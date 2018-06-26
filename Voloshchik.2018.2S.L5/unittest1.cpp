#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Strings/Strings.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Strings;

namespace StringsTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(FindPalindromes_Test1)
		{
			int n = 5;
			char** ar = new char*[n];
			*ar = "dad";
			*(ar + 1) = "hi";
			*(ar + 2) = "fear";
			*(ar + 3) = "mum";
			*(ar + 4) = "we";

			char** pal = new char*[n];
			pal = Strings::FindPalindromes(ar, n);

			char** exppal = new char*[2];
			*pal = "dad";
			*(pal + 1) = "mum";

			for(int i = 0; i < n; i++)
				Assert::AreEqual(pal[i], exppal[i]);
		}

		TEST_METHOD(ObtainWords_Test1)
		{
			int n = 20;
			char* str = "- It is Tuesday today. - The twentyth of march? - Yes.";
			char** words = new char*[n];

			words = Strings::ObtainWords(str, n);

			char** expwords = new char*[n];
			*expwords = "It";
			*(expwords + 1) = "is";
			*(expwords + 2) = "Tuesday";
			*(expwords + 3) = "today";
			*(expwords + 4) = "The";
			*(expwords + 5) = "twentyth";
			*(expwords + 6) = "of";
			*(expwords + 7) = "march";
			*(expwords + 8) = "Yes";

			for (int i = 0; i < n; i++)
				Assert::AreEqual(words[i], expwords[i]);
		};
	};
}