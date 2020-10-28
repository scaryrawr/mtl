#pragma once

#include <string>
#include <string_view>

namespace mtl
{
    template <class CharT = char, class OutType = std::basic_string_view<CharT>, class OutIter>
    OutIter split(std::basic_string_view<CharT> str, std::basic_string_view<CharT> delim, OutIter out)
    {
        size_t position{};
        const size_t delimLength{delim.length()};
        for (auto pos{str.find(delim)}; pos != std::basic_string_view<CharT>::npos; pos = str.find(delim, position))
        {
            (*out++) = OutType(str.substr(position, pos - position));
            position = pos + delimLength;
        }

        // Remaining bit of string
        if (position < str.length())
        {
            (*out++) = OutType(str.substr(position, str.length() - position));
        }

        return out;
    }
} // namespace mtl
