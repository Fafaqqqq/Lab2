#pragma once
#include <stdexcept>
#include <cmath>

class Function
{
public:
	Function() = default;
	Function(int size);

	virtual double Ñalculate(double x) const = 0;
	virtual void CheckArgument() const = 0;
	virtual ~Function();
	double& AtFac(int index) const;

	enum BAD_ARG
	{
		ZERO,
		ONE
	};

private:
	double* _factors = nullptr;
};