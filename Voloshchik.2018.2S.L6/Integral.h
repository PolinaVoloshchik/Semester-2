#pragma once
#ifdef INTEGRAL_EXPORTS
#define INTEGRAL_API __declspec(dllexport)
#else
#define INTEGRAL_API __declspec(dllimport)
#endif

namespace Integral
{
	INTEGRAL_API double LeftRectangle(double, double, int);
	INTEGRAL_API double RightRectangle(double, double, int);
	INTEGRAL_API double Function(double);
	INTEGRAL_API double FindIntegral(double(*f), double, double, int);
	INTEGRAL_API bool CheckAccuracy(double(*func), int, double, double, double);
}