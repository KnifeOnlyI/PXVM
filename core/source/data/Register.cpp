#include "exception/RegisterIndexOutOfBoundException.hpp"
#include "data/Register.hpp"

namespace pxvm
{
pxvm::Data Register::get(uint8_t key)
{
    if (m_data.count(key) == 0)
    {
        throw pxvm::RegisterIndexOutOfBoundException(
            boost::format("The key %s not exists in the register") % std::to_string(key));
    }

    pxvm::Data data {m_data.at(key)};

    m_data.erase(key);

    return data;
}

void Register::set(uint8_t key, const Data &data)
{
    m_data.emplace(key, data);
}
}
