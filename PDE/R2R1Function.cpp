#include "R2R1Function.h"

R2R1Function::R2R1Function()
{}

R2R1Function::~R2R1Function()
{}

NullFunction::NullFunction() : R2R1Function()
{}

double NullFunction::operator()(double x, double t)
{
	return 0.0;
}

// Diffusion functions
BSActualization::BSActualization(double rate) : R2R1Function(), Rate(rate)
{}

double BSActualization::operator()(double x, double t)
{
	return Rate;
}

BSVariance::BSVariance(double sigma) : R2R1Function(), Sigma(sigma)
{}

double BSVariance::operator()(double x, double t)
{
	return Sigma * Sigma * x * x;
}

BSTrend::BSTrend(double rate) : R2R1Function(), Rate(rate)
{}

double BSTrend::operator()(double x, double t)
{
	return Rate * x;
}