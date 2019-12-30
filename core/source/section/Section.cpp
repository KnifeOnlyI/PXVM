#include "section/Section.hpp"

#include <utility>

namespace pxvm
{
pxvm::Section::Section(std::string name)
    : m_name {std::move(name)}
{
}

void Section::add(const std::vector<std::string> &props)
{
    m_instructionList.push_back(pxvm::Instruction::create(props));
}

const std::string &Section::getName() const
{
    return m_name;
}

pxvm::Instruction *Section::get(int i)
{
    return m_instructionList[i];
}

size_t Section::getNbInstruction() const
{
    return m_instructionList.size();
}

Section::~Section()
{
    for (pxvm::Instruction *instruction : m_instructionList)
    {
        delete instruction;
    }
}
}