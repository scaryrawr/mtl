#pragma once

#include <locale>
#include <string>
#include <string_view>

namespace mtl
{
    namespace string
    {
        namespace character
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
        } // namespace character

        template <class CharT>
        struct icompare
        {
            icompare(const std::locale &locale = std::locale()) : m_locale(locale)
            {
            }

            auto operator()(std::basic_string_view<CharT> lhs, std::basic_string_view<CharT> rhs) const
            {
                size_t len{std::min(lhs.size(), rhs.size())};
                size_t pos{};
                while (std::toupper(lhs[pos], m_locale) == std::toupper(rhs[pos], m_locale) && pos < len)
                {
                    ++pos;
                }

                return (std::toupper(lhs[pos], m_locale) == std::toupper(rhs[pos], m_locale))
                           ? (lhs.size() <=> rhs.size())
                           : (std::toupper(lhs[pos], m_locale) <=> std::toupper(rhs[pos], m_locale));
            }

        private:
            const std::locale &m_locale;
        };

        template <class CharT>
        struct iless
        {
            iless(const std::locale &locale = std::locale()) : m_compare(locale)
            {
            }

            bool operator()(std::basic_string_view<CharT> lhs, std::basic_string_view<CharT> rhs) const
            {
                return m_compare(lhs, rhs) == std::strong_ordering::less;
            }

        private:
            const icompare<CharT> m_compare;
        };

        template <class CharT>
        struct igreater
        {
            igreater(const std::locale &locale = std::locale()) : m_compare(locale)
            {
            }

            bool operator()(std::basic_string_view<CharT> lhs, std::basic_string_view<CharT> rhs) const
            {
                return m_compare(lhs, rhs) == std::strong_ordering::greater;
            }

        private:
            const icompare<CharT> m_compare;
        };

        template <class CharT>
        struct iequals
        {
            iequals(const std::locale &locale = std::locale()) : m_compare(locale)
            {
            }

            bool operator()(std::basic_string_view<CharT> lhs, std::basic_string_view<CharT> rhs) const
            {
                return m_compare(lhs, rhs) == std::strong_ordering::equivalent;
            }

        private:
            const icompare<CharT> m_compare;
        };
    } // namespace string

} // namespace mtl
