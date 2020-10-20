#include "Hyperbola.h"
#define HYP_FAC_ARG 1
#define HYP_FAC 0

Hyperbola::Hyperbola(double a)
	: Function(HYP_FAC_ARG)
{
	AtFac(HYP_FAC) = a;
}

double Hyperbola::Ñalculate(double x) const
{
	if (x == BAD_ARG::ZERO)
	{
		throw std::invalid_argument("Division by zero!");
	}
	else
	{
		return AtFac(HYP_FAC) / x;
	}
}

void Hyperbola::CheckArgument() const {}