#ifndef PXVM_STACK_HPP
#define PXVM_STACK_HPP

#include <stack>

#include "Data.hpp"

namespace pxvm
{
/**
 * Represent a stack
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class Stack
{
public:
    /**
     * Push m_data on the top of the stack
     *
     * \param data The m_data to push
     */
    void push(const Data &data);

    /**
     * Get the top m_data and remove it from the stack
     *
     * \return The top m_data
     */
    pxvm::Data pop();

    /**
     * Swap the 2 top elements on the stack
     */
    void swap();

    /**
     * Perform ADD operation with the 2 top value on the stack and push the result on the top
     */
    void add();

private:
    /**
     * Manage ADD operation for numbers
     */
    void addForNumber(const pxvm::Data &a, const pxvm::Data &b);

    /**
     * Manage ADD operation for integer numbers
     */
    void addForIntNumber(const pxvm::Data &a, const pxvm::Data &b);

    /** \var The wrapped stack */
    std::stack<pxvm::Data> m_stack {};
};
}

#endif //PXVM_STACK_HPP
