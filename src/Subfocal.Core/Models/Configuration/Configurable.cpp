#include "stdafx.h"
#include "Configurable.hpp"


void Configurable::SetConfiguration(Configuration config)
{

}

void Configurable::SetConfigurer(const std::string& configurationKey, std::function<void(std::string)> valueSetter, const std::string& defaultValue, bool required)
{

}

void Configurable::SetConfigurer(const std::string& configurationKey, std::function<void(double)> valueSetter, double defaultValue, bool required) {

}

std::vector<std::string> Configurable::GetConfigurations() 
{
	return std::vector<std::string>();
}

std::vector<std::string> Configurable::GetRequiredConfigurations()
{
	return std::vector<std::string>();
}