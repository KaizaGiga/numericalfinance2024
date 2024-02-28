
#include "RandomGenerator.h"

double RandomGenerator::Mean(myLong nbSim)
{
	double result = 0.;
	for (myLong i = 0; i < nbSim; ++i)
		result += Generate();
	return result / nbSim;
}
double RandomGenerator::Deviation(myLong nbSim)
{
	return 0.;
}

RandomGenerator::RandomGenerator()
{
}


RandomGenerator::~RandomGenerator()
{
}
