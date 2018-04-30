#include "stdafx.h"
#include "Integral.h"
#include <iostream>

using namespace std;

INTEGRAL_API double Integral::LeftRectangle(double lowLimit, double upLimit, int n)
{
	double integral = 0;
	double h = (upLimit - lowLimit) / n;
	double term = 0;
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		term = lowLimit + i*h;
		sum += Function(term);
	}

	integral = h*sum;
	return integral;
}

INTEGRAL_API double Integral::RightRectangle(double lowLimit, double upLimit, int n)
{
	double integral = 0;
	double h = (upLimit - lowLimit) / n;
	double term = 0;
	double sum = 0;

	for (int i = 0; i < n + 1; i++)
	{
		term = lowLimit + i*h;
		sum += Function(term);
	}

	integral = h*sum;
	return integral;
}

INTEGRAL_API double Integral::Function(double x)
{
	return 1/(1+x);
}

INTEGRAL_API double Integral::FindIntegral(double (*func), double lowLimit, double upLimit, int n)
{
	return *func(lowLimit, upLimit, n);
}

INTEGRAL_API bool Integral::CheckAccuracy(double (*func), int n, double eps, double lowLimit, double upLimit)
{
	double i1 = FindIntegral(func,lowLimit, upLimit, n);
	double i2 = FindIntegral(func, lowLimit, upLimit, 2*n);

	if (abs(i1 - i2) < eps)
		return true;
	else
	{
		n = n * 2;
		CheckAccuracy(func, n, eps, lowLimit, upLimit);
	}
}
