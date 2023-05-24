#pragma once
#include "Algorithm.hpp"

/// <summary> The base component for creating algorithms </summary>
class AlgorithmFactoryBase : public IInjectable
{
public:
	/// <summary> Create an algorithm based on the name and passed in configuration </summary>
	virtual std::shared_ptr<Algorithm> Create(const std::string& algorithmName, Configuration config);

	/// <summary> Registers the algorithms at this factory to the dependency provider </summary>
	virtual void RegisterAlgorithms(DependencyProvider* provider) = 0;

	/// <summary> Injected required dependencies for the factory to work </summary>
	virtual void Inject(DependencyProvider* provider) override;

	inline std::shared_ptr<DependencyProvider> GetProvider()
	{
		return _dependencyProvider;
	}

protected:
	std::map<std::string, std::function<std::shared_ptr<Algorithm>(void)>> _algorithmToCreationMethod;

	std::shared_ptr<DependencyProvider> _dependencyProvider;
	
	/// <summary> Registers an algorithm to be create-able from this factory </summary>
	template<typename AlgorithmType>
	inline void _addAlgorithmFactory()
	{
		auto algorithmSample = std::make_shared<AlgorithmType>();
		auto algorithm = std::dynamic_pointer_cast<Algorithm>(algorithmSample);

		if (algorithm == nullptr)
			throw std::invalid_argument("The passed in type cannot be cast as an Algorithm");
		
		_algorithmToCreationMethod[algorithm->GetComponentName()] =
		[this]() -> std::shared_ptr<Algorithm> 
		{
			if (this->GetProvider() == nullptr) throw std::invalid_argument("No dependency provider was injected into factory");

			auto typedAlgorithm = this->GetProvider()->GetService<AlgorithmType>();

			auto algorithm = std::dynamic_pointer_cast<Algorithm>(typedAlgorithm);

			if (algorithm == nullptr)
				throw std::invalid_argument("The passed in type cannot be cast as an Algorithm");

			return algorithm;

		};
	}
};