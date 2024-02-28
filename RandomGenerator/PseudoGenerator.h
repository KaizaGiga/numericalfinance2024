#pragma once

#include "UniformGenerator.h"
#include "pch.h"

class PseudoGenerator : public UniformGenerator
{
protected:
	myLong Seed;

public:
	PseudoGenerator(double inputSeed);
	PseudoGenerator() {}
	~PseudoGenerator();
};





