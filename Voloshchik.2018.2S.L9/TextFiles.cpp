#include "stdafx.h"
#include "TextFiles.h"
#include <iostream>
#include<fstream>

using namespace std;

int main()
{
	char* filename = "test.txt";
	int n = ContentsFile(filename);
	int* array = InitArray(filename, n);
	DisplayArray(array, n);

	int m = n / 2;
	int* newarray = new int[m];
	newarray = MakeNewArray(array, n, newarray, m);
	DisplayArray(newarray, m);
	AddFile(filename, newarray, m);

	DeleteElements(array, n);
	BubbleSortOfArray(array, n);
	DisplayArray(array, n);
	AddFile(filename, array, n);

	system("pause");
	return 0;
}

