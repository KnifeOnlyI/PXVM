#include <boost/format.hpp>

#include "exception/MemoryNotExistVariable.hpp"
#include "data/MemoryContext.hpp"

namespace pxvm
{
pxvm::Data pxvm::MemoryContext::get(const std::string &key)
{
    if (m_data.count(key) == 0)
    {
        throw pxvm::UndeclaredVariableException(
            boost::format("No variable '%s' available in the VRAM or current context") % key
        );
    }

    return {m_data.at(key)};
}

void MemoryContext::set(const std::string &key, const Data &data)
{
    m_data.emplace(key, data);
}

void MemoryContext::free(const std::string &key)
{
    m_data.erase(key);
}
}