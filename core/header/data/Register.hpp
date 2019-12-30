#ifndef PXVM_REGISTER_HPP
#define PXVM_REGISTER_HPP

#include <map>

#include "Data.hpp"

namespace pxvm
{
/**
 * Represent a register
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class Register
{
public:
    /**
     * Get m_data at the specified key
     *
     * \param key The key to get
     *
     * \return The m_data
     */
    pxvm::Data get(uint8_t key);

    /**
     * Set m_data at the specified key
     *
     * \param key The key to set
     * \param data The m_data to set
     */
    void set(uint8_t key, const Data &data);

private:
    /** \var The m_data list */
    std::map<uint8_t, pxvm::Data> m_data;
};
}

#endif //PXVM_REGISTER_HPP
