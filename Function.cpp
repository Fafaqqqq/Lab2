#include "Function.h"

Function::Function(int size)
	: _factors(new double[size]) {}

Function::~Function()
{
	if (_factors)
	{
		delete[] _factors;
	}
}

double& Function::AtFac(int index) const 
{
	return _factors[index];
}