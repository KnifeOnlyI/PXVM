#ifndef PXVM_INVALIDCHARVALUEEXCEPTION_HPP
#define PXVM_INVALIDCHARVALUEEXCEPTION_HPP

#include "BaseException.hpp"

namespace pxvm
{
class InvalidCharValueException : public BaseException
{
public:
    EMPTY_CONSTRUCTOR(InvalidCharValueException);

    EMPTY_FORMAT_CONSTRUCTOR(InvalidCharValueException)

    BASIC_CONSTRUCTOR(InvalidCharValueException)

    FORMAT_CONSTRUCTOR(InvalidCharValueException)
};
}

#endif //PXVM_INVALIDCHARVALUEEXCEPTION_HPP
