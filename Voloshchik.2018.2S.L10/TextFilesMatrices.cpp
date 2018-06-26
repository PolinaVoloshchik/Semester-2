#include "stdafx.h"
#include "Matrices.h"
#include <iostream>
#include<fstream>

using namespace std;


int main()
{
	int n = 5, m = 5;
	char* name = "test.txt";

	double** m1 = AllocateMemory(n, m);
	double** m2 = AllocateMemory(n, m);

	InitializeMatrixSin(m1, n, m);
	InitializeMatrixSinTaylor(m2, n, m);
	AddFile(name, m1, n);
	AddFile(name, m2, n);

	bool result = CompareMatrix(m1, m2, n, m);
	Result(name, result);

	FreeMemory(m1, n);
	FreeMemory(m2, n);

	system("pause");
    return 0;
}

