#include "R1R1Function.h"
#include <cmath>
#include <algorithm>

R1R1Function::R1R1Function()
{}

R1R1Function::~R1R1Function()
{}

VanillaTerminalCondition::VanillaTerminalCondition(double strike) : 
	R1R1Function(), Strike(strike)
{}

CallTerminalCondition::CallTerminalCondition(double strike) : VanillaTerminalCondition(strike)
{}

double CallTerminalCondition::operator()(double x)
{
	return std::max(x - Strike, 0.);
}


double PutTerminalCondition::operator()(double x)
{
	return std::max(Strike - x, 0.);
}

// Top and Bottom conditions

CallTopBoundary::CallTopBoundary(double sMax, double strike) : R1R1Function(), SMax(sMax), Strike(strike)
{}

double CallTopBoundary::operator()(double t)
{
	return std::max(SMax - Strike, 0.);
}





PutTopBoundary::PutTopBoundary(double sMax, double strike) : R1R1Function(), SMax(sMax), Strike(strike)
{}

PutTerminalCondition::PutTerminalCondition(double strike) : VanillaTerminalCondition(strike)
{}

double PutTopBoundary::operator()(double t)
{
	return std::max(Strike - SMax, 0.);
}

CallBottomBoundary::CallBottomBoundary(double sMin, double strike) : R1R1Function(), SMin(sMin), Strike(strike)
{}





double CallBottomBoundary::operator()(double t)
{
	return std::max(SMin - Strike, 0.);
}

PutBottomBoundary::PutBottomBoundary(double sMin, double strike) : R1R1Function(), SMin(sMin), Strike(strike)
{}

double PutBottomBoundary::operator()(double t)
{
	return std::max(Strike - SMin, 0.);
}