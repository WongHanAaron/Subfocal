#pragma once
#include "AlgorithmFactoryBase.hpp"
#include "BinaryComposite/BinaryCompositeFactory.hpp"

/// <summary> The consolidated algorithm factory for creating all subfocal algorithms </summary>
class SubfocalAlgorithmFactory : public AlgorithmFactoryBase
{
public:
	SubfocalAlgorithmFactory();

	/// <summary> Create an algorithm based on the name and passed in configuration </summary>
	virtual std::shared_ptr<Algorithm> Create(const std::string& algorithmName, Configuration config) override;

	/// <summary> Injected required dependencies for the factory to work </summary>
	virtual void Inject(DependencyProvider* provider) override;

	/// <summary> Checks if this algorithm factory contains the factory methods for the specified algorithm </summary>
	virtual bool HasAlgorithm(const std::string& algorithmName) override;

	/// <summary> Gets all the available algorithms in this factory </summary>
	virtual std::vector<std::string> GetAvailableAlgorithms() override;

	virtual std::string GetComponentName() override;

protected:
	std::vector <std::shared_ptr<AlgorithmFactoryBase>> _algorithmFactories;

	/// <summary> Adds a specific algorithm factory type to this algorithm factory </summary>
	template<typename AlgorithmFactoryType>
	void AddAlgorithmFactory();
};

