// Random.cpp : Defines the entry point for the console application.
//



#include "LinearCongruential.h"
#include "EcuyerCombined.h"
#include "HeadTail.h"
#include "Bernoulli.h"
#include "Binomial.h"
#include "FiniteSet.h"
#include "Poisson.h"
#include "Exponential.h"
#include <iostream>
#include "Normal.h"

int main()
{
	// LinearCongruential GenLinear(17, 43, 100, 27);

	try
	{
		HeadTail GenHeadTail;
		Bernoulli GenBernoulli(0.3);
		Binomial GenBinomial(100, 0.3);

		std::vector<double> probas{ 0.3, 0.2, 0.4, 0.1 };
		FiniteSet GenFiniteSet(probas);

		PoissonFirstAlgo GenPoisson(2.3);
		ExponentialInverseDistribution GenExponential(0.25);
		NormalBoxMuller GenNormal(2, 0.05);

		for (size_t i = 1; i <= 3; ++i)
		{
			std::cout << "X" << i << " = " << GenNormal.Generate() << std::endl;
		}
		std::cout << "E(X) = " << GenNormal.Mean(10000000) << std::endl;

	}
	catch (std::exception E)
	{
		std::cout << E.what() << std::endl;
	}
	
	double x;
	std::cin >> x;
    return 0;
}

