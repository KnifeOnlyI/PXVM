#include <iostream>
#include <exception/NotExistsRegisterException.hpp>
#include <exception/InvalidOperandException.hpp>

#include "parser/FileParserService.hpp"
#include "vm/VM.hpp"

namespace pxvm
{
//region Static methods

bool VM::isConstData(const std::string &value)
{
    bool isNumber {true};
    int nbPoint {0};
    int index {0};

    for (char c : value)
    {
        if (c == '-' && index == 0)
        {
            continue;
        }

        if (c == '.')
        {
            nbPoint++;
        }
        else if (!::isdigit(c))
        {
            isNumber = false;
            break;
        }

        if (nbPoint > 1)
        {
            isNumber = false;
            break;
        }

        index++;
    }

    return value.empty() ||
           isNumber ||
           (value[0] == '"' && value[value.size() - 1] == '"') ||
           (value[0] == '\'' && value[value.size() - 1] == '\'') ||
           (value == "true") ||
           (value == "false");
}

uint8_t VM::getRegisterNumber(const std::string &registerName)
{
    return std::stoi(registerName.substr(2, registerName.size() - 1));
}

bool VM::isStack(const std::string &value)
{
    return value == "rs";
}

bool VM::isRegister(const std::string &value)
{
    return (value.size() >= 2 && value.size() <= 5) &&
           (value.substr(0, 2) == "rp" || value.substr(0, 2) == "rr");
}

bool VM::isMemoryIdentifier(const std::string &value)
{
    return !isConstData(value) && !isRegister(value) && !isStack(value);
}

std::string VM::getRegisterName(const std::string &value)
{
    return value.substr(0, 2);
}

pxvm::Register &VM::getRegister(const std::string &completeRegisterName)
{
    const std::string registerDestName {getRegisterName(completeRegisterName)};

    if (registerDestName == "rr")
    {
        return m_data.rr;
    }
    else if (registerDestName == "rp")
    {
        return m_data.rp;
    }
    else
    {
        throw pxvm::NotExistsRegisterException(boost::format("The register '%s' doesn'\' exists.") % registerDestName);
    }
}

bool VM::isConditionalInstruction(const std::string &instructionName)
{
    return (
        instructionName == "CMP" || // Compare strict equality and put results on stack
        instructionName == "CGE" || // Compare greater or equals and put results on stack
        instructionName == "CG" ||  // Compare greater and put results on stack
        instructionName == "CLE" || // Compare less or equals and put results on stack
        instructionName == "CL" ||  // Compare less and put results on stack
        instructionName == "JT" ||  // Jump on specified section if the top of stack is a boolean TRUE value
        instructionName == "JF" ||  // Jump on specified section if the top of stack is a boolean FALSE value
        instructionName == "JTF"    // Jump on section or another section depends of top stack boolean value
    );
}

// endregion

void pxvm::VM::execute(const std::string &filepath)
{
    pxvm::SectionList sectionList {pxvm::FileParserService::getSectionListFromFile(filepath)};

    executeSection(sectionList, "__main__");
}

void VM::executeSection(SectionList &sectionList, const std::string &name)
{
    pxvm::Section *section {sectionList.get(name)};
    pxvm::Instruction *instruction {nullptr};

    size_t nbInstruction {section->getNbInstruction()};

    for (int i = 0; i < nbInstruction; i++)
    {
        instruction = section->get(i);

        if (isConditionalInstruction(instruction->getName()))
        {
            manageConditionalInstruction(sectionList, *instruction);
        }
        else if (instruction->getParam1().empty() && instruction->getParam2().empty())
        {
            manageBasicOperation(instruction->getName());
        }
        else if (instruction->getName() == "JMP")
        {
            executeSection(sectionList, instruction->getParam1());
        }
        else if (instruction->getName() == "MEM")
        {
            manageOperationMEM(name, *instruction);
        }
        else if (instruction->getName() == "MOV")
        {
            manageOperationMOV(name, *instruction);
        }
    }

    // Clear all m_data at the end of section
    this->m_data.mem.free(name);
}

void VM::manageOperationMEM(const std::string &sectionName, Instruction &instruction)
{
    if (isConstData(instruction.getParam2()))
    {
        m_data.mem.set(sectionName, instruction.getParam1(), pxvm::Data {instruction.getParam2()});
    }
    else if (isMemoryIdentifier(instruction.getParam2()))
    {
        m_data.mem.set(sectionName, instruction.getParam1(), m_data.mem.get(sectionName, instruction.getParam2()));
    }
    else if (isRegister(instruction.getParam2()))
    {
        m_data.mem.set(
            sectionName, instruction.getParam1(),
            getRegister(instruction.getParam2()).get(getRegisterNumber(instruction.getParam2())));
    }
    else if (isStack(instruction.getParam2()))
    {
        m_data.mem.set(sectionName, instruction.getParam1(), m_data.rs.pop());
    }
}

void VM::manageOperationMOV(const std::string &sectionName, pxvm::Instruction &instruction)
{
    if (isStack(instruction.getParam1())) // Manage MOV for stack
    {
        if (isConstData(instruction.getParam2()))
        {
            m_data.rs.push(pxvm::Data {instruction.getParam2()});
        }
        else if (isMemoryIdentifier(instruction.getParam2()))
        {
            m_data.rs.push(m_data.mem.get(sectionName, instruction.getParam2()));
        }
        else if (isRegister(instruction.getParam2()))
        {
            m_data.rs.push(getRegister(instruction.getParam2()).get(getRegisterNumber(instruction.getParam2())));
        }
        else if (isStack(instruction.getParam2()))
        {
            m_data.rs.push(m_data.rs.pop());
        }
    }
    else // Manage MOV for register
    {
        const uint8_t registerNumber {getRegisterNumber(instruction.getParam1())};

        // The register to use like destination
        pxvm::Register &r = getRegister(instruction.getParam1());

        if (isConstData(instruction.getParam2()))
        {
            r.set(registerNumber, pxvm::Data {instruction.getParam2()});
        }
        else if (isMemoryIdentifier(instruction.getParam2()))
        {
            r.set(registerNumber, m_data.mem.get(sectionName, instruction.getParam2()));
        }
        else if (isRegister(instruction.getParam2()))
        {
            r.set(registerNumber, getRegister(instruction.getParam2()).get(getRegisterNumber(instruction.getParam2())));
        }
        else if (isStack(instruction.getParam2()))
        {
            r.set(registerNumber, m_data.rs.pop());
        }
    }
}

void VM::manageBasicOperation(const std::string &name)
{
    if (name == "SWP")
    {
        m_data.rs.swap();
    }
    else if (name == "ADD")
    {
        m_data.rs.add();
    }
    else if (name == "PRINT")
    {
        std::cout << *m_data.rs.pop().getValue();
    }
}

void VM::manageConditionalInstruction(pxvm::SectionList &sectionList, pxvm::Instruction &instruction)
{
    pxvm::Data data1 {m_data.rs.pop()};

    if ((instruction.getName() == "JT" && data1.isTrue()) ||
        ((instruction.getName() == "JF" && !data1.isTrue())))
    {
        executeSection(sectionList, instruction.getParam1());
    }
    else if (instruction.getName() == "JTF")
    {
        if (data1.isTrue())
        {
            executeSection(sectionList, instruction.getParam1());
        }
        else
        {
            executeSection(sectionList, instruction.getParam2());
        }
    }
    else
    {
        pxvm::Data data2 {m_data.rs.pop()};

        // Compare strict equality (for string and numbers)
        if (instruction.getName() == "CMP")
        {
            m_data.rs.push(pxvm::Data {data1.getValue() == data2.getValue()});
        }
        else if (!data1.isNumber() || !data2.isNumber()) // If one of the 2 values is not a number
        {
            throw pxvm::InvalidOperandException(boost::format("%s operand need 2 numbers") % instruction.getName());
        }
        else if (instruction.getName() == "CGE") // Operation "greater or equals"
        {
            m_data.rs.push(pxvm::Data {data2.toDouble() >= data1.toDouble()});
        }
        else if (instruction.getName() == "CG") // Operation "greater"
        {
            m_data.rs.push(pxvm::Data {data2.toDouble() > data1.toDouble()});
        }
        else if (instruction.getName() == "CLE") // Operation "less or equals"
        {
            m_data.rs.push(pxvm::Data {data2.toDouble() <= data1.toDouble()});
        }
        else if (instruction.getName() == "CL") // Operation "less"
        {
            m_data.rs.push(pxvm::Data {data2.toDouble() < data1.toDouble()});
        }
    }
}
}