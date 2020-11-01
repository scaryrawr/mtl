#include <mtl/string.hpp>
#include <gtest/gtest.h>

TEST(StringReplace, EscapePath)
{
    std::wstring path{L"/home/user/not a real dir"};
    mtl::string::replace_all(path, L" ", L"\\ ");
    ASSERT_EQ(path, L"/home/user/not\\ a\\ real\\ dir");
}