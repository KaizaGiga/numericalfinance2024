
#include "LinearCongruential.h"


LinearCongruential::LinearCongruential(myLong Multiplier, myLong Increment, myLong Modulus, myLong Seed):
	PseudoGenerator(Seed),
	Multiplier(Multiplier),
	Increment(Increment),	
	Modulus(Modulus)
{
}

LinearCongruential::~LinearCongruential()
{
}


double LinearCongruential::Generate()
{
	Current = (Multiplier * Current + Increment) % Modulus;
	
	return (double) Current / Modulus;
}