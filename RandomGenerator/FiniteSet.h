#pragma once
#include "DiscreteGenerator.h"
#include "EcuyerCombined.h"
#include "pch.h"
#include <vector>
class FiniteSet : public DiscreteGenerator
{
protected:
	std::vector<double> Probabilities;
	EcuyerCombined Uniform;

public:
	FiniteSet(const std::vector<double>& inputProb);
	~FiniteSet();
	double Generate();
};

