#include "stdafx.h"
#include <iostream>
#include "NonrectangularMatrixes.h"

using namespace std;
using namespace Matrixes;

int main()
{
	int n = 10;
	int* m;
	int** matrix = AllocateMemory(n, m);
	InitializeMatrix(matrix, n, m);
	DisplayMatrix(matrix, n, m);
	BubbleSorting(matrix, n);
	DisplayMatrix(matrix, n, m);
	
	system("pause");
	return 0;
}

