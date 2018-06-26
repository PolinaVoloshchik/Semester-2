#include "stdafx.h"
#include "Strings.h"
#include <iostream>

using namespace std;
using namespace Strings;


STRINGS_API char** Strings::ObtainWords(char* string, int & n)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char** words = new char*[strlen(string) / 2];

	n = 0;
	char* curword = strpbrk(string, symbols); //возвращает указатель первого вхождения любого символа строки symbols в строке string
	while (curword)
	{
		int length = strspn(curword, symbols);//возвращает длину начального сегмента строки curword, содержащего только те символы, которые входят в строку symbols
		words[n] = new char[length + 2];
		strncpy(words[n], curword, length+1);//выполняет побайтное копирование length+1 символов из строки  curword в строку words[n]. возвращает значения words[n]
		words[n][length] = '\0';
		curword += length;
		curword = strpbrk(curword, symbols);
		n++;
	}

	return words;
}

STRINGS_API void Strings::DisplayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
		cout << (i + 1) << ". " << words[i] << endl;
}

STRINGS_API void Strings::FreeHeap(char** words, int n)
{
	for (int i = 0; i < n; i++)
		delete[] words[i];
	delete[] words;
}

STRINGS_API char** Strings::FindPalindromes(char** words, int n)
{
	char** palindromes = new char*[n];
	int m = 0;

	for(int i = 0; i < n; i++)
		for (int j = 0; j <= strlen(words[i] + 1)/2; j++)
		{
			if (words[i][j] == words[i][n - j - 1])
			{
				palindromes[m] = words[i];
				m++;
			}
		}

	return palindromes;
}
