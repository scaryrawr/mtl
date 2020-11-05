#include <array>
#include <mtl/string.hpp>
#include <gtest/gtest.h>

TEST(StringSplit, RawString)
{
    const wchar_t *str{L"Hello World"};
    std::array<std::wstring_view, 2> output;
    mtl::string::split(str, L" ", std::begin(output));
    ASSERT_EQ(output[0], L"Hello");
    ASSERT_EQ(output[1], L"World");
}

TEST(StringSplit, BasicString)
{
    std::wstring str{L"Hello World"};
    std::array<std::wstring_view, 2> output;
    mtl::string::split(str, L" ", std::begin(output));

    ASSERT_EQ(output[0], L"Hello");
    ASSERT_EQ(output[1], L"World");
}

TEST(StringSplit, StringView)
{
    std::wstring_view str{L"Hello World"};
    std::array<std::wstring_view, 2> output;
    mtl::string::split(str, L" ", std::begin(output));

    ASSERT_EQ(output[0], L"Hello");
    ASSERT_EQ(output[1], L"World");
}

TEST(StringSplit, OutputBasicString)
{
    std::wstring_view str{L"Hello World"};
    std::vector<std::wstring> output;

    // Need to specify output type as template argument if not using string_views
    mtl::string::split<wchar_t, std::wstring>(str, L" ", std::back_inserter(output));

    ASSERT_EQ(output.size(), 2);
    ASSERT_EQ(output[0], L"Hello");
    ASSERT_EQ(output[1], L"World");
}

TEST(StringSplit, LastIsDelim)
{
    const wchar_t *str{L"Hello World "};
    std::vector<std::wstring_view> output;
    mtl::string::split(str, L" ", std::back_inserter(output));

    ASSERT_EQ(output.size(), 2);
    ASSERT_EQ(output[0], L"Hello");
    ASSERT_EQ(output[1], L"World");
}
