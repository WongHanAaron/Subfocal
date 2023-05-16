#include "stdafx.h"
#include "String.hpp"

/// <summary>
/// Reference: https://stackoverflow.com/questions/28387362/is-there-a-built-in-function-for-stdstring-in-c-to-compare-two-strings-alpha
/// </summary>
bool String::IsCaseInvariantEquals(const std::string& str1, const std::string& str2) 
{
    return std::equal(str1.begin(), str1.end(), str2.begin(),
        [](const char& a, const char& b)
        {
            return (std::tolower(a) == std::tolower(b));
        });
}

/// <summary>
/// Reference: https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
/// </summary>
std::string String::ToLower(const std::string& str)
{
    std::string output(str);
    auto it = std::transform(str.begin(), str.end(), output.begin(),
                             [](unsigned char c) { return std::tolower(c); });
    return output;
}

std::string String::ToUpper(const std::string& str)
{
    std::string output(str);
    auto it = std::transform(str.begin(), str.end(), output.begin(),
        [](unsigned char c)
        {
            auto converted = std::toupper(c);
            return converted;
        });
    return output;
}