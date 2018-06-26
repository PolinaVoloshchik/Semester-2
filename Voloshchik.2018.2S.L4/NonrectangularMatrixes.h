#pragma once
#ifdef NONRECTANGULAR_MATRIXES_EXPORTS
#define NONRECTANGULAR_MATRIXES_API __declspec(dllexport)
#else
#define NONRECTANGULAR_MATRIXES __declspec(dllimport)
#endif

namespace Matrixes
{
	/*NONRECTANGULAR_MATRIXES_API void DisplayMatrix(int**, int, int);
	NONRECTANGULAR_MATRIXES_API int** AllocateMemory(int, int);
	NONRECTANGULAR_MATRIXES_API int** InitializeRandomMatrix(int**, int, int);*/
	NONRECTANGULAR_MATRIXES_API void FreeMemory(int**, int);
	NONRECTANGULAR_MATRIXES_API int** AllocateMemory(int, int*);
	NONRECTANGULAR_MATRIXES_API void InitializeMatrix(int**, int, int*);
	NONRECTANGULAR_MATRIXES_API void DisplayMatrix(int**, int, int*);
	NONRECTANGULAR_MATRIXES_API int FindTheBiggestElement(int*, int);
	NONRECTANGULAR_MATRIXES_API void BubbleSorting(int**, int);
	NONRECTANGULAR_MATRIXES_API void Swap(int*, int*);
}