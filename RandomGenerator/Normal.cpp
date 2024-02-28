
#include "Normal.h"
#include <exception>
#include <cmath>

const long double PI = 3.141592653589793238L;

Normal::Normal(double inputMu, double inputSigma) : Mu(inputMu), Uniform()
{
	if(inputSigma < 0)
		throw std::exception("The variance must be strictly positive for Normal distribution");
	Sigma = inputSigma;
}

Normal::~Normal()
{}

NormalBoxMuller::NormalBoxMuller(double inputMu, double inputSigma) : Normal(inputMu, inputSigma)
{
	requireNewSimulation = true;
}

NormalCLT::NormalCLT(double inputMu, double inputSigma) : Normal(inputMu, inputSigma)
{}

NormalRejectionSampling::NormalRejectionSampling(double inputMu, double inputSigma) : Normal(inputMu, inputSigma)
{}

double NormalBoxMuller::Generate()
{
	
	throw std::exception("The Box-Muller method is not implemented yet for Normal distribution");
}
double NormalCLT::Generate()
{
	throw std::exception("The Central Limit Theorem method is not implemented yet for Normal distribution");
}
double NormalRejectionSampling::Generate()
{
	throw std::exception("The rejection sampling method is not implemented yet for Normal distribution");
}