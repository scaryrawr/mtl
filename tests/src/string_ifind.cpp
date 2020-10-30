#include <mtl/string.hpp>
#include <gtest/gtest.h>

TEST(StringIFind, RawString)
{
    const char *str{"Hello World"};
    ASSERT_EQ(mtl::string::ifind(str, "world"), 6);
}

TEST(StringIFind, BasicString)
{
    std::string str{"Hello World"};
    ASSERT_EQ(mtl::string::ifind(str, "world"), 6);
}

TEST(StringIFind, StringView)
{
    std::string_view str{"Hello World"};
    ASSERT_EQ(mtl::string::ifind(str, "world"), 6);
}