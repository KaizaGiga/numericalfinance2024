#pragma once
#include "ContinuousGenerator.h"
#include "EcuyerCombined.h"
#include "pch.h"

class Normal : public ContinuousGenerator
{
protected:
	double Mu;
	double Sigma;
	EcuyerCombined Uniform;

public:
	Normal(double inputMu, double inputSigma);
	~Normal();
};

class NormalBoxMuller : public Normal
{
private:
	bool requireNewSimulation;
	double X;
	double Y;

public:
	NormalBoxMuller(double inputMu, double inputSigma);
	double Generate();
};

class NormalCLT : public Normal
{
public:
	NormalCLT(double inputMu, double inputSigma);
	double Generate();
};

class NormalRejectionSampling : public Normal
{
public:
	NormalRejectionSampling(double inputMu, double inputSigma);
	double Generate();
};