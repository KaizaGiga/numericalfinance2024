#pragma once
#include "DiscreteGenerator.h"
#include "EcuyerCombined.h"

class Bernoulli : public DiscreteGenerator
{
protected:
	double p;
	EcuyerCombined Uniform;

public:
	Bernoulli(double inputP);
	~Bernoulli();
	double Generate();
};

