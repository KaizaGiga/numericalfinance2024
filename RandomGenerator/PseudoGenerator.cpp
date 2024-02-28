
#include "PseudoGenerator.h"


PseudoGenerator::PseudoGenerator(double inputSeed) : Seed(inputSeed)
{
	Current = inputSeed;
}


PseudoGenerator::~PseudoGenerator()
{
}
