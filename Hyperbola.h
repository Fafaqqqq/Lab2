#pragma once
#include "Function.h"

class Hyperbola : public Function
{
public:
	Hyperbola(double a = 0.);

	void CheckArgument() const;
	double Ñalculate(double x) const;
};