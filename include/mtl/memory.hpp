#pragma once

#include <type_traits>
#include "type_traits.hpp"

namespace mtl
{
    template <class FuncPtr, FuncPtr func>
    struct unique_deleter
    {
        using value_type = argument_type_t<FuncPtr>;
        auto operator()(value_type arg)
        {
            return func(arg);
        }
    };

    template <class FuncPtr, FuncPtr func>
    using unique_ptr = std::unique_ptr<std::remove_pointer_t<argument_type_t<FuncPtr>>, unique_deleter<FuncPtr, func>>;
} // namespace mtl
