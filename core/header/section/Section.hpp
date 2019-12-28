#ifndef PXVM_SECTION_HPP
#define PXVM_SECTION_HPP

#include <vector>
#include <memory>

#include "instruction/Instruction.hpp"

namespace pxvm
{
/**
 * Represent a section with his instruction list
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class Section
{
public:
    /**
     * Create a new section with his name
     *
     * \param name The name
     */
    explicit Section(std::string name);

    virtual ~Section();

    /**
     * Add instruction to section
     *
     * \param instruction The instruction to add
     */
    void add(const std::vector<std::string> &props);

    /**
     * Get the name
     *
     * \return The name
     */
    [[nodiscard]] const std::string &getName() const;

    /**
     * Get the instruction list
     *
     * \return The instruction list
     */
    [[nodiscard]] const pxvm::Instruction &get(int i) const;

    /**
     * Get the number of instruction
     *
     * \return The number of instruction
     */
    [[nodiscard]] size_t getNbInstruction() const;

private:
    /** \var The name */
    const std::string m_name;

    /** \var The instruction list */
    std::vector<pxvm::Instruction *> m_instructionList;
};
}

#endif //PXVM_SECTION_HPP
