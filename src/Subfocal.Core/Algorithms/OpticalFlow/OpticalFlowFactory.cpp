#include "stdafx.h"
#include "OpticalFlowFactory.hpp"

OpticalFlowFactory::OpticalFlowFactory()
{
    _addAlgorithmFactory<HornSchunckOpticalFlow>();
}

std::string OpticalFlowFactory::GetComponentName()
{
    return "OpticalFlowFactory";
}
