#include "Series.h"
#include "Scanner.h"
#include <typeinfo>
#include <iostream>

void Series::Do() const
{
	Function* FunctionPointer = nullptr;

	int number = INT_MAX;

	while (number)
	{

		SelectNumber(number);

		if (!number)
		{
			break;
		}

		SwitchFunction(&FunctionPointer, number);

		try 
		{
			FunctionPointer->CheckArgument();
		}
		catch (const std::exception& err)
		{
			std::cerr << err.what() << std::endl;
			system("pause");
			system("cls");
			continue;
		}

		double start, end;
		double step = -1;

		ScanIntervalAndStep(start, end, step);

		PrintOnInterval(start, end, step, FunctionPointer);

		std::cout << std::endl;

		system("pause");
		system("cls");
		delete FunctionPointer;
		FunctionPointer = nullptr;
	}
}

Function* Series::ScanAndCreate(char function) const
{
	if (function == 'P')
	{
		double factors[3];

		Scanner().Scan("%f%f%f", &factors[0], &factors[1], &factors[2]);

		return new Parabola(factors[0], factors[1], factors[2]);
	}

	if (function == 'L')
	{
		double factor;

		Scanner().Scan("%f", &factor);

		return new Logarithm(factor);
	}

	if (function == 'H')
	{
		double factor;

		Scanner().Scan("%f", &factor);

		return new Hyperbola(factor);
	}

	throw std::logic_error("Uncorrect argument!");
}

void Series::SelectNumber(int& number) const
{
	bool condition = true;

	while (condition)
	{
		try
		{
			PrintMenu();

			Scanner().Scan("%d", &number);

			condition = number != 0 && number != 1 && number != 2 && number != 3;

			if (condition)
			{
				std::cout << "Repeat please!\n\n";
			}
		}
		catch (const std::exception& err)
		{
			std::cerr << err.what() << std::endl;
			std::cout << "Repeat please!\n\n";
		}
	}
}

void Series::PrintMenu() const
{
	std::cout << "1. Hyperbola\n";
	std::cout << "2. Logarithm\n";
	std::cout << "3. Parabola\n";
	std::cout << "0. Exit\n";
	std::cout << "Select function: ";
}

void Series::SwitchFunction(Function** function, int number) const
{
	switch (number)
	{
	case 1:
	{
		bool scanFlag = false;

		std::cout << "\nEnter a factor of Hyperbola (One number): ";

		while (!scanFlag)
		{
			try
			{
				*function = ScanAndCreate('H');

				scanFlag = true;
				std::cout << std::endl;
			}
			catch (const std::exception& err)
			{
				std::cerr << err.what() << std::endl;
				std::cout << "Repeat please!\n";
				std::cout << "Your factor: ";
			}
		}
	}
	break;
	case 2:
	{
		bool scanFlag = false;

		std::cout << "\nEnter a base of the Logarithm (One number): ";

		while (!scanFlag)
		{
			try
			{

				*function = ScanAndCreate('L');

				scanFlag = true;
				std::cout << std::endl;
			}
			catch (const std::exception& err)
			{
				std::cerr << err.what() << std::endl;
				std::cout << "Repeat please!\n";
				std::cout << "Your factor: ";
			}
		}
	}
	break;
	case 3:
	{
		bool scanFlag = false;

		std::cout << "\nEnter a factor of Parabola(Three numbers separated by a space. Example: 1 2 3): ";

		while (!scanFlag)
		{
			try
			{
				*function = ScanAndCreate('P');

				scanFlag = true;
				std::cout << std::endl;
			}
			catch (const std::exception& err)
			{
				std::cerr << err.what() << std::endl;
				std::cout << "Repeat please!\n";
				std::cout << "Your factor: ";
			}
		}
	}
	break;
	default:
		break;
	}
}

void Series::ScanIntervalAndStep(double& start, double& end, double& step) const
{
	std::cout << "Enter an interval value.\n";

	while (true) {
		try
		{

			std::cout << "Start: ";
			Scanner().Scan("%f", &start);

			std::cout << "End: ";
			Scanner().Scan("%f", &end);

			std::cout << "Enter a step: ";
			Scanner().Scan("%f", &step);

			if (step > 0 && start <= end)
			{
				break;
			}
			else
			{
				std::cout << "Uncorrect value!\n";
				std::cout << "Repeat please!\n\n";
			}
		}
		catch (const std::exception& err)
		{
			std::cerr << err.what() << std::endl;

			std::cout << "Repeat please!\n\n";
		}
	}

}

void Series::PrintOnInterval(double& start, double& end, double& step, Function* function) const
{
	std::cout << std::endl;
	std::string name = typeid(*function).name();
	name.erase(0, 6);

	for (double x = start; x <= end; x += step)
	{
		try
		{
			/*double result = function->Ñalculate(x);
			std::cout << name << "(" << x << ") = " << result << ";\n";*/

			PrintResult(x, function->Ñalculate(x), function);
		}
		catch (const std::exception& err)
		{
			//std::cerr << name << "(" << x << ") = " << err.what() << std::endl;
			PrintErrorMessage(x, err.what(), function);
		}
	}
}

void Series::PrintResult(double x, double result, Function* function) const
{
	std::string name = typeid(*function).name();
	name.erase(0, 6);

	
	if (name == "Hyperbola")
	{
		std::cout << name << "( " << function->AtFac(0) << "/x ) = " << result << ", where x = " << x << std::endl;
	}
	
	if (name == "Logarithm")
	{
		std::cout << name << "( Log" << function->AtFac(0) << "(x) ) = " << result << ", where x = " << x << std::endl;
	}

	if (name == "Parabola")
	{
		std::cout << name << "( " << function->AtFac(0) <<"*x^2 + " << function->AtFac(1) <<"*x + " << function->AtFac(2) << " ) = " << result << ", where x = " << x << std::endl;
	}
}

void Series::PrintErrorMessage(double x, const char* message, Function* function) const
{
	std::string name = typeid(*function).name();
	name.erase(0, 6);

	if (name == "Hyperbola")
	{
		std::cout << name << "( " << function->AtFac(0) << "/x ) = " << message << ", where x = " << x << std::endl;
	}

	if (name == "Logarithm")
	{
		std::cout << name << "( Log" << function->AtFac(0) << "(x) ) = " << message << ", where x = " << x << std::endl;
	}
}