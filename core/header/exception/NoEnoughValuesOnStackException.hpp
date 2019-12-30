#ifndef PXVM_NOENOUGHVALUESONSTACKEXCEPTION_HPP
#define PXVM_NOENOUGHVALUESONSTACKEXCEPTION_HPP

#include "BaseException.hpp"

namespace pxvm
{
class NoEnoughValuesOnStackException : public BaseException
{
public:
    EMPTY_CONSTRUCTOR(NoEnoughValuesOnStackException)

    EMPTY_FORMAT_CONSTRUCTOR(NoEnoughValuesOnStackException)

    BASIC_CONSTRUCTOR(NoEnoughValuesOnStackException)

    FORMAT_CONSTRUCTOR(NoEnoughValuesOnStackException)
};
}

#endif //PXVM_NOENOUGHVALUESONSTACKEXCEPTION_HPP
