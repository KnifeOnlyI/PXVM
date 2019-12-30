#ifndef PXVM_FILEPARSERSERVICE_HPP
#define PXVM_FILEPARSERSERVICE_HPP

#include <string>
#include <vector>

#include "instruction/Instruction.hpp"
#include "section/SectionList.hpp"
#include "section/Section.hpp"

namespace pxvm
{
/**
 * Represent a service to analyze files
 *
 * \author Dany Pignoux (dany.pignoux@outlook.fr)
 */
class FileParserService
{
public:
    /**
     * Get the section list from specified file
     *
     * \param filepath The filepath to analyze
     *
     * \return The section list in the specified file
     */
    static pxvm::SectionList getSectionListFromFile(const std::string &filepath);

    /**
     * Trim all whitespaces on begin, end of the specified string and replace all multiples whitespaces by one and
     * return a copy of transformed string. Remove the comments
     *
     * \param str The string to analyze
     *
     * \return The transformed string
     */
    static std::string trim(const std::string &str);

    /**
     * Get the line split by spaces and comma
     *
     * e.g : Vector<String>({"MOV", "vara", "Hello World !"})
     *
     * \param line The line to analyze
     *
     * \return The operation mnemonic, empty string if the line is not an operation (e.g : begin/end section
     */
    static std::vector<std::string> getSplitLine(const std::string &line);
};
}

#endif //PXVM_FILEPARSERSERVICE_HPP
