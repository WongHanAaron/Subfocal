#include "stdafx.h"
#include "Algorithm.hpp"

void Algorithm::Inject(DependencyProvider* provider) 
{ 
	_logger = provider->GetService<Logger>();
}