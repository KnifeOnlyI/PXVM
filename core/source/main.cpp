#include <boost/assert.hpp>

#include "parser/FileParserService.hpp"
#include "instruction/Instruction.hpp"

void assertInstruction(
    const pxvm::Instruction &instruction,
    const std::string &name,
    const std::string &param1,
    const std::string &param2)
{
    assert(name == instruction.getName());
    assert(param1 == instruction.getParam1());
    assert(param2 == instruction.getParam2());
}

int main()
{
    /* Unit tests for getSectionListFromFile from file ============================================================== */

    pxvm::SectionList sectionList = pxvm::FileParserService::getSectionListFromFile("resources/main.pxasm");
    const pxvm::Section &mainSection = sectionList.get("__main__");
    const pxvm::Section &addSection = sectionList.get("add");

    assert(2 == sectionList.getNbSection());
    assert(5 == mainSection.getNbInstruction());
    assert(4 == addSection.getNbInstruction());

    assertInstruction(mainSection.get(0), "MEM", "vara", "5");
    assertInstruction(mainSection.get(0), "MEM", "vara", "5");
    assertInstruction(mainSection.get(1), "MEM", "varb", "2");
    assertInstruction(mainSection.get(2), "MOV", "rpia", "vara");
    assertInstruction(mainSection.get(3), "MOV", "rpib", "varb");
    assertInstruction(mainSection.get(4), "JMP", "add", "");

    assertInstruction(addSection.get(0), "MOV", "rs", "rpib");
    assertInstruction(addSection.get(1), "MOV", "rs", "rpia");
    assertInstruction(addSection.get(2), "ADD", "", "");
    assertInstruction(addSection.get(3), "MOV", "rria", "");

    /* Unit tests for FileParserService ============================================================================= */

    const std::string instruction = R"(MOV vara, "Hello World !" ; Le commentaire)";
    const std::string beginSection = R"(SECTION __main__ ; Le commentaire)";
    const std::string endSection = R"(ENDSECTION __main__ ; Le commentaire)";
    const std::vector splitLine = pxvm::FileParserService::getSplitLine(instruction);
    const pxvm::Instruction *ai {pxvm::Instruction::create(splitLine)};

    assert("MOV vara, \"Hello World !\"" == pxvm::FileParserService::trim(instruction));
    assert("SECTION __main__" == pxvm::FileParserService::trim(beginSection));
    assert("ENDSECTION __main__" == pxvm::FileParserService::trim(endSection));
    assert(3 == splitLine.size());
    assert("MOV" == splitLine[0]);
    assert("vara" == splitLine[1]);
    assert("\"Hello World !\"" == splitLine[2]);
    assert("MOV" == ai->getName());
    assert("vara" == ai->getParam1());
    assert("\"Hello World !\"" == ai->getParam2());

    /* ============================================================================================================== */

    return 0;
}
