#pragma once
#include "Function.h"

class Parabola : public Function
{
public:
	Parabola(double a = 0., double b = 0., double c = 0.);
	
	void CheckArgument() const;
	double Ñalculate(double x) const;
};