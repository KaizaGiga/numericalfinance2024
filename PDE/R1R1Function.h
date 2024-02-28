#pragma once
class R1R1Function
{
public:
	R1R1Function();
	~R1R1Function();
	virtual double operator()(double x) = 0;

};

/*  VANILLA OPTIONS */

class VanillaTerminalCondition : public R1R1Function
{
protected:
	double Strike;

public:
	VanillaTerminalCondition(double strike);
};

// CALL Option

class CallTerminalCondition : public VanillaTerminalCondition
{
public:
	CallTerminalCondition(double strike);
	double operator()(double x);
};

class CallTopBoundary : public R1R1Function
{
private:
	double SMax;
	double Strike;

public:
	CallTopBoundary(double sMax, double strike);
	double operator()(double t);
};

class CallBottomBoundary : public R1R1Function
{
private:
	double SMin;
	double Strike;

public:
	CallBottomBoundary(double sMin, double strike);
	double operator()(double t);
};

// PUT Option

class PutTerminalCondition : public VanillaTerminalCondition
{
public:
	PutTerminalCondition(double strike);
	double operator()(double x);
};

class PutTopBoundary : public R1R1Function
{
private:
	double SMax;
	double Strike;

public:
	PutTopBoundary(double sMax, double strike);
	double operator()(double t);
};

class PutBottomBoundary : public R1R1Function
{
private:
	double SMin;
	double Strike;

public:
	PutBottomBoundary(double sMin, double strike);
	double operator()(double t);
};