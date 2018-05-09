#pragma once
#ifdef CAROWNER_EXPORTS
#define CAROWNER_API __declspec(dllexport) 
#else
#define CAROWNER_API __declspec(dllimport) 
#endif

namespace CarOwner
{
	class CarOwner
	{
	public:
		CAROWNER_API CarOwner(char*, char*, char*, int, int, char*, char*, char*, char*, char*, int, int, char*, int, int) {};
		CAROWNER_API ~CarOwner();

		CAROWNER_API char* GetSurname() const;
		CAROWNER_API char* GetFirstName() const;
		CAROWNER_API char* GetSecondName() const;
		CAROWNER_API int GetPhoneNumber() const;
		CAROWNER_API void GetAddress(int, char*, char*, char*, char*, char*, int, int) const;
		CAROWNER_API int GetIndex() const;
		CAROWNER_API char* GetCountry() const;
		CAROWNER_API char* GetRegion() const;
		CAROWNER_API char* GetDistrict() const;
		CAROWNER_API char* GetCity() const;
		CAROWNER_API char* GetStreet() const;
		CAROWNER_API int GetHouseNumber() const;
		CAROWNER_API int GetFlatNumber() const;
		CAROWNER_API char* GetBrand() const;
		CAROWNER_API int GetCarNumber() const;
		CAROWNER_API int GetPassportNumber() const;

		CAROWNER_API void SetSurname(char*);
		CAROWNER_API void SetFirstName(char*);
		CAROWNER_API void SetSecondName(char*);
		CAROWNER_API void SetPhoneNumber(int);
		CAROWNER_API void SetAddress(int, char*, char*, char*, char*, char*, int, int);
		CAROWNER_API void SetIndex(int);
		CAROWNER_API void SetCountry(char*);
		CAROWNER_API void SetRegion(char*);
		CAROWNER_API void SetDistrict(char*);
		CAROWNER_API void SetCity(char*);
		CAROWNER_API void SetStreet(char*);
		CAROWNER_API void SetHouseNumber(int);
		CAROWNER_API void SetFlatNumber(int);
		CAROWNER_API void SetBrand(char*);
		CAROWNER_API void SetCarNumber(int);
		CAROWNER_API void SetPassportNumber(int);

	private:
		char* surname;
		char* firstname;
		char* secondname;
		int phone;
		int index;
		char* country;
		char* region;
		char* district;
		char* city;
		char* street;
		int house;
		int flat;
		char* brand;
		int carnumber;
		int passport;

		static char* AllocateMemory(char*);
		static int* AllocateMemory(int);

		bool CheckAmountOfNumbers(int&, const int);
	};
}