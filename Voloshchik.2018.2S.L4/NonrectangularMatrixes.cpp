#include "stdafx.h"
#include <iostream>
#include "NonrectangularMatrixes.h"

using namespace std;
using namespace Matrixes;

//NONRECTANGULAR_MATRIXES_API void Matrixes::DisplayMatrix(int** a, int n, int m)
//{
//	if (n <= 0 || m <= 0)
//	{
//		throw std::invalid_argument("Dimentions can not be less or equal zero!");
//	}
//
//	if (a == nullptr)
//	{
//		throw std::invalid_argument("Pointer can not be null!");
//	}
//
//	cout << "------------------------------" << endl;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout.width(5);
//			cout << a[i][j];
//		}
//
//		cout << endl;
//	}
//}
//
//NONRECTANGULAR_MATRIXES_API int ** Matrixes::AllocateMemory(int n, int m)
//{
//	if (n <= 0 || m <= 0)
//	{
//		throw std::invalid_argument("Dimentions can not be less or equal zero!");
//	}
//
//	int** a = new int*[n];
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = new int[m];
//	}
//
//	return a;
//}
//
//NONRECTANGULAR_MATRIXES_API int ** Matrixes::InitializeRandomMatrix(int ** a, int n, int m)
//{
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < rand() % (n + 1); j++)
//		{
//			a[i][j] = rand() % 50 - rand() % 50;
//		}
//}

NONRECTANGULAR_MATRIXES_API void Matrixes::FreeMemory(int** a, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}

NONRECTANGULAR_MATRIXES_API int** Matrixes::AllocateMemory(int n, int* d)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	int** a = new int*[n];

	for (size_t i = 0; i < n; i++)
	{
		a[i] = new int[d[i]];
	}

	return a;
}

NONRECTANGULAR_MATRIXES_API void Matrixes::InitializeMatrix(int** a, int n, int* d)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr || d == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < d[i]; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}

NONRECTANGULAR_MATRIXES_API void Matrixes::DisplayMatrix(int** a, int n, int* d)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr || d == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < d[i]; j++)
		{
			cout.width(4);
			cout << a[i][j];
		}

		cout << endl;
	}
}

NONRECTANGULAR_MATRIXES_API int Matrixes::FindTheBiggestElement(int* p, int n)
{
	int max = p[0];

	for (size_t i = 1; i < n; i++)
	{
		if (p[i] > max)
			max = p[i];
	}

	return max;
}

NONRECTANGULAR_MATRIXES_API void Matrixes::BubbleSorting(int** matrix, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i+1; j < n; j++)
		{
			int max1 = FindTheBiggestElement(matrix[i], n);
			int max2 = FindTheBiggestElement(matrix[j], n);

			if (max1 > max2)
				Swap(matrix[i], matrix[j]);
		}
	}
}

NONRECTANGULAR_MATRIXES_API void Matrixes::Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}



