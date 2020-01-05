#ifndef PXVM_VM_HPP
#define PXVM_VM_HPP

#include "exception/InvalidCharValueException.hpp"
#include "data/Memory.hpp"
#include "data/DataArchitecture.hpp"
#include "section/SectionList.hpp"
#include "instruction/Instruction.hpp"

namespace pxvm
{
/**
 * Represent the VM
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class VM
{
public:
    /**
     * Execute the code on the specified file
     *
     * \param filepath The filepath of file to execute
     */
    void execute(const std::string &filepath);

private:
    /**
     * Check if the specified value is a const data or not
     *
     * \param value The value to check
     *
     * \return TRUE if is a const data (like a string or number), FALSE otherwise (can be a memory identifier, main stack or register)
     */
    static bool isConstData(const std::string &value);

    /**
     * Check if the specified value is the main stack
     *
     * \param value The value to check
     *
     * \return TRUE if is the main stack (rs), FALSE otherwise (can be memory identifier, register or const data)
     */
    static bool isStack(const std::string &value);

    /**
     * Check if the specified value is a register
     *
     * \param value The value to check
     *
     * \return TRUE if is a register (e.g : rr0, rp0, rs, etc.), FALSE otherwise (can be memory identifier, main stack or const data)
     */
    static bool isRegister(const std::string &value);

    /**
     * Check if the specified value is a memory identifier
     *
     * \param value The value to check
     *
     * \return TRUE if is a memory identifier (e.g : vara, varb), FALSE otherwise (can be register, main stack, or const data)
     */
    static bool isMemoryIdentifier(const std::string &value);

    /**
     * Get register name of the specified value
     *
     * \param value The value to analyze
     *
     * \return The register name
     */
    static std::string getRegisterName(const std::string &value);

    /**
     * Get the register number of specified register name
     *
     * \param registerName The register name to analyze (e.g : rr0)
     *
     * \return The register number
     */
    static uint8_t getRegisterNumber(const std::string &registerName);

    /**
     * Check if the specfied instruction name is a conditional instruction or not
     *
     * \return TRUE if the specfied instruction name is a conditional instruction FALSE otherwise
     */
    static bool isConditionalInstruction(const std::string &instructionName);

    /**
     * Execute the specified name
     *
     * \param sectionList The section list
     * \param name The name name
     */
    void executeSection(pxvm::SectionList &sectionList, const std::string &name);

    /**
     * Manage the "MEM" operation
     *
     * \param instruction The instruction to analyze
     */
    void manageOperationMEM(const std::string &sectionName, pxvm::Instruction &instruction);

    /**
     * Manage the "MOV" operation
     *
     * \param sectionName The section name
     * \param instruction The instruction to analyze
     */
    void manageOperationMOV(const std::string &sectionName, pxvm::Instruction &instruction);

    /**
     * Manage basic operation (e.g : ADD, SWP, etc)
     *
     * \param name The basic operation name
     */
    void manageBasicOperation(const std::string &name);

    /**
     * Manage conditional instruction
     *
     * \param sectionList The section list
     * \param instruction Instruction to analyze
     */
    void manageConditionalInstruction(pxvm::SectionList &sectionList, pxvm::Instruction &instruction);

    /**
     * Get register by name
     *
     * \param completeRegisterName The complete register name
     *
     * \return The register
     */
    pxvm::Register &getRegister(const std::string &completeRegisterName);

    /** \var The data architecture (RAM, main stack, registers) */
    pxvm::DataArchitecture m_data;
};
}

#endif //PXVM_VM_HPP
