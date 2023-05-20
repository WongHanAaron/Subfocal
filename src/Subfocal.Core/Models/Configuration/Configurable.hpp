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

};

