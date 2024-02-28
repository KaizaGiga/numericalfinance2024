#pragma once
#include "R1R1Function.h"
#include "R2R1Function.h"
#include <vector>

using namespace std;

class PDEGrid2D
{
protected:
	double T;
	double MinX;
	double MaxX;
	double h0; // Time step
	double h1; // space step

	R2R1Function* a;
	R2R1Function* b;
	R2R1Function* r;
	R2R1Function* f;

	R1R1Function* TopBoundaryFunction;
	R1R1Function* BottomBoundaryFunction;
	R1R1Function* RightBoundaryFunction;

	vector< vector<double> > Nodes;
	size_t NodesHeight;
	size_t NodesWidth;

public:
	PDEGrid2D(
		double Maturity,
		double MinUnderlyingValue,
		double MaxUnderlyingValue,
		int NbTimeSteps,
		double StepForUnderlying,
		R2R1Function* VarianceFunction,
		R2R1Function* TrendFunction,
		R2R1Function* ActualizationFunction,
		R2R1Function* SourceTermFunction,
		R1R1Function* TopBoundaryFunction,
		R1R1Function* BottomBoundaryFunction,
		R1R1Function* RightBoundaryFunction
	);
	~PDEGrid2D();

	virtual void FillNodes();

	double GetTimeZeroNodeValue(double spot);

private:

	void FillTopAndBottomBoundary();
	void FillRightBoundary();

};

class PDEGrid2DExplicit : public PDEGrid2D
{
public:
	PDEGrid2DExplicit(
		double Maturity,
		double MinUnderlyingValue,
		double MaxUnderlyingValue,
		int NbTimeSteps,
		double StepForUnderlying,
		R2R1Function* VarianceFunction,
		R2R1Function* TrendFunction,
		R2R1Function* ActualizationFunction,
		R2R1Function* SourceTermFunction,
		R1R1Function* TopBoundaryFunction,
		R1R1Function* BottomBoundaryFunction,
		R1R1Function* RightBoundaryFunction
	);

	void FillNodes();
};