#pragma once
#include "PseudoGenerator.h"
#include "LinearCongruential.h"
#include "pch.h"

class EcuyerCombined : public PseudoGenerator
{
protected:
	LinearCongruential FirstLinear;
	LinearCongruential SecondLinear;
public:
	EcuyerCombined();
	~EcuyerCombined();

	double Generate();
};

