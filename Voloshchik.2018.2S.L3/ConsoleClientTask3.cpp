#include "stdafx.h"
#include <iostream>
#include "../MatrixLib/MatrixLib.h"

using namespace std;
using namespace MatrixLib;


int main()
{
	int n = 5, m = 5;

	int** matrixA = AllocateMemory(n, m);
	int** matrixB = AllocateMemory(n, m);

	InitializeRandomMatrix(matrixA, n, m);
	matrixB = CreateBijForUpper(matrixA, matrixB, n, m);
	matrixB = CreateBijForLower(matrixA, matrixB, n, m);
	matrixB = CopySecondaryDiag(matrixA, matrixB, n);

	DisplayMatrix(matrixA, n, m);
	DisplayMatrix(matrixB, n, m);

	system("pause");

    return 0;
}

