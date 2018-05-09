#include "stdafx.h"
#include "CarOwner.h"
#include <iostream>


CarOwner::CarOwner::CarOwner(char* surname, char* fname, char* sname, int phone, int index, char* country, char* region, char* district, char* city, char* street, int house, int flat, char* brand, int carn, int passport)
{
	std::cout << "Constructor works!" << std::endl;

	this->SetSurname(surname);
	this->SetFirstName(fname);
	this->SetSecondName(sname);
	this->SetPhoneNumber(phone);
	this->SetAddress(index, country, region, district, city, street, house, flat);
	this->SetBrand(brand);
	this->SetCarNumber(carn);
	this->SetPassportNumber(passport);
}

CarOwner::CarOwner::~CarOwner()
{
	std::cout << "Destructor works!" << std::endl;

	delete[] surname;
	delete[] firstname;
	delete[] secondname;
	delete[] country;
	delete[] region;
	delete[] district;
	delete[] city;
	delete[] street;
	delete[] brand;
}

#pragma region get-accessors

CAROWNER_API char * CarOwner::CarOwner::GetSurname() const
{
	return this->surname;
}

CAROWNER_API char * CarOwner::CarOwner::GetFirstName() const
{
	return this->firstname;
}

CAROWNER_API char * CarOwner::CarOwner::GetSecondName() const
{
	return this->secondname;
}

CAROWNER_API int CarOwner::CarOwner::GetPhoneNumber() const
{
	return phone;
}

CAROWNER_API int CarOwner::CarOwner::GetIndex() const
{
	return index;
}

CAROWNER_API char * CarOwner::CarOwner::GetCountry() const
{
	return country;
}

CAROWNER_API char * CarOwner::CarOwner::GetRegion() const
{
	return region;
}

CAROWNER_API char * CarOwner::CarOwner::GetDistrict() const
{
	return district;
}

CAROWNER_API char * CarOwner::CarOwner::GetCity() const
{
	return city;
}

CAROWNER_API char * CarOwner::CarOwner::GetStreet() const
{
	return street;
}

CAROWNER_API int CarOwner::CarOwner::GetHouseNumber() const
{
	return house;
}

CAROWNER_API int CarOwner::CarOwner::GetFlatNumber() const
{
	return flat;
}

CAROWNER_API char * CarOwner::CarOwner::GetBrand() const
{
	return brand;
}

CAROWNER_API int CarOwner::CarOwner::GetCarNumber() const
{
	return carnumber;
}

CAROWNER_API int CarOwner::CarOwner::GetPassportNumber() const
{
	return passport;
}

CAROWNER_API void CarOwner::CarOwner::GetAddress(int, char *, char *, char *, char *, char *, int, int) const
{
	GetIndex();
	GetCountry();
	GetRegion();
	GetDistrict();
	GetCity();
	GetStreet();
	GetHouseNumber();
	GetFlatNumber();
}

#pragma endregion

#pragma region set-accessors

CAROWNER_API void CarOwner::CarOwner::SetSurname(char * surname)
{
	if (surname == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->surname = AllocateMemory(surname);
	strcpy(this->surname, surname);
}

CAROWNER_API void CarOwner::CarOwner::SetFirstName(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->firstname = AllocateMemory(name);
	strcpy(this->firstname, name);
}

CAROWNER_API void CarOwner::CarOwner::SetSecondName(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->secondname = AllocateMemory(name);
	strcpy(this->secondname, name);
}

CAROWNER_API void CarOwner::CarOwner::SetPhoneNumber(int ph)
{
	if (ph <= 0)
	{
		throw std::invalid_argument("Number can not be negative or zero!");
	}

	if (CheckAmountOfNumbers(ph,7) == false)
	{
		throw std::invalid_argument("Phone number should have 7 digits!");
	}

	this->phone = ph;
}

CAROWNER_API void CarOwner::CarOwner::SetAddress(int ind, char* country, char * region, char * district, char * city, char * street, int house, int flat)
{
	SetIndex(ind);
	SetCountry(country);
	SetRegion(region);
	SetDistrict(district);
	SetCity(city);
	SetStreet(street);
	SetHouseNumber(house);
	SetFlatNumber(flat);
}

CAROWNER_API void CarOwner::CarOwner::SetIndex(int ind)
{
	if (ind <= 0)
	{
		throw std::invalid_argument("Index can not be negative or zero!");
	}

	if (CheckAmountOfNumbers(ind, 6) == false)
	{
		throw std::invalid_argument("Index should have 6 digits!");
	}

	this->index = ind;
}

CAROWNER_API void CarOwner::CarOwner::SetCountry(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->country = AllocateMemory(name);
	strcpy(this->country, name);
}

CAROWNER_API void CarOwner::CarOwner::SetRegion(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->region = AllocateMemory(name);
	strcpy(this->region, name);
}

CAROWNER_API void CarOwner::CarOwner::SetDistrict(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->district = AllocateMemory(name);
	strcpy(this->district, name);
}

CAROWNER_API void CarOwner::CarOwner::SetCity(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->city = AllocateMemory(name);
	strcpy(this->city, name);
}

CAROWNER_API void CarOwner::CarOwner::SetStreet(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->street = AllocateMemory(name);
	strcpy(this->street, name);
}

CAROWNER_API void CarOwner::CarOwner::SetHouseNumber(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Number can not be negative or zero!");
	}

	this->house = n;
}

CAROWNER_API void CarOwner::CarOwner::SetFlatNumber(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Number can not be negative or zero!");
	}

	this->flat = n;
}

CAROWNER_API void CarOwner::CarOwner::SetBrand(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->brand = AllocateMemory(name);
	strcpy(this->brand, name);
}

CAROWNER_API void CarOwner::CarOwner::SetCarNumber(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Number can not be negative or zero!");
	}

	if (CheckAmountOfNumbers(n, 4) == false)
	{
		throw std::invalid_argument("Car number should have 4 digits!");
	}

	this->carnumber = n;
}

CAROWNER_API void CarOwner::CarOwner::SetPassportNumber(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Number can not be negative or zero!");
	}

	if (CheckAmountOfNumbers(n, 8) == false)
	{
		throw std::invalid_argument("Passport number should have 8 digits!");
	}

	this->passport = n;
}

#pragma endregion

inline char * CarOwner::CarOwner::AllocateMemory(char* name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	return new char[strlen(name) + 1];
}

inline int * CarOwner::CarOwner::AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimension of array can not be negative or zero!");
	}

	return new int[n];
}

bool CarOwner::CarOwner::CheckAmountOfNumbers(int& n, const int C)
{
	int k = 1;

	while (n/10 > 0)
	{
		k++;
	}

	if (k == C)
		return true;
	else
		return false;
}
