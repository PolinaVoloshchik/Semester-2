#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

char* InitString(char*, int);
void CreateFile(char*, int);
int ContentsFile(char*);
void AddFile(char*, char**, int);
char** ObtainWords(char*, int&);
void FreeHeap(char**, int);
char** FindPalindromes(char**, int);


char* InitString(char* fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	char* string = new char[n];
	for (int i = 0; i < n; i++)
		//streamIn.getline >> string[i];
	streamIn >> string[i];

	streamIn.close();
	return string;
}

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

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0;
	char term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

void AddFile(char* fileName, char** words, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	streamOut << "\nPalindromes from " << fileName << ":\n";
	for (int i = 0; i < n; i++)
	{
		streamOut << i+1 << ". " << words[i] << endl;
	}
	streamOut.close();
}

char** ObtainWords(char* string, int& n)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char** words = new char*[strlen(string) / 2];

	n = 0;
	char* curword = strpbrk(string, symbols);
	while (curword)
	{
		int length = strspn(curword, symbols);
		words[n] = new char[length + 2];
		strncpy(words[n], curword, length + 1);
		words[n][length] = '\0';
		curword += length;
		curword = strpbrk(curword, symbols);
		n++;
	}

	return words;
}

void FreeHeap(char** words, int n)
{
	for (int i = 0; i < n; i++)
		delete[] words[i];
	delete[] words;
}

char** FindPalindromes(char** words, int n)
{
	char** palindromes = new char*[n];
	int m = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= strlen(words[i] + 1) / 2; j++)
		{
			if (words[i][j] == words[i][n - j - 1])
			{
				palindromes[m] = words[i];
				m++;
			}
		}

	return palindromes;
}
