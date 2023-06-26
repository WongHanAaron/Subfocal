#include "stdafx.h"
#include "ResizeFactory.hpp"

ResizeFactory::ResizeFactory()
{
    _addAlgorithmFactory<SeamCarvingResize>();
}

std::string ResizeFactory::GetComponentName()
{
    return "ResizeFactory";
}
