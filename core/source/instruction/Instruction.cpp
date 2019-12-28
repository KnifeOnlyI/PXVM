#include "instruction/Instruction.hpp"

#include <utility>

namespace pxvm
{
Instruction *Instruction::create(const std::vector<std::string> &props)
{
    return [&props]() -> pxvm::Instruction * {
        switch (props.size())
        {
            case 1:
                return new pxvm::Instruction {props[0], "", ""};
            case 2:
                return new pxvm::Instruction {props[0], props[1], ""};
            case 3:
                return new pxvm::Instruction {props[0], props[1], props[2]};
            default:
                return new pxvm::Instruction {"", "", ""};
        }
    }();
}

Instruction::Instruction(std::string name, std::string param1, std::string param2)
    : m_name {std::move(name)}, m_param1 {std::move(param1)}, m_param2 {std::move(param2)}
{
}

const std::string &Instruction::getName() const
{
    return m_name;
}

const std::string &Instruction::getParam1() const
{
    return m_param1;
}

const std::string &Instruction::getParam2() const
{
    return m_param2;
}
}