#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

void BlockWriteFile(char*, int, int, int);
void DisplayFile(char*, int, int);
void WorkFile(char*, char*, int, int);
void DisplayMatrix(int*, int, int);
void InitMatrix(int*, int, int);
void SystemFun();
int* Multiplication(int*, int*, int, int);

int main()
{
	const int N = 40;
	char filename[N] = "", newfile[N] = "";
	cout << "\nEnter the name of file: " << endl;
	cin >> filename;
	cout << "\nEnter the name of new file: " << endl;
	cin >> newfile;

	int k, n, m;
	while (true)
	{
		cout << "\nEnter k number of matrixs:" << endl;
		cin >> k;
		cout << "\nEnter n, m dimentions of matrixs:" << endl;
		cin >> n >> m;
		if (k > 0 && n > 0 && m > 0)
			break;
		cout << "\nNumber is incorrect! Try again!" << endl;
	}
	system("cls");

	BlockWriteFile(filename, k, n, m);
	cout << "\nThe contents of file <<" << filename << ">> :" << endl;
	DisplayFile(filename, n, m);
	WorkFile(filename, newfile, n, m);
	cout << "\nThe new contents of file <<" << newfile << ">> : " << endl;
	DisplayFile(newfile, n, m);

	system("pause");
    return 0;
}


void InitMatrix(int* pointer, int n, int m)
{
	for (int i = 0; i < n * m; i++)
		pointer[i] = rand() % 10;
}

void BlockWriteFile(char* fileName, int k, int n, int m)
{
	ofstream streamOut(fileName, ios::out | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write.";
		SystemFun();
		exit(1);
	}
	int bufSize = sizeof(int) * n * m;
	int bufSize1 = sizeof(int) * m * 1;
	int* pointer = new int[n * m];
	int* pointer1 = new int[m * 1];
	for (int i = 0; i < k; i++)
	{
		InitMatrix(pointer, n, m);
		streamOut.write((char*)pointer, bufSize);
		InitMatrix(pointer1, m, 1);
		streamOut.write((char*)pointer1, bufSize1);
	}
	delete[] pointer;
	delete[] pointer1;
	streamOut.close();
}

void DisplayFile(char* fileName, int n, int m)
{
	ifstream streamIn(fileName, ios::in | ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read.";
		SystemFun();
		exit(1);
	}
	int bufSize = sizeof(int) * n * m, bufSize1 = sizeof(int) * m * 1, counter = 0;
	int* pointer = new int[n * m];
	int* pointer1 = new int[m * 1];
	while (streamIn.read((char*)pointer, bufSize))
	{
		cout << endl << counter + 1 << "'s  matrix " << endl;
		DisplayMatrix(pointer, n, m);
		DisplayMatrix(pointer1, m, 1);
		counter++;
	}
	delete[] pointer;
	delete[] pointer1;
	streamIn.close();
}

void DisplayMatrix(int* pointer, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(4);
			cout << pointer[i * m + j];
		}
		cout << endl;
	}
}

void WorkFile(char* fileName, char* newfile, int n, int m)
{
	fstream streamIn(fileName, ios::in | ios::binary);
	fstream streamOut(newfile, ios::out | ios::binary);
	if (!streamIn.is_open() || !streamOut.is_open())
	{
		cout << "Can't open file.";
		SystemFun();
		exit(1);
	}
	int* pointer = new int[n * m];
	int* pointer1 = new int[m * 1];
	int bufSize = sizeof(int) * n * m;
	int bufSize1 = sizeof(int) * m * 1;
	int* result = new int[n * 1];
	int resultsize = sizeof(int) * n * 1;
	while (streamIn.read((char*)pointer, bufSize) && streamIn.read((char*)pointer1, bufSize1))
	{
		result = Multiplication(pointer, pointer1, n, m);
		streamOut.write((char*)result, resultsize);
	}
	delete[] pointer;
	delete[] pointer1;
	streamIn.close();
	streamOut.close();
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

int* Multiplication(int* m1, int* m2, int n, int m)
{
	int* result = new int[n * 1];
	for (int i = 0; i < n; i++)
	{
		int term = 0;
		for (int j = 0, k = 0; j < m, k < n; j++, k++)
		{
				term += m1[i*m+j] * m2[k];
		}
		result[i] = term;
	}

	return result;
}

