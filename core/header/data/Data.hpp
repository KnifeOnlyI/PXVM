#ifndef PXVM_DATA_HPP
#define PXVM_DATA_HPP

#include <string>

namespace pxvm
{
/**
 * Represent all m_data type of m_data usable in PXVM
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
enum DataType
{
    UINT_8,     /**< \ No signed 8 bit integer */
    UINT_16,    /**< No signed 16 bit integer */
    UINT_32,    /**< No signed 32 bit integer */
    UINT_64,    /**< No signed 64 bit integer */
    INT_8,      /**< Signed 8 bit integer */
    INT_16,     /**< Signed 16 bit integer */
    INT_32,     /**< Signed 32 bit integer */
    INT_64,     /**< Signed 64 bit integer */
    CHAR_8,     /**< Char on 8 bit */
    CHAR_16,    /**< Char on 16 bit */
    CHAR_32,    /**< Char on 32 bit */
    FLOAT,      /**< Floating number on 32 bit */
    DOUBLE,     /**< Floating number on 64 bit */
    STRING,     /**< String */
};

/**
 * Represent a data
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class Data
{
public:
    /**
     * Create null data
     *
     * \param type The data type
     */
    explicit Data(DataType type);

    /**
     * Create data with specified value and automatically deduce of the data type
     *
     * \param value The value
     */
    explicit Data(const std::string &value);

    /**
     * Create not null data
     *
     * \param type The m_data type
     * \param value The value
     */
    Data(DataType type, std::string value);

    /**
     * Get the type
     *
     * \return The data type
     */
    [[nodiscard]] const DataType &getType() const;

    /**
     * Get string value
     *
     * \return The value
     */
    [[nodiscard]] const std::string *getValue() const;

    /**
     * Get isNull
     *
     * \return TRUE if is null, FALSE otherwise
     */
    [[nodiscard]] bool isNull() const;

    /**
     * Set string value
     *
     * \param value The value
     */
    void setValue(std::string value);

    /**
     * Set null value
     *
     * \param value The value
     */
    void isNull(bool value);

    /**
     * Check if m_data is signed int
     *
     * \return True if is signed int
     */
    [[nodiscard]] bool isSignedInt() const;

    /**
     * Check if m_data is unsigned int
     *
     * \return True if is unsigned int
     */
    [[nodiscard]] bool isUnsignedInt() const;

    /**
     * Check if m_data is int
     *
     * \return TRUE if is int, FALSE otherwise
     */
    [[nodiscard]] bool isInt() const;

    /**
     * Check if m_data is a real number
     *
     * \return TRUE if is a real number, FALSE otherwise
     */
    [[nodiscard]] bool isRealNumber() const;

    /**
     * Check if m_data is a number
     *
     * \return TRUE if is a number, FALSE otherwise
     */
    [[nodiscard]] bool isNumber() const;

    /**
     * Check if m_data is a char or string
     *
     * \return TRUE if is a char or string, FALSE otherwise
     */
    [[nodiscard]] bool isCharOrString() const;

    /**
     * Assert the value is not null
     */
    void assertNotNull() const;

    /**
     * Convert string value to uint8
     *
     * \return uint8 value
     */
    [[nodiscard]] uint8_t toUint8() const;

    /**
     * Convert string value to uint8
     *
     * \return uint32 value
     */
    [[nodiscard]] uint16_t toUint16() const;

    /**
     * Convert string value to uint32
     *
     * \return uint32 value
     */
    [[nodiscard]] uint32_t toUint32() const;

    /**
     * Convert string value to uint64
     *
     * \return uint64 value
     */
    [[nodiscard]] uint64_t toUint64() const;

    /**
     * Convert string value to int8
     *
     * \return int8 value
     */
    [[nodiscard]] int8_t toInt8() const;

    /**
     * Convert string value to int8
     *
     * \return int32 value
     */
    [[nodiscard]] int16_t toInt16() const;

    /**
     * Convert string value to int32
     *
     * \return int32 value
     */
    [[nodiscard]] int32_t toInt32() const;

    /**
     * Convert string value to int64
     *
     * \return int64 value
     */
    [[nodiscard]] int64_t toInt64() const;

    /**
     * Convert string value to char8
     *
     * \return char8 value
     */
    [[nodiscard]] char toChar8() const;

    /**
     * Convert string value to char16
     *
     * \return char16 value
     */
    [[nodiscard]] char16_t toChar16() const;

    /**
     * Convert string value to char32
     *
     * \return char32 value
     */
    [[nodiscard]] char32_t toChar32() const;

    /**
     * Convert string value to float
     *
     * \return float value
     */
    [[nodiscard]] float toFloat() const;

    /**
     * Convert string value to double
     *
     * \return double value
     */
    [[nodiscard]] double toDouble() const;

private:
    /** \var Represent the type */
    DataType m_type;

    /** \var Represent the value */
    std::string m_value;

    /** \var Represent if the value is null or not */
    bool m_isNull {};
};
}

#endif //PXVM_DATA_HPP
