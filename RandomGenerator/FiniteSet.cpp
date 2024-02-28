
#include "FiniteSet.h"


FiniteSet::FiniteSet(const std::vector<double>& inputProb) : Uniform()
{
	double sumProba = 0;
	for (size_t i = 0; i < inputProb.size(); ++i)
	{
		double currentProb = inputProb[i];
		if (currentProb < 0 || currentProb > 1)
		{
			throw std::exception("A probability must be between [0 , 1]");
		}
		else
		{
			sumProba += currentProb;
		}
	}
	if (sumProba != 1)
		throw std::exception("The sum of probabilities must be equal to 1");

	Probabilities = inputProb;
}


FiniteSet::~FiniteSet()
{
}

double FiniteSet::Generate()
{
	throw std::exception("The finite set generator is not implemented yet");
}