#pragma once
#include "..\..\stdafx.h"
#include <string>

/// <summary> "Interface" that represents a class that can be depended on by others and injected into using the dependency injection </summary>
class IDependable : public std::enable_shared_from_this<IDependable>
{
public:
	/// <summary> Gets the component name for this component. This should be name that the dependency is registered at </summary>
	virtual std::string GetComponentName() = 0;

protected:
    
    template <typename Derived>
    inline std::shared_ptr<Derived> shared_from_base()
    {
        auto thisPointer = shared_from_this();
        return std::static_pointer_cast<Derived>(thisPointer);
    }
};