#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

namespace Math
{
	const int N = 50;

	LIBRARY_API void InitializeArray(int*, int);
	LIBRARY_API void DisplayArray(int*, int);
	LIBRARY_API int* AllocateMemory(int);
	LIBRARY_API void FreeMemory(int*);
	LIBRARY_API int* MakeNewArray(int*, int&, int*, int);
	LIBRARY_API void DeleteElements(int*, int&);
	LIBRARY_API void RemoveElement(int*, int&, int);
	LIBRARY_API int FindDifferenceBetweenUnitsAndZeros(int);
	LIBRARY_API void BubbleSortOfArray(int*, int);
	LIBRARY_API void Swap(int&, int&);
}