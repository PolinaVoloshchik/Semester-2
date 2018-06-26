// Library.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Library.h"
#include <stdexcept>
#include <iostream>

using namespace Math;

LIBRARY_API int* Math::AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension must be more than zero!");
	}

	int* a = new int[n];

	return a;
}

LIBRARY_API void Math::FreeMemory(int* a)
{
	delete[] a;
}

LIBRARY_API void Math::InitializeArray(int* a, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int* p = a; p < a + n; p++)
	{
		*p = rand() % 10 - rand() % 10;
	}
}

LIBRARY_API void Math::DisplayArray(int* a, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int* p = a; p < a + n; p++)
	{
		std::cout << *p << " ";
	}
}

LIBRARY_API int* Math::MakeNewArray(int* a, int& n, int* na, int m)
{
	int j = 0;
	for (j; j < m; j++)
	{
		*(na+j) = 0;
	}

	for (int i = 1; i < n; i += 2)
	{
		if ((a[i] < 0) && (a[i] % 2 != 0))
		{
			na[j] = a[i];
			j++;
		}
	}

	return na;
}

LIBRARY_API void Math::DeleteElements(int* a, int& n)
{
	for (int i = 1; i < n; i += 2)
	{
		if ((a[i] < 0) && (a[i] % 2 == -1))
		{
			RemoveElement(a, n, i);
		}
	}
}

LIBRARY_API void Math::RemoveElement(int* array, int& n, int k)
{
	for (int i = k; i < n - 1; i++)
	{
		array[i] = array[i + 1];
	}
	n--;
}

LIBRARY_API int Math::FindDifferenceBetweenUnitsAndZeros(int n)
{
	int u = 0, z = 0;
	n = abs(n);

	if (n == 0)
		return -1;

	for (; n; n >>= 1)
	{
		if (n & 1)
			u++;
		else z++;
	}

	return u - z;
}

LIBRARY_API void Math::BubbleSortOfArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n+1; j++)
		{
			int dif1 = FindDifferenceBetweenUnitsAndZeros(*(a + i));
			int dif2 = FindDifferenceBetweenUnitsAndZeros(*(a + j));
			if (dif1 < dif2)
			{
				Swap(a[i], a[j]);
			}
		}
	}
}

LIBRARY_API void Math::Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}