#pragma once
#include <iostream>
#include<fstream>

using namespace std;

void CreateFile(char*, int);
int* InitArray(char*, int);
int ContentsFile(char*);
void AddFile(char*, int*, int);
int* MakeNewArray(int*, int&, int*, int);
void DeleteElements(int*, int&);
void RemoveElement(int*, int&, int);
int FindDifferenceBetweenUnitsAndZeros(int);
void BubbleSortOfArray(int*, int);
void Swap(int&, int&);
void DisplayArray(int*, int);


void CreateFile(char* fileName, int n)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	system("cls");

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element #" << i << ": ";
		cin >> arr[i];
		streamOut.width(5);
		streamOut << arr[i];
	}

	streamOut.close();
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];

	streamIn.close();
	return arr;
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0, term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

void AddFile(char* fileName, int* arr, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\n\nNew array!\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
}

int* MakeNewArray(int* a, int& n, int* na, int m)
{
	int j = 0;
	for (j; j < m; j++)
	{
		na[j] = 0;
	}

	for (int i = 1; i < n; i += 2)
	{
		if ((a[i] < 0) && (a[i] % 2 != 0))
		{
			na[j] = a[i];
			j++;
		}
	}

	return na;
}

void DeleteElements(int* a, int& n)
{
	for (int i = 1; i < n; i += 2)
	{
		if ((a[i] < 0) && (a[i] % 2 == -1))
		{
			RemoveElement(a, n, i);
		}
	}
}

void RemoveElement(int* array, int& n, int k)
{
	for (int i = k; i < n - 1; i++)
	{
		array[i] = array[i + 1];
	}
	n--;
}

int FindDifferenceBetweenUnitsAndZeros(int n)
{
	int u = 0, z = 0;
	n = abs(n);

	if (n == 0)
		return -1;

	for (; n; n >>= 1)
	{
		if (n & 1)
			u++;
		else z++;
	}

	return u - z;
}

void BubbleSortOfArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n + 1; j++)
		{
			int dif1 = FindDifferenceBetweenUnitsAndZeros(*(a + i));
			int dif2 = FindDifferenceBetweenUnitsAndZeros(*(a + j));
			if (dif1 < dif2)
			{
				Swap(a[i], a[j]);
			}
		}
	}
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void DisplayArray(int* a, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout.width(5);
		cout << a[i];
	}
}
