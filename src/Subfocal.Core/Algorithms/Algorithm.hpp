#pragma once
#include "..\stdafx.h"
#include "..\Utilities\DependencyInjection\IInjectable.hpp"
#include "..\Models\Configuration\Configurable.hpp"
#include "..\Utilities\Logging\Logger.hpp"

class Algorithm : public Configurable
{
public:
	virtual void Inject(DependencyProvider* provider) override;

protected:
	std::shared_ptr<Logger> _logger;
};
