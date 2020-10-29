#pragma once

#include <locale>
#include <string>
#include <string_view>

namespace mtl
{
    namespace string
    {
        template <class CharT = char>
        struct iequals
        {
            iequals(const std::locale &locale = std::locale()) : m_locale(locale)
            {
            }

            bool operator()(CharT left, CharT right) const
            {
                return std::toupper(left, m_locale) == std::toupper(right, m_locale);
            }

        private:
            const std::locale &m_locale;
        };

        template <class CharT = char>
        struct iless
        {
            iless(const std::locale &locale = std::locale()) : m_locale(locale)
            {
            }

            auto operator()(CharT left, CharT right) const
            {
                return std::toupper(left, m_locale) < std::toupper(right, m_locale);
            }

        private:
            const std::locale &m_locale;
        };

        template <class CharT = char>
        struct igreater
        {
            igreater(const std::locale &locale = std::locale()) : m_locale(locale)
            {
            }

            auto operator()(CharT left, CharT right) const
            {
                return std::toupper(left, m_locale) > std::toupper(right, m_locale);
            }

        private:
            const std::locale &m_locale;
        };

        template <class CharT>
        auto ifind(std::basic_string_view<CharT> str, std::basic_string_view<CharT> other, size_t startPosition = 0, const std::locale &locale = std::locale())
        {
            auto itr = std::search(std::begin(str) + startPosition, std::end(str), std::begin(other), std::end(other), iequals<CharT>{locale});
            return itr == std::end(str) ? std::basic_string_view<CharT>::npos : itr - std::begin(str);
        }

        template <class CharT, class CharTraits = std::char_traits<CharT>>
        auto ifind(const std::basic_string<CharT> &str, std::basic_string_view<typename CharTraits::char_type> other, size_t startPosition = 0, const std::locale &locale = std::locale())
        {
            return ifind(std::basic_string_view<CharT>(str), other, startPosition, locale);
        }

        template <class CharT, class CharTraits = std::char_traits<CharT>>
        auto ifind(const CharT *str, std::basic_string_view<typename CharTraits::char_type> other, size_t startPosition = 0, const std::locale &locale = std::locale())
        {
            return ifind(std::basic_string_view<CharT>(str), other, startPosition, locale);
        }

        template <class CharT, class Allocator = std::allocator<CharT>, class CharTraits = std::char_traits<CharT>>
        void ierase_all(std::basic_string<CharT, CharTraits, Allocator> &str, std::basic_string_view<typename CharTraits::char_type> other, size_t start = 0, const std::locale &locale = std::locale())
        {
            for (auto position{ifind<CharT>(str, other, start, locale)}; std::basic_string_view<CharT>::npos != position; position = ifind<CharT>(str, other, position, locale))
            {
                str.erase(position, other.length());
            }
        }
    } // namespace string

} // namespace mtl
