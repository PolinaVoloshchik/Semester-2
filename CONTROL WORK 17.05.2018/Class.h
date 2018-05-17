#ifndef number_h
#define number_h

#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class Number
{
public:
	Number(int, int) {};
	Number() {}
	void SetNumber(int);
	void SetBase(int);
	void DisplayNumber();
private:
	int number;
	int newnumber;
	int base;

	int FindNewNumberInP(int, int);
	void SetNewNumber(int, int);
	int From10ToP(int, int);
};

#endif