#pragma once
#include <iostream>

using namespace std;

class QuadraticEquation
{
public:
	QuadraticEquation(int = 1, int = 1, int = 1);
	void SetCoefficients(int, int, int);
	int GetCoeffA();
	int GetCoeffB();
	int GetCoeffC();
private:
	int coeffA{ 1 };
	int coeffB{ 1 };
	int coeffC{ 1 };
	void SetCoeffA(int);
	void SetCoeffB(int);
	void SetCoeffC(int);
};