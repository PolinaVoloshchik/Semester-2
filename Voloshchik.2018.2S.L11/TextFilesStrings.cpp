#include "stdafx.h"
#include "Strings.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	char* name = "text.txt";
	char* newname = "result.txt";
	int k = ContentsFile(name);
	char* text = InitString(name, k);
	int n = 0;
	char** words = ObtainWords(text, n);
	char** palindromes = FindPalindromes(words, n);
	AddFile(newname, words, n);
	FreeHeap(words, n);
	FreeHeap(palindromes, n);

	system("pause");
    return 0;
}

