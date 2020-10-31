#include <vector>
#include <mtl/string.hpp>
#include <gtest/gtest.h>

#define HELLO L"HELLO"
#define hElLo L"hElLo"
#define WORLD L"WORLD"
#define wOrLd L"wOrLd"

TEST(ICompare, Sort)
{
    std::vector<std::wstring_view> strs{{WORLD,
                                         HELLO,
                                         wOrLd,
                                         hElLo}};

    std::sort(std::begin(strs), std::end(strs), mtl::string::iless<wchar_t>{});
    ASSERT_EQ(strs[0], HELLO);
    ASSERT_EQ(strs[1], hElLo);
    ASSERT_EQ(strs[2], WORLD);
    ASSERT_EQ(strs[3], wOrLd);
}

TEST(ICompare, Equal)
{
    mtl::string::iequals<wchar_t> equals;
    ASSERT_TRUE(equals(HELLO, hElLo));
    ASSERT_TRUE(equals(WORLD, wOrLd));
    ASSERT_FALSE(equals(HELLO, WORLD));
    ASSERT_FALSE(equals(L"fire", L"firefox"));
}

TEST(ICompare, Less)
{
    mtl::string::iless<wchar_t> less;
    ASSERT_TRUE(less(HELLO, WORLD));
    ASSERT_TRUE(less(HELLO, wOrLd));
    ASSERT_TRUE(less(hElLo, WORLD));
    ASSERT_TRUE(less(hElLo, wOrLd));
    ASSERT_TRUE(less(L"fire", L"firefox"));
    ASSERT_FALSE(less(HELLO, hElLo));
    ASSERT_FALSE(less(hElLo, HELLO));
    ASSERT_FALSE(less(WORLD, wOrLd));
    ASSERT_FALSE(less(wOrLd, WORLD));
}

TEST(ICompare, Greater)
{
    mtl::string::igreater<wchar_t> greater;
    ASSERT_TRUE(greater(WORLD, HELLO));
    ASSERT_TRUE(greater(wOrLd, HELLO));
    ASSERT_TRUE(greater(WORLD, hElLo));
    ASSERT_TRUE(greater(wOrLd, hElLo));
    ASSERT_TRUE(greater(L"firefox", L"fire"));
    ASSERT_FALSE(greater(hElLo, HELLO));
    ASSERT_FALSE(greater(HELLO, hElLo));
    ASSERT_FALSE(greater(wOrLd, WORLD));
    ASSERT_FALSE(greater(WORLD, wOrLd));
}

TEST(ICompare, SortUnique)
{
    std::vector<std::wstring_view> strs{{WORLD,
                                         HELLO,
                                         wOrLd,
                                         hElLo}};

    std::sort(std::begin(strs), std::end(strs), mtl::string::iless<wchar_t>{});
    strs.erase(std::unique(std::begin(strs), std::end(strs), mtl::string::iequals<wchar_t>{}), std::end(strs));
    ASSERT_EQ(strs.size(), 2);
    ASSERT_EQ(strs[0], HELLO);
    ASSERT_EQ(strs[1], WORLD);
}