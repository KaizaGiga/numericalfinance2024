
#include "Exponential.h"
#include <exception>


Exponential::Exponential(double inputLambda) : Uniform()
{
	if(inputLambda <= 0)
		throw std::exception("Lambda must be strictly positive for Exponential distribution");
	Lambda = inputLambda;
}

Exponential::~Exponential()
{}

ExponentialInverseDistribution::ExponentialInverseDistribution(double inputLambda) : Exponential(inputLambda)
{}
ExponentialRejectionSampling::ExponentialRejectionSampling(double inputLambda) : Exponential(inputLambda)
{}

double ExponentialInverseDistribution::Generate()
{
	return -log(Uniform.Generate()) / Lambda;
}

double ExponentialRejectionSampling::Generate()
{
	throw std::exception("The rejection sampling method is not implemented yet for Exponential distribution");
}
