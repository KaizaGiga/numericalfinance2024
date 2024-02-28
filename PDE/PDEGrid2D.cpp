#include "PDEGrid2D.h"

PDEGrid2D::PDEGrid2D(
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
) :
	T(Maturity),
	MinX(MinUnderlyingValue),
	MaxX(MaxUnderlyingValue),
	h0(Maturity / NbTimeSteps),
	h1(StepForUnderlying),
	a(VarianceFunction),
	b(TrendFunction),
	r(ActualizationFunction),
	f(SourceTermFunction),
	TopBoundaryFunction(TopBoundaryFunction),
	BottomBoundaryFunction(BottomBoundaryFunction),
	RightBoundaryFunction(RightBoundaryFunction)
{
	NodesHeight = (MaxX - MinX) / h1 + 1;
	NodesWidth = NbTimeSteps + 1;
	Nodes = vector< vector<double> >(NodesWidth);
	for (size_t i = 0; i < NodesWidth; ++i)
	{
		Nodes[i] = vector<double>(NodesHeight);
	}
}

PDEGrid2D::~PDEGrid2D()
{
}

void PDEGrid2D::FillRightBoundary()
{
	for (size_t j = 0; j < NodesHeight; ++j)
	{
		//Nodes[NodesWidth - 1][j] = RightBoundaryFunction->operator()(j * h1);
		Nodes[NodesWidth - 1][j] = (*RightBoundaryFunction)(MinX + j * h1);
	}
}

void PDEGrid2D::FillTopAndBottomBoundary()
{
	for (size_t i = 0; i < NodesWidth; ++i)
	{
		Nodes[i][0] = (*BottomBoundaryFunction)(i * h0);
		Nodes[i][NodesHeight - 1] = (*TopBoundaryFunction)(i * h0);
	}
}

void PDEGrid2D::FillNodes()
{
	FillRightBoundary();
	FillTopAndBottomBoundary();
}

double PDEGrid2D::GetTimeZeroNodeValue(double spot)
{
	return Nodes[0][(int)((spot - MinX) / h1)];
}

PDEGrid2DExplicit::PDEGrid2DExplicit(
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
) : PDEGrid2D(
	Maturity,
	MinUnderlyingValue,
	MaxUnderlyingValue,
	NbTimeSteps,
	StepForUnderlying,
	VarianceFunction,
	TrendFunction,
	ActualizationFunction,
	SourceTermFunction,
	TopBoundaryFunction,
	BottomBoundaryFunction,
	RightBoundaryFunction
)
{}

void PDEGrid2DExplicit::FillNodes()
{
	PDEGrid2D::FillNodes();

	for (size_t k = (NodesWidth - 1); k > 0; --k)
	{
		for (size_t j = 1; j < NodesHeight - 1; ++j)
		{
			double x = MinX + j * h1;
			double t = k * h0;

			double AjkH0ToH1Square = h0 * (*a)(x, t) / (h1 * h1);
			double BjkH0ToH1 = h0 * (*b)(x, t) / h1;

			if ((k == (NodesWidth - 1)) && j == (NodesHeight-2))
			{
				double Vjp1k = Nodes[k][j + 1];
				double Vjk = Nodes[k][j];
				double vjm1k = Nodes[k][j - 1];
			}
			Nodes[k - 1][j] = Nodes[k][j] * (1 - AjkH0ToH1Square - BjkH0ToH1 - h0 * (*r)(x, t))
							+ Nodes[k][j + 1] * (BjkH0ToH1 + 0.5*AjkH0ToH1Square)
							+ Nodes[k][j - 1] * (0.5 * AjkH0ToH1Square)
							+ h0 * (*f)(x, t);
		}
	}
}