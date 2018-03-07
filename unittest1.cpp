#include "stdafx.h"
#include "CppUnitTest.h"
#include "Matrix.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Matrix;

namespace MatrixTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(RoundTo_Test1)
		{
			double x = 2.439;
			int c = 1;

			double y = Matrix::RoundTo(x, c);

			double exp = 2.4;
			Assert::AreEqual(y, exp);
		}

		TEST_METHOD(RoundTo_Test2)
		{
			double x = 1.45916;
			int c = 2;

			double y = Matrix::RoundTo(x, c);

			double exp = 1.46;
			Assert::AreEqual(y, exp);
		}

		TEST_METHOD(RoundTo_Test3)
		{
			double x = 4.19;
			int c = 0;

			double y = Matrix::RoundTo(x, c);

			double exp = 4;
			Assert::AreEqual(y, exp);
		}

		TEST_METHOD(RoundTo_Test4)
		{
			double x = -1.33485;
			int c = 3;

			double y = Matrix::RoundTo(x, c);

			double exp = -1.335;
			Assert::AreEqual(y, exp);
		}

		TEST_METHOD(RoundTo_Test5)
		{
			double x = -0.31246;
			int c = 2;

			double y = Matrix::RoundTo(x, c);

			double exp = -0.31;
			Assert::AreEqual(y, exp);
		}

		TEST_METHOD(RoundTo_Test6)
		{
			double x = -0.0124;
			int c = 1;

			double y = Matrix::RoundTo(x, c);

			double exp = 0;
			Assert::AreEqual(y, exp);
		}

		TEST_METHOD(FindBiggestDifference_Test1)
		{
			int n = 3, m = 3;
			double** m1 = Matrix::AllocateMemory(n, m);
			double** m2 = Matrix::AllocateMemory(n, m);

			for (int i = 0; i < n; i++)
			{
				**(m1 + i) = i + 1;
			}

			for (int i = 0; i < n; i++)
			{
				**(m2 + i) = 10 - i - 1;
			}

			double dif = Matrix::FindBiggestDifference(m1, m2, n, m);

			double expdif = 8;
			Assert::AreEqual(dif, expdif);
		}

	};
}