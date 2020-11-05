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
                auto [lp, rp] = std::mismatch(std::begin(lhs), std::end(lhs),
                                              std::begin(rhs), std::end(rhs), character::iequals<CharT>(m_locale));

                return (lp == std::end(lhs) && rp == std::end(rhs)) ? std::strong_ordering::equal
                       : (lp == std::end(lhs))                      ? std::strong_ordering::less
                       : (rp == std::end(rhs))                      ? std::strong_ordering::greater
                                                                    : std::toupper(*lp, m_locale) <=> std::toupper(*rp, m_locale);
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
