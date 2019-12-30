#ifndef PXVM_NOTEXISTSREGISTEREXCEPTION_HPP
#define PXVM_NOTEXISTSREGISTEREXCEPTION_HPP

#include "BaseException.hpp"

namespace pxvm
{
class NotExistsRegisterException : public BaseException
{
public:
    EMPTY_CONSTRUCTOR(NotExistsRegisterException);

    EMPTY_FORMAT_CONSTRUCTOR(NotExistsRegisterException)

    BASIC_CONSTRUCTOR(NotExistsRegisterException)

    FORMAT_CONSTRUCTOR(NotExistsRegisterException)
};
}

#endif //PXVM_NOTEXISTSREGISTEREXCEPTION_HPP
