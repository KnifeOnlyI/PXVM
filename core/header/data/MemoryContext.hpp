#ifndef PXVM_MEMORYCONTEXT_HPP
#define PXVM_MEMORYCONTEXT_HPP

#include <map>

#include "Data.hpp"

namespace pxvm
{
/**
 * Represent an isolated section of the VM RAM (Random Access Memory)
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class MemoryContext
{
public:
    /**
     * Get m_data at the specified key
     *
     * \param key The key to get
     *
     * \return The m_data
     */
    pxvm::Data get(const std::string &key);

    /**
     * Set m_data at the specified key
     *
     * \param key The key to set
     * \param data The m_data to set
     */
    void set(const std::string &key, const Data &data);

    /**
     * Free m_data at the specified key
     *
     * \param key The key of the m_data to free
     */
    void free(const std::string &key);

private:
    /** \var The m_data list */
    std::map<std::string, pxvm::Data> m_data;
};
}

#endif //PXVM_MEMORYCONTEXT_HPP
