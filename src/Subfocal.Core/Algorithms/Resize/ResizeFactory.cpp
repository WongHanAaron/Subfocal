#include "stdafx.h"
#include "ResizeFactory.hpp"

ResizeFactory::ResizeFactory()
{
    _addAlgorithmFactory<ContentAwareResize>();
}

std::string ResizeFactory::GetComponentName()
{
    return "ResizeFactory";
}
