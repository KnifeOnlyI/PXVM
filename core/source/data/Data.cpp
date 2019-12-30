#include <utility>

#include "exception/InvalidCharValueException.hpp"
#include "exception/NullPointerException.hpp"
#include "data/Data.hpp"

namespace pxvm
{
Data::Data(DataType type)
    : m_type {type}, m_value {""}, m_isNull {true}
{
}

Data::Data(const std::string &value)
    : m_value {value}, m_isNull {false}
{
    pxvm::DataType type {pxvm::DataType::STRING};

    if (value[0] == '"' && value[value.size() - 1] == '"')
    {
        type = pxvm::DataType::STRING;
    }
    else if (value[0] == '\'' && value[value.size() - 1] == '\'')
    {
        if (value.size() != 3)
        {
            throw pxvm::InvalidCharValueException("Char CANNOT contains greater than one character.");
        }
        else
        {
            type = pxvm::DataType::CHAR_32;
        }
    }
    else if (value.find(' ') == -1)
    {
        if (value.find('.') != -1)
        {
            if (value[value.size() - 1] == 'd')
            {
                type = pxvm::DataType::DOUBLE;
            }
            else
            {
                type = pxvm::DataType::FLOAT;
            }
        }
        else if (value[0] == '-')
        {
            type = pxvm::DataType::INT_64;
        }
        else
        {
            type = pxvm::DataType::UINT_64;
        }
    }

    m_type = type;
}

Data::Data(DataType type, std::string value)
    : m_type {type}, m_value {std::move(value)}, m_isNull {false}
{
}

const DataType &Data::getType() const
{
    return m_type;
}

const std::string *Data::getValue() const
{
    return (!m_isNull) ? &m_value : nullptr;
}

bool Data::isNull() const
{
    return m_isNull;
}

void Data::setValue(std::string value)
{
    m_isNull = false;
    m_value = std::move(value);
}

void Data::isNull(bool value)
{
    m_isNull = value;
    m_value.clear();
}

void Data::assertNotNull() const
{
    if (m_isNull)
    {
        throw pxvm::NullPointerException("The value cannot be NULL", __FILE__, __LINE__);
    }
}

bool Data::isSignedInt() const
{
    return (
        m_type == DataType::INT_64 ||
        m_type == DataType::INT_32 ||
        m_type == DataType::INT_16 ||
        m_type == DataType::INT_8
    );
}

bool Data::isUnsignedInt() const
{
    return (
        m_type == DataType::UINT_8 ||
        m_type == DataType::UINT_16 ||
        m_type == DataType::UINT_32 ||
        m_type == DataType::UINT_64
    );
}

bool Data::isInt() const
{
    return (isSignedInt() || isUnsignedInt());
}

bool Data::isRealNumber() const
{
    return (m_type == DataType::FLOAT || m_type == DataType::DOUBLE);
}

bool Data::isNumber() const
{
    return (isInt() || isRealNumber());
}

bool Data::isCharOrString() const
{
    return (
        m_type == DataType::CHAR_8 ||
        m_type == DataType::CHAR_16 ||
        m_type == DataType::CHAR_32 ||
        m_type == DataType::STRING
    );
}

uint8_t Data::toUint8() const
{
    assertNotNull();

    return (uint8_t) std::stoi(m_value);
}

uint16_t Data::toUint16() const
{
    assertNotNull();

    return (uint16_t) std::stoi(m_value);
}

uint32_t Data::toUint32() const
{
    assertNotNull();

    return (uint32_t) std::stoi(m_value);
}

uint64_t Data::toUint64() const
{
    assertNotNull();

    return (uint64_t) std::stoi(m_value);
}

int8_t Data::toInt8() const
{
    assertNotNull();

    return (int8_t) std::stoi(m_value);
}

int16_t Data::toInt16() const
{
    assertNotNull();

    return (int16_t) std::stoi(m_value);
}

int32_t Data::toInt32() const
{
    assertNotNull();

    return (int32_t) std::stoi(m_value);
}

int64_t Data::toInt64() const
{
    assertNotNull();

    return (int64_t) std::stoi(m_value);
}

char Data::toChar8() const
{
    assertNotNull();

    return (char) std::stoi(m_value);
}

char16_t Data::toChar16() const
{
    assertNotNull();

    return (char16_t) std::stoi(m_value);
}

char32_t Data::toChar32() const
{
    assertNotNull();

    return (char32_t) std::stoi(m_value);
}

float Data::toFloat() const
{
    assertNotNull();

    return std::stof(m_value);
}

double Data::toDouble() const
{
    assertNotNull();

    return std::stod(m_value);
}
}