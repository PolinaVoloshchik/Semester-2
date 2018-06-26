#include "stdafx.h"
#include "MatrixLib.h"
#include <iostream>

using namespace std;
using namespace MatrixLib;


MATRIX_LIB_API void MatrixLib::InitializeRandomMatrix(int** matrix, int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw out_of_range("Dimensions of matrix must be more than zero!");
	}

	if (matrix == nullptr)
	{
		throw invalid_argument("Argument is null!");
	}

	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < m+1; j++)
		{
			matrix[i][j] = rand() % 50 - rand() % 50;
		}
	}
}

MATRIX_LIB_API void MatrixLib::DisplayMatrix(int** a, int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	cout << "------------------------------" << endl;

	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < m+1; j++)
		{
			cout.width(5);
			cout << a[i][j];
		}

		cout << endl;
	}
}

MATRIX_LIB_API int** MatrixLib::AllocateMemory(int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	int** a = new int*[n];
	for (int i = 1; i < n+1; i++)
	{
		a[i] = new int[m];
	}

	return a;
}

MATRIX_LIB_API void MatrixLib::FreeMemory(int** a, int n)
{
	for (int i = 1; i < n+1; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}

MATRIX_LIB_API int ** MatrixLib::CopySecondaryDiag(int ** a, int ** b, int n)
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i + j == n + 1)
				b[i][j] = a[i][j];
		}
	}

	return b;
}

MATRIX_LIB_API int MatrixLib::FindMaxElementForUpper(int** a, int k, int l, int n)
{
	int max = a[k][l];
	int c = n + 1, p = c+1;

	for(int j = l; j < c; j++, p--)
		for (int i = k; i < c-j+1; i++)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}

	return max;
}

MATRIX_LIB_API int MatrixLib::FindMaxElementForLower(int** a, int k, int l, int n)
{
	int max = a[k][l];
	int c = n - 1, p = 0;

	for (int i = k; i > n-l; i--, p++)
		for (int j = l; j > p; j--)
		{
			if (a[i][j] > max)
			max = a[i][j];
		}

	return max;
}

MATRIX_LIB_API int** MatrixLib::CreateBijForUpper(int** a, int** b, int n, int m)
{
	for(int i = 1; i < n + 1; i++)
		for (int j = m - i; j > 0; j--)
		{
			b[i][j] = FindMaxElementForUpper(a, i, j, n);
		}

	return b;
}

MATRIX_LIB_API int ** MatrixLib::CreateBijForLower(int ** a, int** b, int n, int m)
{
	for (int i = n; i > 1; i--)
		for (int j = m - i + 2; j <= m; j++)
		{
			b[i][j] = FindMaxElementForLower(a, i, j, n);
		}

	return b;
}
