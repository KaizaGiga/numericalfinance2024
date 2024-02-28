#pragma once
class R2R1Function
{
public:
	R2R1Function();
	~R2R1Function();
	virtual double operator()(double x, double t) = 0;
};

class NullFunction : public R2R1Function
{
public:
	NullFunction();
	double operator()(double x, double t);
};

class BSActualization : public R2R1Function
{
private:
	double Rate;

public:
	BSActualization(double rate);
	double operator()(double x, double t);
};

class BSVariance : public R2R1Function
{
private:
	double Sigma;

public:
	BSVariance(double sigma);
	double operator()(double x, double t);
};

class BSTrend : public R2R1Function
{
private:
	double Rate;

public:
	BSTrend(double rate);
	double operator()(double x, double t);
};