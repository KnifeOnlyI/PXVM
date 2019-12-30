#ifndef PXVM_REGISTERINDEXOUTOFBOUNDEXCEPTION_HPP
#define PXVM_REGISTERINDEXOUTOFBOUNDEXCEPTION_HPP

#include "BaseException.hpp"

namespace pxvm
{
class RegisterIndexOutOfBoundException : public BaseException
{
public:
    EMPTY_CONSTRUCTOR(RegisterIndexOutOfBoundException)

    EMPTY_FORMAT_CONSTRUCTOR(RegisterIndexOutOfBoundException)

    BASIC_CONSTRUCTOR(RegisterIndexOutOfBoundException)

    FORMAT_CONSTRUCTOR(RegisterIndexOutOfBoundException)
};
}
#endif //PXVM_REGISTERINDEXOUTOFBOUNDEXCEPTION_HPP
