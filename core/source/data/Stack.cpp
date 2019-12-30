#include <boost/format.hpp>
#include <exception/NoEnoughValuesOnStackException.hpp>

#include "exception/InvalidOperandException.hpp"
#include "data/Stack.hpp"

namespace pxvm
{
void pxvm::Stack::push(const Data &data)
{
    m_stack.push(data);
}

pxvm::Data Stack::pop()
{
    pxvm::Data data {m_stack.top()};

    m_stack.pop();

    return data;
}

void Stack::add()
{
    pxvm::Data a {pop()};
    pxvm::Data b {pop()};

    a.assertNotNull();
    b.assertNotNull();

    if ((a.isNumber() && b.isCharOrString()) || (a.isCharOrString() && b.isNumber()))
    {
        throw pxvm::InvalidOperandException("Invalid operand (between number and string)");
    }
    else if (a.isCharOrString() && b.isCharOrString()) // If a and b are string, concatenation
    {
        m_stack.push({DataType::STRING, (boost::format("%s%s") % *a.getValue() % *b.getValue()).str()});
    }
    else if (a.isNumber() && b.isNumber())
    {
        addForNumber(a, b);
    }
}

void Stack::addForNumber(const pxvm::Data &a, const pxvm::Data &b)
{
    if (a.isInt() && b.isInt())
    {
        addForIntNumber(a, b);
    }
    else if (a.isRealNumber() && b.isRealNumber())
    {
        m_stack.push({DataType::DOUBLE, std::to_string(a.toDouble() + b.toDouble())});
    }
    else if (a.isRealNumber() && b.isInt())
    {
        m_stack.push({DataType::DOUBLE, std::to_string(a.toDouble() + b.toInt64())});
    }
    else if (a.isInt() && b.isRealNumber())
    {
        m_stack.push({DataType::DOUBLE, std::to_string(a.toInt64() + b.toDouble())});
    }
}

void Stack::addForIntNumber(const pxvm::Data &a, const pxvm::Data &b)
{
    if (a.isSignedInt() && b.isSignedInt())
    {
        m_stack.push({DataType::INT_64, std::to_string(a.toInt64() + b.toInt64())});
    }
    else if (a.isUnsignedInt() && b.isUnsignedInt())
    {
        m_stack.push({DataType::UINT_64, std::to_string(a.toUint64() + b.toUint64())});
    }
    else if (a.isSignedInt() && b.isUnsignedInt())
    {
        m_stack.push({DataType::UINT_64, std::to_string(a.toInt64() + b.toUint64())});
    }
    else if (a.isUnsignedInt() && b.isSignedInt())
    {
        m_stack.push({DataType::UINT_64, std::to_string(a.toUint64() + b.toInt64())});
    }
}

void Stack::swap()
{
    if (m_stack.size() >= 2)
    {
        pxvm::Data first {pop()};
        pxvm::Data second {pop()};

        push(first);    // Become the second
        push(second);   // Become the first
    }
}
}