#include "stdafx.h"
#include "../Strings/Strings.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace Strings;

int main()
{
	const int C = 500;
	char* text = new char[C];

	cout << "Enter text:" << endl;
	cin.getline(text, C);

	int n;
	char** words = ObtainWords(text, n);
	cout << endl << "------WORDS------" << endl;
	DisplayWords(words, n);

	char** palindromes = FindPalindromes(words, n);
	cout << endl << "------PALINDROMES------" << endl;
	DisplayWords(palindromes, n);

	FreeHeap(words, n);

	system("pause");

    return 0;
}

