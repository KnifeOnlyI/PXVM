#ifndef PXVM_DATAARCHITECTURE_HPP
#define PXVM_DATAARCHITECTURE_HPP

#include "Stack.hpp"
#include "Register.hpp"
#include "Memory.hpp"

namespace pxvm
{
/**
 * Represent the VM's m_data architecture (main stack, registers, etc.)
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
struct DataArchitecture
{
    pxvm::Register rp;  /**< Register for parameters */
    pxvm::Register rr;  /**< Register for returns */
    pxvm::Memory mem;   /**< Virtual RAM (Random Access Memory) */
    pxvm::Stack rs;     /**< Main stack */
};
}

#endif //PXVM_DATAARCHITECTURE_HPP
