// MatrixLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Matrix.h"
#include <cmath>
#include <iostream>

using namespace Matrix;
using namespace std;

const int C = 10;

MATRIX_LIBRARY_API double Matrix::SinTaylor(double x, double eps)
{
	double term = x, sum = 0;
	for (int i = 1; fabs(term) > eps; i++)
	{
		sum += term;
		term = -term * x * x / (2 * i) / (2 * i + 1);
	}
	return sum;
}

MATRIX_LIBRARY_API void Matrix::InitializeRandomMatrix(double** matrix, int n, int m)
{
	if (n <= 0 || m<=0)
	{
		throw std::out_of_range("Dimensions of matrix must be more than zero!");
	}

	if (matrix == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 10 - rand() % 10;
		}
	}
}

MATRIX_LIBRARY_API void Matrix::InitializeMatrixSinTaylor(double** matrix, int n, int m)
{
	double eps = 0.001;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 2 * j)
				matrix[i][j] = RoundTo((SinTaylor(2 * i * j, eps) + SinTaylor(i, eps)) / (pow(i - j - 4, 3) + pow(i + j, 2)),C);
			else
				matrix[i][j] = i;
		}
	}
}

MATRIX_LIBRARY_API void Matrix::InitializeMatrixSin(double** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 2 * j)
				matrix[i][j] = RoundTo((sin(2 * i * j) + sin(i)) / (pow(i - j - 4, 3) + pow(i + j, 2)),C);
			else
				matrix[i][j] = i;
		}
	}
}

MATRIX_LIBRARY_API bool Matrix::CompareMatrix(double** a, double** b, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != b[i][j])
				return false;
		}
	}

	return true;
}

MATRIX_LIBRARY_API void Matrix::DisplayMatrix(double** a, int n, int m)
{
		if (n <= 0 || m <= 0)
		{
			throw std::invalid_argument("Dimentions can not be less or equal zero!");
		}

		if (a == nullptr)
		{
			throw std::invalid_argument("Pointer can not be null!");
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout.width(C+5);
				if (a[i][j] == 0)
					cout << "0";
				else 
					cout << a[i][j];
			}

			cout << endl;
		}
}

MATRIX_LIBRARY_API double** Matrix::AllocateMemory(int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	double** a = new double*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[m];
	}

	return a;
}

MATRIX_LIBRARY_API void Matrix::FreeMemory(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}

MATRIX_LIBRARY_API double Matrix::FindBiggestDifference(double** a, double** b, int n, int m)
{
	double maxdif = RoundTo(abs(a[0][0] - b[0][0]),C);

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			double dif = RoundTo(abs(a[i][j] - b[i][j]),C);
			if (dif > maxdif)
				maxdif = dif;
		}
	}

	return maxdif;
}

MATRIX_LIBRARY_API double Matrix::RoundTo(double x, int c)
{
	if (x > 0)
	{
		x = x*pow(10, c + 1);

		int x1 = trunc(x);
		if (x1 % 10 < 5)
			x = (x1 - (x1 % 10)) / pow(10, c + 1);
		else
			x = (x1 + 10 - (x1 % 10)) / pow(10, c + 1);

		return x;
	}
	else
	{
		x = abs(x*pow(10, c + 1));

		int x1 = trunc(x);
		if (x1 % 10 < 5)
			x = (x1 - (x1 % 10)) / pow(10, c + 1);
		else
			x = (x1 + 10 - (x1 % 10)) / pow(10, c + 1);

		return -x;
	}
}