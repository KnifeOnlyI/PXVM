#ifndef PXVM_MEMORYNOTEXISTSVARIABLE_HPP
#define PXVM_MEMORYNOTEXISTSVARIABLE_HPP

#include "BaseException.hpp"

namespace pxvm
{
class UndeclaredVariableException : public BaseException
{
public:
    EMPTY_CONSTRUCTOR(UndeclaredVariableException)

    EMPTY_FORMAT_CONSTRUCTOR(UndeclaredVariableException)

    BASIC_CONSTRUCTOR(UndeclaredVariableException)

    FORMAT_CONSTRUCTOR(UndeclaredVariableException)
};
}
#endif //PXVM_MEMORYNOTEXISTSVARIABLE_HPP
