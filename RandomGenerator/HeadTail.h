#pragma once
#include "DiscreteGenerator.h"
#include "EcuyerCombined.h"
#include "pch.h"

class HeadTail : public DiscreteGenerator
{
protected:
	EcuyerCombined Uniform;

public:
	HeadTail();
	~HeadTail();
	double Generate();
};

