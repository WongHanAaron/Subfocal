#pragma once
#include "..\..\stdafx.h"
#include "Configuration.hpp"
#include "Configurer.hpp"
#include "..\..\Utilities\DependencyInjection\IInjectable.hpp"

class Configurable : public IInjectable
{
public:
	/// <summary> Call to load a specific configuration into this algorithm </summary>
	virtual void SetConfiguration(Configuration config);

	/// <summary> Sets this configurer for this configurable object </summary>
	void SetConfigurer(const std::string& configurationKey, std::function<void(std::string)> valueSetter, const std::string& defaultValue = "", bool required = true);

	/// <summary> Sets this configurer for this configurable object </summary>
	void SetConfigurer(const std::string& configurationKey, std::function<void(double)> valueSetter, double defaultValue = 0.0, bool required = true);

	/// <summary> Gets the list of configurations for this configurable </summary>
	std::vector<std::string> GetConfigurations();

	/// <summary> Gets the list of required configuration for this configurable </summary>
	std::vector<std::string> GetRequiredConfigurations();

protected:
	/// <summary> Configure methods for string configuration </summary>
	std::map<std::string, Configurer<std::string>> StringConfigurable;

	/// <summary> Configure methods for numeric configuration </summary>
	std::map<std::string, Configurer<double>> NumericConfigurable;

	/// <summary> Configure the configuration collection using the configurers and add them to the missing fields if the configuration is missing </summary>
	template <typename Type>
	void _configureFieldsOrAddToMissing(std::map<std::string, Type> configurations, std::map<std::string, Configurer<Type>> configurers, std::vector<std::string>& missingConfigurations);
};

