#pragma once
#include "Logarithm.h"
#include "Hyperbola.h"
#include "Parabola.h"

class Series
{
public:
	void Do() const;

private:
	Function* ScanAndCreate(char function) const;
	void SelectNumber(int& number) const;
	void PrintMenu() const;
	void SwitchFunction(Function** function, int number) const;
	void ScanIntervalAndStep(double& start, double& end, double& step) const;
	void PrintOnInterval(double& start, double& end, double& step, Function* function) const;
	void PrintResult(double x, double result, Function* function) const;
	void PrintErrorMessage(double x, const char* message, Function* function) const;
};