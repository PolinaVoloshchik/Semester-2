// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Library/Library.h"
#include <iostream>

using namespace Math;

int main()
{
	int n;
	std::cout << "Enter the dimension of the array n = ";
	std::cin >> n;

	int* array = AllocateMemory(n);
	InitializeArray(array, n);
	std::cout << "Array:" << std::endl;
	DisplayArray(array, n);
	std::cout << std::endl;

	int m = n / 2;
	int* newarray = AllocateMemory(m);
	newarray = MakeNewArray(array, n, newarray, m);
	std::cout << "New array:" << std::endl;
	DisplayArray(newarray, m);
	std::cout << std::endl;

	DeleteElements(array, n);
	std::cout << "First array:" << std::endl;
	DisplayArray(array, n);
	std::cout << std::endl;

	std::cout << "Sorted first array:" << std::endl;
	BubbleSortOfArray(array, n);
	DisplayArray(array, n);
	std::cout << std::endl;

	system("pause");

	return 0;
}

