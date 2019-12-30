#ifndef PXVM_INVALIDOPERANDEXCEPTION_HPP
#define PXVM_INVALIDOPERANDEXCEPTION_HPP

#include "BaseException.hpp"

namespace pxvm
{
class InvalidOperandException : public BaseException
{
public:
    EMPTY_CONSTRUCTOR(InvalidOperandException);

    EMPTY_FORMAT_CONSTRUCTOR(InvalidOperandException)

    BASIC_CONSTRUCTOR(InvalidOperandException)

    FORMAT_CONSTRUCTOR(InvalidOperandException)
};
}

#endif //PXVM_INVALIDOPERANDEXCEPTION_HPP
