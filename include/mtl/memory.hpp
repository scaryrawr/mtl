#pragma once

#include <memory>
#include <type_traits>

#include "type_traits.hpp"

namespace mtl
{
    template <class FuncPtr, FuncPtr func>
    struct custom_delete
    {
        using value_type = unary_argument_type_t<FuncPtr>;
        auto operator()(value_type arg)
        {
            return func(arg);
        }
    };

    template <class FuncPtr, FuncPtr func>
    using unique_ptr = std::unique_ptr<std::remove_pointer_t<unary_argument_type_t<FuncPtr>>, custom_delete<FuncPtr, func>>;

    template <class SmartPtr>
    struct out_ptr
    {
        using pointer = typename SmartPtr::pointer;
        out_ptr(SmartPtr& smartpointer) : wrapper(smartpointer)
        {
        }

        ~out_ptr()
        {
            wrapper.reset(ptr);
        }

        operator pointer*()
        {
            return &ptr;
        }

    private:
        pointer ptr{};
        SmartPtr& wrapper;
    };
} // namespace mtl
