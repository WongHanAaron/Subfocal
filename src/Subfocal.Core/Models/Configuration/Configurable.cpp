#include "stdafx.h"
#include "Configurable.hpp"


void Configurable::SetConfiguration(Configuration config)
{
	std::vector<std::string> missingRequired;

	_configureFieldsOrAddToMissing<double>(config.Numeric, NumericConfigurable, missingRequired);
	_configureFieldsOrAddToMissing<std::string>(config.String, StringConfigurable, missingRequired);

	if (missingRequired.size() > 0)
	{
		throw std::invalid_argument("The configuration object was missing the following configurations: ");
	}
}

template <typename Type>
void Configurable::_configureFieldsOrAddToMissing(std::map<std::string, Type> config, std::map<std::string, Configurer<Type>> configurers, std::vector<std::string>& missingConfigurations)
{
	for (auto& pair : configurers)
	{
		auto key = pair.first;
		auto configurer = pair.second;

		auto search = config.find(key);

		if (search != config.end())
			configurer.ValueSetter(search->second);
		else if (configurer.IsRequired)
			missingConfigurations.push_back(key);
		else
			configurer.ValueSetter(configurer.DefaultValue);
	}
}


void Configurable::SetConfigurer(const std::string& configurationKey, std::function<void(std::string)> valueSetter, const std::string& defaultValue, bool required)
{
	auto c = Configurer<std::string>();
	c.ValueSetter = valueSetter;
	c.IsRequired = required;
	c.DefaultValue = defaultValue;
	StringConfigurable[configurationKey] = c;
}

void Configurable::SetConfigurer(const std::string& configurationKey, std::function<void(double)> valueSetter, double defaultValue, bool required) 
{
	auto c = Configurer<double>();
	c.ValueSetter = valueSetter;
	c.IsRequired = required;
	c.DefaultValue = defaultValue;
	NumericConfigurable[configurationKey] = c;
}

std::vector<std::string> Configurable::GetConfigurations() 
{
	return std::vector<std::string>();
}

std::vector<std::string> Configurable::GetRequiredConfigurations()
{
	return std::vector<std::string>();
}