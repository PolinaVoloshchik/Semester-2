#pragma once
#pragma once
#ifdef MATRIX_LIBRARY_EXPORTS
#define MATRIX_LIBRARY_API __declspec(dllexport)
#else
#define MATRIX_LIBRARY_API __declspec(dllimport)
#endif

namespace Matrix
{
	MATRIX_LIBRARY_API double SinTaylor(double, double);
	MATRIX_LIBRARY_API void InitializeRandomMatrix(double**, int, int);
	MATRIX_LIBRARY_API void InitializeMatrixSinTaylor(double**, int, int);
	MATRIX_LIBRARY_API void InitializeMatrixSin(double**, int, int);
	MATRIX_LIBRARY_API bool CompareMatrix(double**, double**, int, int);
	MATRIX_LIBRARY_API void DisplayMatrix(double**, int, int);
	MATRIX_LIBRARY_API double** AllocateMemory(int, int);
	MATRIX_LIBRARY_API void FreeMemory(double**, int);
	MATRIX_LIBRARY_API double FindBiggestDifference(double**, double**, int, int);
	MATRIX_LIBRARY_API double RoundTo(double, int);
}