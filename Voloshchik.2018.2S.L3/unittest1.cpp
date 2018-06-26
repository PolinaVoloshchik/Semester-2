#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MatrixLib/MatrixLib.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace MatrixLib;

namespace MatrixLibTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CopySecondaryDiag_Test1)
		{
			const int C = 3;
			int** m1 = MatrixLib::AllocateMemory(C, C);
			int** m2 = MatrixLib::AllocateMemory(C, C);

			InitializeRandomMatrix(m1, C, C);
			**m2 = { 0 };
			m2 = MatrixLib::CopySecondaryDiag(m1, m2, C);

			for (int i = 0; i < C; i++)
				for (int j = 0; j < C; j++)
					if (i + j == C + 1)
						Assert::AreEqual(m1[i][j], m2[i][j]);

			MatrixLib::FreeMemory(m1, C);
			MatrixLib::FreeMemory(m2, C);
		}
	};
}