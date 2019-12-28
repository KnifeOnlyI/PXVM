#ifndef PXVM_SECTIONLIST_HPP
#define PXVM_SECTIONLIST_HPP

#include <map>
#include <memory>

#include "Section.hpp"

namespace pxvm
{
/**
 * Represent a section list
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class SectionList
{
public:
    virtual ~SectionList();

    /**
     * Add a section to the list
     *
     * \param section The section to add
     */
    void add(pxvm::Section *section);

    /**
     * Get section by the specified name
     *
     * \param name The name of the section to get
     *
     * \return The section
     */
    const pxvm::Section &get(const std::string &name);

    /**
     * Get the number of section
     *
     * \return The number of section
     */
    [[nodiscard]] size_t getNbSection() const;

private:
    /** \var The wrapped section list */
    std::map<std::string, pxvm::Section *> m_list;
};
}

#endif //PXVM_SECTIONLIST_HPP
