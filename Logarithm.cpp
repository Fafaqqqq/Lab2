#include "Logarithm.h"
#define BASE_ARG 1
#define BASE 0

Logarithm::Logarithm(double a)
	: Function(BASE_ARG)
{
	AtFac(BASE) = a;
}

double Logarithm::Ñalculate(double x) const
{
	if (x <= BAD_ARG::ZERO)
	{
		throw std::invalid_argument("The parameter is less than or equal to zero");
	}

	return std::log(x) / std::log(AtFac(BASE));
}

void Logarithm::CheckArgument() const
{
	if (AtFac(BASE) == BAD_ARG::ONE)
	{
		throw std::invalid_argument("The base is equal to one!");
	}

	if (AtFac(BASE) <= BAD_ARG::ZERO)
	{
		throw std::invalid_argument("Base less than or equal to zero");
	}
}