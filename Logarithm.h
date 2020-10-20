#pragma once
#include "Function.h"

class Logarithm : public Function
{
public:
	Logarithm(double a = 2.);

	void CheckArgument() const;
	double Ñalculate(double x) const;
};