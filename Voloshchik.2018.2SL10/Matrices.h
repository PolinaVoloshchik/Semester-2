#pragma once
#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

const int C = 10;

double SinTaylor(double, double);
void InitializeMatrixSinTaylor(double**, int, int);
void InitializeMatrixSin(double**, int, int);
bool CompareMatrix(double**, double**, int, int);
double** AllocateMemory(int, int);
void FreeMemory(double**, int);
double FindBiggestDifference(double**, double**, int, int);
double RoundTo(double, int);
void AddFile(char*, double**, int);
void Result(char*, bool);



double SinTaylor(double x, double eps)
{
	double term = x, sum = 0;
	for (int i = 1; fabs(term) > eps; i++)
	{
		sum += term;
		term = -term * x * x / (2 * i) / (2 * i + 1);
	}
	return sum;
}

void InitializeMatrixSinTaylor(double** matrix, int n, int m)
{
	double eps = 0.001;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 2 * j)
				matrix[i][j] = RoundTo((SinTaylor(2 * i * j, eps) + SinTaylor(i, eps)) / (pow(i - j - 4, 3) + pow(i + j, 2)), C);
			else
				matrix[i][j] = i;
		}
	}
}

void InitializeMatrixSin(double** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 2 * j)
				matrix[i][j] = RoundTo((sin(2 * i * j) + sin(i)) / (pow(i - j - 4, 3) + pow(i + j, 2)), C);
			else
				matrix[i][j] = i;
		}
	}
}

bool CompareMatrix(double** a, double** b, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != b[i][j])
				return false;
		}
	}

	return true;
}

double** AllocateMemory(int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	double** a = new double*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[m];
	}

	return a;
}

void FreeMemory(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}

double FindBiggestDifference(double** a, double** b, int n, int m)
{
	double maxdif = RoundTo(abs(a[0][0] - b[0][0]), C);

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			double dif = RoundTo(abs(a[i][j] - b[i][j]), C);
			if (dif > maxdif)
				maxdif = dif;
		}
	}

	return maxdif;
}

double RoundTo(double x, int c)
{
	if (x > 0)
	{
		x = x*pow(10, c + 1);

		int x1 = trunc(x);
		if (x1 % 10 < 5)
			x = (x1 - (x1 % 10)) / pow(10, c + 1);
		else
			x = (x1 + 10 - (x1 % 10)) / pow(10, c + 1);

		return x;
	}
	else
	{
		x = abs(x*pow(10, c + 1));

		int x1 = trunc(x);
		if (x1 % 10 < 5)
			x = (x1 - (x1 % 10)) / pow(10, c + 1);
		else
			x = (x1 + 10 - (x1 % 10)) / pow(10, c + 1);

		return -x;
	}
}

void AddFile(char* fileName, double** matrix, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	streamOut << "\n\nMatrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			streamOut.width(C + 5);
			if (matrix[i][j] == 0)
				streamOut << "0";
			else
				streamOut << matrix[i][j];
		}
		streamOut << endl;
	}

	streamOut.close();
}

void Result(char* filename, bool x)
{
	ofstream streamOut(filename, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	if (x)
		streamOut << "Matrixes are equal" << endl;
	else
		streamOut << "Matrixes aren't equal" << endl;

	streamOut.close();
}
