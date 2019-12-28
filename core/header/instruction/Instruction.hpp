#ifndef PXVM_INSTRUCTION_HPP
#define PXVM_INSTRUCTION_HPP

#include <string>
#include <vector>

namespace pxvm
{
/**
 * Represent the base class for all instruction
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class Instruction
{
public:
    static Instruction *create(const std::vector<std::string> &props);

    /**
     * Create instruction with name and 2 parameters
     *
     * e.g :
     *  MEM vara, 5
     *  MOV rpia, vara
     *
     * \param name The name
     * \param param1 The first parameter
     * \param param2 The second parameter
     */
    Instruction(std::string name, std::string param1, std::string param2);

    /**
     * Get the name
     *
     * \return The name
     */
    [[nodiscard]] const std::string &getName() const;

    /**
     * Get the first parameter
     *
     * \return The first parameter
     */
    [[nodiscard]] const std::string &getParam1() const;

    /**
     * Get the second parameter
     *
     * \return The second parameter
     */
    [[nodiscard]] const std::string &getParam2() const;

private:
    /** \var The name */
    const std::string m_name;

    /** \var The first parameter */
    const std::string m_param1;

    /** \var The param 2 */
    const std::string m_param2;
};
}

#endif //PXVM_INSTRUCTION_HPP
