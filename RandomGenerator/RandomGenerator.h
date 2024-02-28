#pragma once

#include "pch.h"
typedef unsigned long long myLong ;

class RandomGenerator
{
protected:
	myLong Current;

public:
	RandomGenerator();
	~RandomGenerator();
	myLong GetCurrent() { return Current; }

	virtual double Generate() = 0;
	double Mean(myLong nbSim);
	double Deviation(myLong nbSim);
};

