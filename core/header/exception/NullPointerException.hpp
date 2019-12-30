#ifndef PXVM_NULLPOINTEREXCEPTION_HPP
#define PXVM_NULLPOINTEREXCEPTION_HPP

#include "BaseException.hpp"

namespace pxvm
{
/**
 * Exception to represent the NullPointerException
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class NullPointerException : public BaseException
{
public:
    EMPTY_CONSTRUCTOR(NullPointerException)

    EMPTY_FORMAT_CONSTRUCTOR(NullPointerException)

    BASIC_CONSTRUCTOR(NullPointerException)

    FORMAT_CONSTRUCTOR(NullPointerException)
};
}

#endif //PXVM_NULLPOINTEREXCEPTION_HPP
