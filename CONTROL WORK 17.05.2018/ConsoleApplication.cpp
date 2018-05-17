#include "stdafx.h"
#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
	const int N = 50;
	char textfile[N] = "Test.txt";
	char binaryfile[N] = "Test.bin";

	int n;
	cout << "Enter number of elements of array n = ";
	cin >> n;

	CreateFile(textfile, n);
	CreateBinaryFile(binaryfile, textfile);
	DisplayFile(binaryfile);

	system("pause");
    return 0;
}

