#pragma once
#include "Algorithm.hpp"

/// <summary> The base component for creating algorithms </summary>
class AlgorithmFactoryBase : public IInjectable
{
public:
	template<typename AlgorithmType>
	inline std::shared_ptr<AlgorithmType> Create(const std::string& algorithmName, Configuration config)
	{
		auto created = Create(algorithmName, config);
		auto cast = std::dynamic_pointer_cast<AlgorithmType>(created);
		
		if (cast == nullptr) throw std::invalid_argument("Unable to create and cast algorithm '" + algorithmName + "'");

		return cast;
	}

	/// <summary> Create an algorithm based on the name and passed in configuration </summary>
	virtual std::shared_ptr<Algorithm> Create(const std::string& algorithmName, Configuration config);

	/// <summary> Injected required dependencies for the factory to work </summary>
	virtual void Inject(DependencyProvider* provider) override;

	/// <summary> Checks if this algorithm factory contains the factory methods for the specified algorithm </summary>
	virtual bool HasAlgorithm(const std::string& algorithmName);

	/// <summary> Gets all the available algorithms in this factory </summary>
	virtual std::vector<std::string> GetAvailableAlgorithms();

	/// <summary> Get the dependency provider specified in this factory </summary>
	inline std::shared_ptr<DependencyProvider> GetProvider()
	{
		return _dependencyProvider;
	}

protected:
	std::map<std::string, std::pair<std::shared_ptr<Algorithm>, std::function<std::shared_ptr<Algorithm>(void)>>> _algorithmToCreationMethod;

	std::vector<std::function<std::shared_ptr<IDependable>(void)>> _algorithmTransientCreationMethod;

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
			std::make_pair(algorithm,
							[this]() -> std::shared_ptr<Algorithm> 
							{
								if (this->GetProvider() == nullptr) throw std::invalid_argument("No dependency provider was injected into factory");

								auto provider = this->GetProvider();

								auto typedAlgorithm = provider->GetService<AlgorithmType>();

								auto algorithm = std::dynamic_pointer_cast<Algorithm>(typedAlgorithm);

								if (algorithm == nullptr)
									throw std::invalid_argument("The passed in type cannot be cast as an Algorithm");

								return algorithm;
							});

		_algorithmTransientCreationMethod.push_back([]() -> std::shared_ptr<IDependable>
		{
			auto algorithm = std::make_shared<AlgorithmType>();

			auto dependable = std::dynamic_pointer_cast<IDependable>(algorithm);

			if (dependable == nullptr)
				throw std::invalid_argument("Unable to cast Algorithm as IDependable");

			return dependable;
		});
	}
};