#pragma once

namespace mtl
{
    template <class FuncType>
    struct remove_noexcept
    {
        using type = FuncType;
    };

    template <class ReturnType, class... ArgsType>
    struct remove_noexcept<ReturnType(ArgsType...) noexcept>
    {
        using type = ReturnType(ArgsType...);
    };

    template <class FuncType>
    using remove_noexcept_t = typename remove_noexcept<FuncType>::type;

    template <class>
    struct unary_argument_type;

    template <class ReturnType, class ArgType>
    struct unary_argument_type<ReturnType(ArgType)>
    {
        using type = ArgType;
    };

    template <class ReturnType, class ArgType>
    struct unary_argument_type<ReturnType(ArgType) noexcept>
    {
        using type = ArgType;
    };

    template <class FuncType>
    using unary_argument_type_t = typename unary_argument_type<FuncType>::type;
} // namespace mtl
