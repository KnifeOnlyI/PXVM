#include "section/SectionList.hpp"

namespace pxvm
{

pxvm::Section *SectionList::get(const std::string &name)
{
    return m_list.at(name);
}

size_t SectionList::getNbSection() const
{
    return m_list.size();
}

void SectionList::add(pxvm::Section *section)
{
    m_list.insert({section->getName(), section});
}

SectionList::~SectionList()
{
    for (auto &it : m_list)
    {
        delete it.second;
    }
}
}