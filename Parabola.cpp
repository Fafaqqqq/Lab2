#include "Parabola.h"
#define PAR_FAC 3

Parabola::Parabola(double a, double b, double c)
	: Function(PAR_FAC)
{
	AtFac(0) = a;
	AtFac(1) = b;
	AtFac(2) = c;
}

double Parabola::Ñalculate(double x) const 
{
	 return AtFac(0) * pow(x, 2) + AtFac(1) * x + AtFac(2);
}

void Parabola::CheckArgument() const {}

