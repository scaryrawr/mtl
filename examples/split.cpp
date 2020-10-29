#include <mtl/string.hpp>

#include <array>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const *argv[])
{
    const char *helloworld = "Hello World";
    std::vector<std::string> charworld;
    mtl::string::split<char, std::string>(helloworld, " ", std::back_inserter(charworld));
    std::copy(std::begin(charworld), std::end(charworld), std::ostream_iterator<std::string>(std::cout, " "));

    std::cout << std::endl;

    std::wstring worldhello = L"World Hello";
    std::array<std::wstring_view, 2> wideworld;
    mtl::string::split(worldhello, L" ", std::begin(wideworld));
    std::copy(std::rbegin(wideworld), std::rend(wideworld), std::ostream_iterator<std::wstring_view, wchar_t>(std::wcout, L" "));

    std::wcout << std::endl;

    return 0;
}
