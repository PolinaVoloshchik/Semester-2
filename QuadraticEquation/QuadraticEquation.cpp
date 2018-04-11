#include "stdafx.h"
#include "QuadraticEquation.h"
#include <iostream>
#include <stdexcept>

using namespace std;

QuadraticEquation::QuadraticEquation(int a, int b, int c)
{
	SetCoefficients(a, b, c);
}

void QuadraticEquation::SetCoefficients(int a, int b, int c)
{
	SetCoeffA(a);
	SetCoeffB(b);
	SetCoeffC(c);
}

int QuadraticEquation::GetCoeffA()
{
	return coeffA;
}

int QuadraticEquation::GetCoeffB()
{
	return coeffB;
}

int QuadraticEquation::GetCoeffC()
{
	return coeffC;
}

void QuadraticEquation::SetCoeffA(int a)
{
	if (a == 0)
	{
		throw invalid_argument("The leading coefficient can not be zero!");
	}

	coeffA = a;
}

void QuadraticEquation::SetCoeffB(int b)
{
	coeffB = b;
}

void QuadraticEquation::SetCoeffC(int c)
{
	coeffC = c;
}