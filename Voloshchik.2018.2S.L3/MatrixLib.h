#pragma once

#ifdef MATRIX_LIB_EXPORTS
#define MATRIX_LIB_API __declspec(dllexport)
#else
#define MATRIX_LIB_API __declspec(dllimport)
#endif

namespace MatrixLib
{
	MATRIX_LIB_API void InitializeRandomMatrix(int**, int, int);
	MATRIX_LIB_API void DisplayMatrix(int**, int, int);
	MATRIX_LIB_API int** AllocateMemory(int, int);
	MATRIX_LIB_API void FreeMemory(int**, int);
	MATRIX_LIB_API int** CopySecondaryDiag(int**, int**, int);
	MATRIX_LIB_API int FindMaxElementForUpper(int**, int, int, int);
	MATRIX_LIB_API int FindMaxElementForLower(int**, int, int, int);
	MATRIX_LIB_API int** CreateBijForUpper(int**, int**, int, int);
	MATRIX_LIB_API int** CreateBijForLower(int**, int**, int, int);
}