#pragma once
#include "ContinuousGenerator.h"
#include "EcuyerCombined.h"
#include "pch.h"

class Exponential : public ContinuousGenerator
{
protected:
	double Lambda;
	EcuyerCombined Uniform;

public:
	Exponential(double inputLambda);
	~Exponential();
};

class ExponentialInverseDistribution : public Exponential
{
public:
	ExponentialInverseDistribution(double inputLambda);
	double Generate();
};

class ExponentialRejectionSampling : public Exponential
{
public:
	ExponentialRejectionSampling(double inputLambda);
	double Generate();
};