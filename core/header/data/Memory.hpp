#ifndef PXVM_MEMORY_HPP
#define PXVM_MEMORY_HPP

#include <map>

#include "MemoryContext.hpp"

namespace pxvm
{
/**
 * Represent the memory of the VM RAM (Random Access Memory)
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class Memory
{
public:
    /**
     * Get m_data at the specified context and specified key
     *
     * \param context The context
     * \param key The key
     *
     * \return The m_data
     */
    pxvm::Data get(const std::string &context, const std::string &key);

    /**
     * Set m_data at the specified context and specified key
     *
     * \param context The context
     * \param key The key to set
     * \param data The m_data to set
     */
    void set(const std::string &context, const std::string &key, const Data &data);

    /**
     * Free all m_data
     */
    void free();

    /**
     * Free all m_data at the specified context
     *
     * \param key The context of the all m_data to free
     */
    void free(const std::string &context);

    /**
     * Free m_data at the specified context and specified key
     *
     * \param context The context of the m_data to free
     * \param key The key of the m_data to free
     */
    void free(const std::string &context, const std::string &key);

private:
    /** \var The m_data context list */
    std::map<std::string, pxvm::MemoryContext> m_data;
};
}

#endif //PXVM_MEMORY_HPP
