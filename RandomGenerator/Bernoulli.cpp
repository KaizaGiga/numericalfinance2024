#include "Bernoulli.h"


Bernoulli::Bernoulli(double inputProb) : p(inputProb), Uniform()
{
}


Bernoulli::~Bernoulli()
{
	
}

double Bernoulli::Generate()
{
	return (Uniform.Generate() <= p);
}