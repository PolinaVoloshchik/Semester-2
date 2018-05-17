#pragma once
#include<iostream>
#include<fstream>
#include "Class.h"

using namespace std;

void CreateFile(char*, int);
int ContentsFile(char*);
void CreateBinaryFile(char*, char*);
void DisplayFile(char*);

void CreateFile(char* filename, int n)
{
	ofstream streamOut(filename);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		int temp = rand() % 50 - rand() % 50;
		streamOut << temp;
	}

	streamOut.close();
}

int ContentsFile(char* filename)
{
	ifstream streamIn(filename);

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

void CreateBinaryFile(char* binname, char* textname)
{
	ofstream streamOut;
	streamOut.open(binname, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!" << endl;
		system("pause");
		return;
	}

	int p;
	cout << "Enter base of the system p = ";
	cin >> p;

	int size = ContentsFile(textname);
	for (int i = 0; i <= size; i++)
	{
		ifstream streamIn(textname);
		int n;
		while (!streamIn.eof())
		{
			streamIn >> n;
			if (n > 0)
			{
				Number(n, p);
				ofstream streamOut(binname, ios::binary);
			}
		}
	}

	system("pause");
	streamOut.close();
}

void DisplayFile(char* binname)
{
	ifstream streamIn(binname, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		system("pause");
		return;
	}

	int size = sizeof(Number);
	Number* n = new Number;
	while (streamIn.read((char*)n, size))
	{
		n->DisplayNumber();
	}

	streamIn.close();
}
