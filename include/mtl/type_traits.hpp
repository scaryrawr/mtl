#pragma once

namespace mtl
{
    template<class>
    struct argument_type;

    template<class ReturnType, class ArgType>
    struct argument_type<ReturnType(ArgType)>
    {
        using type = ArgType;
    };

    template<class FuncType>
    using argument_type_t = typename argument_type<FuncType>::type;
} // namespace mtl
