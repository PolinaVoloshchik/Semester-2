#include "stdafx.h"
#include "Class.h"
#include "Header.h"
#include <iostream>
#include <math.h>

using namespace std;

Number::Number(int n, int p)
{
	this->SetNumber(n);
	this->SetBase(p);
	this->SetNewNumber(n, p);
}

void Number::SetNumber(int n)
{
	number = n;
}

void Number::SetBase(int p)
{
	base = p;
}

void Number::DisplayNumber()
{
	cout << "Number:" << this->number << "/t" << "New number: " << this->newnumber << "/t" << "Base: " << this->base << endl;
}

int Number::FindNewNumberInP(int n, int p)
{
	switch (p)
	{
	case 2:
	case 8:
		return From10ToP(n, p);
	case 16:
		return (int)From10To16(n, p);
	default:
		cout << "Invalid data!" << endl;
	}
}

void Number::SetNewNumber(int n, int p)
{
	newnumber = FindNewNumberInP(n, p);
}

int Number::From10ToP(int n, int p)
{
	const int C = 25;
	int* remainders = new int[C];
	int k = 0;

	for (int i = 0; n >= p; i++)
	{
		remainders[i] = n % p;
		n /= p;
		k++;
	}
	remainders[k] = n;

	int numb = 0;
	for (int j = k; j >= 0; j--)
	{
			numb += remainders[j] * pow(10, j);
	}

	return numb;
}

char* Number::From10To16(int n, int p)
{
	const int C = 25;
	int* remainders = new int[C];
	int k = 0;

	for (int i = 0; n >= p; i++)
	{
		remainders[i] = n % p;
		n /= p;
		k++;
	}
	remainders[k] = n;

	char* numb = new char[C];
	for (int j = k; j >= 0; j--)
	{
		if (remainders[j] <= 9 && remainders[j] >= 0)
		{
			numb[k - j] = (char)remainders[j];
		}
		else
		{
			switch (remainders[j])
			{
			case 10:
				numb[k - j] = 'A';
			case 11:
				numb[k - j] = 'B';
			case 12:
				numb[k - j] = 'C';
			case 13:
				numb[k - j] = 'D';
			case 14:
				numb[k - j] = 'E';
			case 15:
				numb[k - j] = 'F';
			}
		}
	}
	return numb;
}
