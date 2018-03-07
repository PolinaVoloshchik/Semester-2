#include "stdafx.h"
#include "../MatrixLibrary/Matrix.h"
#include <iostream>

using namespace Matrix;
using namespace std;


int main()
{
	int n = 3, m = 3;

	double** m1 = AllocateMemory(n, m);
	double** m2 = AllocateMemory(n, m);

	InitializeMatrixSinTaylor(m1, n, m);
	cout << "Matrix by SinTaylor:" << endl;
	DisplayMatrix(m1, n, m);
	InitializeMatrixSin(m2, n, m);
	cout << "Matrix by Sin:" << endl;
	DisplayMatrix(m2, n, m);

	bool result = CompareMatrix(m1, m2, n, m);

	if (result)
		cout << "Matrixes are equal" << endl;
	else
		cout << "Matrixes aren't equal" << endl;
	
	double md = FindBiggestDifference(m1, m2, n, m);
	cout << "The biggest difference is " << md << endl;

	FreeMemory(m1, n);
	FreeMemory(m2, n);

	system("pause");

    return 0;
}

