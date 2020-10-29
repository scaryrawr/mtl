#pragma once

#include <string>
#include <string_view>

namespace mtl
{
    namespace string
    {
        template <class CharT, class OutType = std::basic_string_view<CharT>, class OutIter>
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

        template <class CharT, class OutType = std::basic_string_view<CharT>, class Allocator = std::allocator<CharT>, class CharTraits = std::char_traits<CharT>, class OutItr>
        OutItr split(const std::basic_string<CharT, CharTraits, Allocator> &str, std::basic_string_view<typename CharTraits::char_type> delim, OutItr out)
        {
            return split<CharT, OutType, OutItr>(std::basic_string_view<CharT>(str), delim, out);
        }

        template <class CharT, class OutType = std::basic_string_view<CharT>, class CharTraits = std::char_traits<CharT>, class OutItr>
        OutItr split(const CharT *str, std::basic_string_view<typename CharTraits::char_type> delim, OutItr out)
        {
            return split<CharT, OutType, OutItr>(std::basic_string_view<CharT>(str), delim, out);
        }
    } // namespace string
} // namespace mtl
