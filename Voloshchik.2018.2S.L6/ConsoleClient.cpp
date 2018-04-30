#include "stdafx.h"
#include "../Integral/Integral.h"
#include <iostream>

using namespace std;
using namespace Integral;


int main()
{
	double I = 0;
	double a, b, eps;
	int n;

	cout << "Enter lower limit a = " << endl;
	cin >> a;
	cout << "Enter upper limit b = " << endl;
	cin >> b;
	cout << "Enter accuracy eps = " << endl;
	cin >> eps;
	cout << "Enter n = " << endl;
	cin >> n;

	I = FindIntegral(LeftRectangle, a, b, n);
	if (CheckAccuracy(LeftRectangle, n, eps, a, b))
	{
		cout << "Integral by LeftRectangle:" << endl << "I = " << I << endl;
	}

	I = FindIntegral(RightRectangle, a, b, n);
	if (CheckAccuracy(RightRectangle, n, eps, a, b))
	{
		cout << "Integral by RightRectangle:" << endl << "I = " << I << endl;
	}

    return 0;
}

