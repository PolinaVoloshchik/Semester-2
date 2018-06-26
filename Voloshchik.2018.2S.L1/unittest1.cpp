#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Library/Library.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryTests
{
	TEST_CLASS(LibraryTests)
	{
	public:

		TEST_METHOD(RemoveElement_Test1)
		{
			//Arrange
			int n = 5;
			int* ina = new int[n] { 1, 2, 3, 4, 5 };
			int k = 3;

			//Act
			Math::RemoveElement(ina, n, k);

			//Assert
			int* ear = new int[4]{ 1, 2, 3, 5 };
			Assert::AreEqual(*ear, *ina);

			delete[] ina;
			delete[] ear;
		}

		TEST_METHOD(MakeNewArray_Test1)
		{
			//Arrange
			int n = 5;
			int* a = new int[n]{ 1, -5, 3, 9, 5 };
			int* na = new int[1]{};

			//Act
			Math::MakeNewArray(a, n, na, 1);

			//Assert
			int* ea = new int[1]{ -5 };
			for (int i = 0; i<2 ; i++)
			{
				Assert::AreEqual(na[i], ea[i], L"Test failed");
			}

			delete[] a;
			delete[] na;
			delete[] ea;
		}

		TEST_METHOD(MakeNewArray_Test2)
		{
			//Arrange
			int n = 7;
			int* a = new int[n] { -1, 7, 8, 0, -15, 11, 2 };
			int* na = new int[0]{};

			//Act
			Math::MakeNewArray(a, n, na, 0);

			//Assert
			int* ea = new int[0]{};
			for (int i = 0; i<1; i++)
			{
				Assert::AreEqual(na[i], ea[i], L"Test failed");
			}


			delete[] a;
			delete[] na;
			delete[] ea;
		}

		TEST_METHOD(MakeNewArray_Test3)
		{
			//Arrange
			int n = 10;
			int* a = new int[n] { 2, 0, -4, -3, 9, 6, 5, -15, 23, -1};
			int* na = new int[3]{};

			//Act
			Math::MakeNewArray(a, n, na, 3);

			//Assert
			int* ea = new int[3]{ -3, -15, -1 };
			for (int i = 0; i<3; i++)
			{
				Assert::AreEqual(na[i], ea[i], L"Test failed");
			}


			delete[] a;
			delete[] na;
			delete[] ea;
		}

		TEST_METHOD(FindDifferenceBetweenUnitsAndZeros_Test1)
		{
			int x = 8;

			int actual = Math::FindDifferenceBetweenUnitsAndZeros(x);

			int exp = -2;
			Assert::IsTrue(exp == actual);
		}

		TEST_METHOD(FindDifferenceBetweenUnitsAndZeros_Test2)
		{
			int x = 14;

			int actual = Math::FindDifferenceBetweenUnitsAndZeros(x);

			int exp = 2;
			Assert::IsTrue(exp == actual);
		}

		TEST_METHOD(FindDifferenceBetweenUnitsAndZeros_Test3)
		{
			int x = 2;

			int actual = Math::FindDifferenceBetweenUnitsAndZeros(x);

			int exp = 0;
			Assert::IsTrue(actual == exp);
		}

		TEST_METHOD(FindDifferenceBetweenUnitsAndZeros_Test4)
		{
		int x = -4;

		int actual = Math::FindDifferenceBetweenUnitsAndZeros(x);

		int exp = -1;
		Assert::IsTrue(exp == actual);
		}

		TEST_METHOD(FindDifferenceBetweenUnitsAndZeros_Test5)
		{
		int x = 0;

		int actual = Math::FindDifferenceBetweenUnitsAndZeros(x);

		int exp = -1;
		Assert::AreEqual(exp, actual);
		}

		TEST_METHOD(BubbleSortOfArray_Test1)
		{
			int n = 3;
			int* a = new int[n] {2, 14, 8};

			Math::BubbleSortOfArray(a, n);

			int* exp = new int[n] {14, 2, 8};
			Assert::AreEqual(*a, *exp);
		}

		TEST_METHOD(BubbleSortOfArray_Test2)
		{
			int n = 7;
			int* a = new int[n] { 10, 7, 4, 0, 5, 16, 11};

			Math::BubbleSortOfArray(a, n);

			int* exp = new int[n] { 7, 11, 5, 10, 4, 16, 0 };
			Assert::AreEqual(*a, *exp);
		}

		TEST_METHOD(BubbleSortOfArray_Test3)
		{
		int n = 8;
		int* a = new int[n] { 10, 7, -6, 0, 5, 16, 11, -12};

		Math::BubbleSortOfArray(a, n);

		int* exp = new int[n] { 7, 11, 5, 10, -6, -12, 16, 0 };
		Assert::AreEqual(*a, *exp);
		}

		TEST_METHOD(DeleteElements_Test1)
		{
			int n = 3;
			int* a = new int[n] {0, -3, 8};

			Math::DeleteElements(a, n);

			int* ea = new int[2] { 0, 8 };
			Assert::AreEqual(*a, *ea);
		}

		TEST_METHOD(DeleteElements_Test2)
		{
			int n = 7;
			int* a = new int[n] {0, -3, 8, -1, -9, -7, -13};

			Math::DeleteElements(a, n);

			int* ea = new int[4]{ 0, 8, -9, -13 };
			Assert::AreEqual(*a, *ea);
		}

		TEST_METHOD(MAIN_Test)
		{
			int n = 5;
			int* array = new int[n] {9, 3, 5, -7, 27};
			int* del = new int[1]{};

			del = Math::MakeNewArray(array, n, del, 1);
			Math::DeleteElements(array, n);
			Math::BubbleSortOfArray(array, n);

			int* delexp = new int[1]{ -7 };
			int* arrayexp = new int[4]{ 27,3,5,9 };

			Assert::AreEqual(*del, *delexp);
			Assert::AreEqual(*array, *arrayexp);
		}

	};
}