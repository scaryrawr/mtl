#pragma once

namespace mtl
{
    template <class>
    struct unary_argument_type;

    template <class ReturnType, class ArgType>
    struct unary_argument_type<ReturnType(ArgType)>
    {
        using type = ArgType;
    };

    template <class FuncType>
    using unary_argument_type_t = typename unary_argument_type<FuncType>::type;
} // namespace mtl
