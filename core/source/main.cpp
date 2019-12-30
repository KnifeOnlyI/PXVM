#include "vm/VM.hpp"

int main()
{
    pxvm::VM vm;

    vm.execute("resources/main.pxasm");

    return 0;
}
