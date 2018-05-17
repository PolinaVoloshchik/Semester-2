#include "Class.h"
#include "Header.h"
#include <iostream>

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
	case 16:
		return From10ToP(n, p);
	default:
		cout << "Invalid data!" << endl;
	}
}

void Number::SetNewNumber(int n, int p)
{
	newnumber = FindNewNumberInP(n, p);
}

void Number::From10ToP(int n, int p)
{

}