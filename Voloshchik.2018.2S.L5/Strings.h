#pragma once
#ifdef STRINGS_EXPORTS
#define STRINGS_API __declspec(dllexport)
#else
#define STRINGS_API __declspec(dllimport)
#endif

namespace Strings
{
	STRINGS_API char** ObtainWords(char*, int&);
	STRINGS_API void DisplayWords(char**, int);
	STRINGS_API void FreeHeap(char**, int);
	STRINGS_API char** FindPalindromes(char**, int);
}