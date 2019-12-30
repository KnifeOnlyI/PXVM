#include "exception/MemoryNotExistVariable.hpp"
#include "data/Memory.hpp"

namespace pxvm
{

pxvm::Data pxvm::Memory::get(const std::string &context, const std::string &key)
{
    if (m_data.count(context) == 0)
    {
        throw pxvm::UndeclaredVariableException(boost::format("No context '%s' available in the VRAM") % context);
    }

    return {m_data.at(context).get(key)};
}

void Memory::set(const std::string &context, const std::string &key, const Data &data)
{
    // If the context not exists, create it
    if (m_data.count(context) == 0)
    {
        m_data.emplace(context, pxvm::MemoryContext {});
    }

    m_data.at(context).set(key, data);
}

void Memory::free()
{
    m_data.clear();
}

void Memory::free(const std::string &context)
{
    m_data.erase(context);
}

void Memory::free(const std::string &context, const std::string &key)
{
    if (m_data.count(context) != 0)
    {
        m_data.at(context).free(key);
    }
}
}