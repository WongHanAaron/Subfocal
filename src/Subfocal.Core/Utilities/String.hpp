#pragma once
#include <string>
#include <algorithm>
#include <cctype>

/// <summary> A static class for all the helper methods related to strings </summary>
class String
{
public:
	static std::string ToUpper(const std::string& str);
	static std::string ToLower(const std::string& str);
	static bool IsCaseInvariantEquals(const std::string& str1, const std::string& str2);
};

