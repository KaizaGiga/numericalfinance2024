#pragma once
#include "PseudoGenerator.h"
#include "pch.h"

class LinearCongruential : public PseudoGenerator
{
private:
	myLong Multiplier;
	myLong Increment;
	myLong Modulus;

public:
	LinearCongruential(myLong Multiplier, myLong Increment, myLong Modulus, myLong Seed);
	LinearCongruential() {};
	~LinearCongruential();

	double Generate();
};

