#pragma once
#include "DiscreteGenerator.h"
#include "Bernoulli.h"
#include "pch.h"

class Binomial : public DiscreteGenerator
{
protected:
	myLong n;
	Bernoulli Bern;

public:
	Binomial(myLong n, double p);
	~Binomial();
	double Generate();
};

