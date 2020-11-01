#pragma once

#include <string>
#include <string_view>

namespace mtl
{
    namespace string
    {
        template <class CharT, class CharTraits = std::char_traits<CharT>, class Allocator>
        void replace_all(std::basic_string<CharT, CharTraits, Allocator> &str, std::basic_string_view<typename CharTraits::char_type> seq, std::basic_string_view<typename CharTraits::char_type> rep)
        {
            size_t position{};
            const size_t seqLen{seq.length()};
            const size_t repLen{rep.length()};
            for (auto pos{str.find(seq)}; pos != std::basic_string<CharT, CharTraits, Allocator>::npos; pos = str.find(seq, position))
            {
                str.replace(pos, seqLen, rep);
                position = pos + repLen;
            }
        }
    } // namespace string
} // namespace mtl
