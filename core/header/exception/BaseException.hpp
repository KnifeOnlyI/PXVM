#ifndef PXVM_BASEEXCEPTION_HPP
#define PXVM_BASEEXCEPTION_HPP

#include <exception>
#include <sstream>
#include <boost/format.hpp>

#define EMPTY_CONSTRUCTOR(X) \
explicit X(const char *msg) \
: BaseException(msg) \
{ \
} \

#define EMPTY_FORMAT_CONSTRUCTOR(X) \
explicit X(const boost::basic_format<char> &msg) \
: BaseException(msg) \
{ \
} \

#define BASIC_CONSTRUCTOR(X) \
X(const char *msg, const char *file, int line) \
: BaseException(msg, file, line) \
{ \
} \

#define FORMAT_CONSTRUCTOR(X) \
X(const boost::basic_format<char> &msg, const char *file, int line) \
: BaseException(msg, file, line) \
{ \
} \

namespace pxvm
{
/**
 * Represent the base exception for OTEngine::CSDL
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class BaseException : public std::exception
{
public:
    /**
     * Constructor
     *
     * \param msg The message
     */
    explicit BaseException(const char *msg)
    {
        this->msg = msg;
    }

    /**
     * Constructor
     *
     * \param msg The formatted message
     */
    explicit BaseException(const boost::basic_format<char> &msg)
    {
        this->msg = msg.str();
    }

    /**
     * Constructor
     *
     * \param msg The message
     * \param file The file (Tip: use macro __FILE__)
     * \param line The line (Tip: use macro __LINE__)
     */
    BaseException(const char *msg, const char *file, int line)
    {
        std::ostringstream oss;
        oss << "[" << file << "." << line << "] : " << msg;

        this->msg = oss.str();
    }

    /**
     * Constructor
     *
     * \param msg The formatted message
     * \param file The file (Tip: use macro __FILE__)
     * \param line The line (Tip: use macro __LINE__)
     */
    BaseException(const boost::basic_format<char> &msg, const char *file, int line)
    {
        std::ostringstream oss;
        oss << "[" << file << "." << line << "] : " << msg.str().c_str();

        this->msg = oss.str();
    }

    /**
     * Destructor
     */
    ~BaseException() noexcept override = default;

    /**
     * Get the message
     *
     * \return The message
     */
    [[nodiscard]] const char *what() const noexcept override
    {
        return this->msg.c_str();
    }

private:
    /**
     * \var The message
     */
    std::string msg;
};
}

#endif //PXVM_BASEEXCEPTION_HPP
