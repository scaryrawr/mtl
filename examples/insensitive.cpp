#include <mtl/string.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string hello{"Hello World, all is good"};
    std::cout << mtl::string::ifind(hello, "wOrLd") << std::endl;
    mtl::string::ierase_all(hello, " ");
    std::cout << mtl::string::ifind(L"World hello", L"HeLlO") << std::endl;

    return 0;
}
