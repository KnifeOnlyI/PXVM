#include <boost/algorithm/string.hpp>
#include <fstream>

#include "parser/FileParserService.hpp"

namespace pxvm
{
std::string FileParserService::trim(const std::string &str)
{
    const std::string &trim {boost::trim_copy(str)};
    std::string newString;

    bool inString {false};
    bool previousCharIsAntiSlash {false};
    bool previousCharIsSpace {false};

    for (char c : trim)
    {
        // If this is the begin of comment, break the loop here
        if (!inString && c == ';')
        {
            break;
        }
        else if (c == '"') // If char is a string delimiter
        {
            // If previous char is escape sequence, the char is not really a string delimiter, ignore the next -> "
            if (!previousCharIsAntiSlash)
            {
                inString = !inString; // Begin string if not already in string, end string otherwise
            }

            previousCharIsAntiSlash = false;
        }
        else if (inString && c == '\\')
        {
            previousCharIsAntiSlash = true;
        }

        // If in string : Add the character
        if (inString)
        {
            newString += c;
        }
        else if (c != ' ') // If not in string and char is not a space, add character
        {
            newString += c;
            previousCharIsSpace = false;
        }
        else if (!previousCharIsSpace) // If not in string and the previous char is not a space, add character
        {
            newString += c;
            previousCharIsSpace = true;
        }
    }

    boost::trim(newString);

    return newString;
}

std::vector<std::string> FileParserService::getSplitLine(const std::string &line)
{
    std::vector<std::string> elementList;
    std::string trimLine {trim(line)};
    std::string currentElement;

    bool inString {false};
    bool previousCharIsAntiSlash {false};

    for (char c : trimLine)
    {
        if (!inString)
        {
            if (currentElement == ",")
            {
                currentElement = "";
            }

            if ((c == ' ' || c == ',') && !currentElement.empty())
            {
                elementList.push_back(currentElement);
                currentElement = "";
            }
            else if (c == '"')
            {
                inString = true;
                currentElement += c;
            }
            else if (c != ' ')
            {
                currentElement += c;
            }
        }
        else if (c == '\\')
        {
            previousCharIsAntiSlash = true;
            currentElement += c;
        }
        else if (c == '"')
        {
            if (!previousCharIsAntiSlash)
            {
                inString = !inString;
            }

            previousCharIsAntiSlash = false;
            currentElement += c;
        }
        else
        {
            currentElement += c;
        }
    }

    if (!currentElement.empty())
    {
        elementList.push_back(currentElement);
    }

    return elementList;
}

pxvm::SectionList FileParserService::getSectionListFromFile(const std::string &filepath)
{
    pxvm::SectionList list;
    std::vector<pxvm::Section> sectionList;

    std::ifstream file {filepath};

    if (file.is_open())
    {
        std::vector<std::string> instructionProps;
        std::string line;

        while (std::getline(file, line))
        {
            instructionProps = pxvm::FileParserService::getSplitLine(line);

            if (!instructionProps.empty() && (instructionProps[0] == "SECTION"))
            {
                pxvm::Section *section {new pxvm::Section {instructionProps[1]}};

                while (std::getline(file, line))
                {
                    if (!line.empty())
                    {
                        instructionProps = pxvm::FileParserService::getSplitLine(line);

                        if (instructionProps[0] != "ENDSECTION")
                        {
                            section->add(instructionProps);
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                list.add(section);
            }
        }
    }

    return list;
}
}