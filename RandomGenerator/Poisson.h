#pragma once
#include "DiscreteGenerator.h"
#include "EcuyerCombined.h"
#include "pch.h"
class Poisson : public DiscreteGenerator
{
protected:
	double Lambda;
	EcuyerCombined Uniform;
	myLong Factorial(myLong n);

public:
	Poisson(double lambda);
	~Poisson();
};

class PoissonFirstAlgo : public Poisson
{
public:
	PoissonFirstAlgo(double lambda);
	double Generate();
};

class PoissonSecondAlgo : public Poisson
{
public:
	PoissonSecondAlgo(double lambda);
	double Generate();
};
