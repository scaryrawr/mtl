#include <array>
#include <mtl/memory.hpp>
#include <gtest/gtest.h>

#define HELLO "Hello World"

bool MessageAlloc(char **ptr)
{
    char *msg{static_cast<char *>(malloc(sizeof(HELLO)))};
    if (msg)
    {
        snprintf(msg, sizeof(HELLO), "%s", HELLO);
        *ptr = msg;

        return true;
    }

    return false;
}

TEST(OutPtr, UniquePtr)
{
    using unique_malloc = mtl::typed_unique_ptr<char, decltype(::free), &::free>;
    unique_malloc str;
    const bool alloced{MessageAlloc(mtl::out_ptr(str))};
    ASSERT_TRUE(alloced);
    ASSERT_STREQ(static_cast<char *>(str.get()), HELLO);
}