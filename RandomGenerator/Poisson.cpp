#include "Poisson.h"
#include <exception>
#include <cmath>

Poisson::Poisson(double lambda) : Lambda(lambda), Uniform()
{
	if (lambda <= 0)
		throw std::exception("Lambda must be strictly positive for Poisson distribution");
	Lambda = lambda;
}

Poisson::~Poisson()
{
}

myLong Poisson::Factorial(myLong n)
{
	return (n == 1 || n == 0) ? 1 : Factorial(n - 1) * n;
}

PoissonFirstAlgo::PoissonFirstAlgo(double lambda) : Poisson(lambda)
{}

double PoissonFirstAlgo::Generate()
{
	throw std::exception("The first algorithm is not implemented yet for Poisson distribution");
}

PoissonSecondAlgo::PoissonSecondAlgo(double lambda) : Poisson(lambda)
{}

double PoissonSecondAlgo::Generate()
{
	throw std::exception("The second algorithm is not implemented yet for Poisson distribution");
}