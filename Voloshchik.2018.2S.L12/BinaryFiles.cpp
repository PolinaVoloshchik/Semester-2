#include "stdafx.h"
#include "BinaryFiles.h"
#include <iostream>
#include <cstring>

using namespace std;

CarOwner::CarOwner(char* surname, char* fname, char* sname, int phone, int index, char* country, char* region, char* district, char* city, char* street, int house, int flat, char* brand, int carn, int passport)
{
	this->SetCarOwner(surname, fname, sname, phone, index, country, region, district, city, street, house, flat, brand, carn, passport);
}

CarOwner::~CarOwner()
{
	cout << "Destructor works!" << std::endl;

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

char * CarOwner::GetSurname() const
{
	return this->surname;
}

char * CarOwner::GetFirstName() const
{
	return this->firstname;
}

char * CarOwner::GetSecondName() const
{
	return this->secondname;
}

int CarOwner::GetPhoneNumber() const
{
	return phone;
}

void CarOwner::GetAddress(int, char *, char *, char *, char *, char *, int, int) const
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

int CarOwner::GetIndex() const
{
	return index;
}

char * CarOwner::GetCountry() const
{
	return country;
}

char * CarOwner::GetRegion() const
{
	return region;
}

char * CarOwner::GetDistrict() const
{
	return district;
}

char * CarOwner::GetCity() const
{
	return city;
}

char * CarOwner::GetStreet() const
{
	return street;
}

int CarOwner::GetHouseNumber() const
{
	return house;
}

int CarOwner::GetFlatNumber() const
{
	return flat;
}

char * CarOwner::GetBrand() const
{
	return brand;
}

int CarOwner::GetCarNumber() const
{
	return carnumber;
}

int CarOwner::GetPassportNumber() const
{
	return passport;
}

#pragma endregion

#pragma region set-accessors

void CarOwner::SetCarOwner(char* surname, char* fname, char* sname, int phone, int index, char* country, char* region, char* district, char* city, char* street, int house, int flat, char* brand, int carn, int passport)
{
	this->SetSurname(surname);
	this->SetFirstName(fname);
	this->SetSecondName(sname);
	this->SetPhoneNumber(phone);
	this->SetAddress(index, country, region, district, city, street, house, flat);
	this->SetBrand(brand);
	this->SetCarNumber(carn);
	this->SetPassportNumber(passport);
}

void CarOwner::SetSurname(char * surname)
{
	if (surname == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->surname = AllocateMemory(surname);
	strcpy(this->surname, surname);
}

void CarOwner::SetFirstName(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->firstname = AllocateMemory(name);
	strcpy(this->firstname, name);
}

void CarOwner::SetSecondName(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->secondname = AllocateMemory(name);
	strcpy(this->secondname, name);
}

void CarOwner::SetPhoneNumber(int ph)
{
	if (ph <= 0)
	{
		throw std::invalid_argument("Number can not be negative or zero!");
	}

	if (CheckAmountOfNumbers(ph, 7) == false)
	{
		throw std::invalid_argument("Phone number should have 7 digits!");
	}

	this->phone = ph;
}

void CarOwner::SetAddress(int ind, char* country, char * region, char * district, char * city, char * street, int house, int flat)
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

void CarOwner::SetIndex(int ind)
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

void CarOwner::SetCountry(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->country = AllocateMemory(name);
	strcpy(this->country, name);
}

void CarOwner::SetRegion(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->region = AllocateMemory(name);
	strcpy(this->region, name);
}

void CarOwner::SetDistrict(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->district = AllocateMemory(name);
	strcpy(this->district, name);
}

void CarOwner::SetCity(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->city = AllocateMemory(name);
	strcpy(this->city, name);
}

void CarOwner::SetStreet(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->street = AllocateMemory(name);
	strcpy(this->street, name);
}

void CarOwner::SetHouseNumber(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Number can not be negative or zero!");
	}

	this->house = n;
}

void CarOwner::SetFlatNumber(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Number can not be negative or zero!");
	}

	this->flat = n;
}

void CarOwner::SetBrand(char * name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	this->brand = AllocateMemory(name);
	strcpy(this->brand, name);
}

void CarOwner::SetCarNumber(int n)
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

void CarOwner::SetPassportNumber(int n)
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

inline char * CarOwner::AllocateMemory(char* name)
{
	if (name == nullptr)
	{
		throw std::invalid_argument("Name can not be empty!");
	}

	return new char[strlen(name) + 1];
}

inline int * CarOwner::AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimension of array can not be negative or zero!");
	}

	return new int[n];
}

bool CarOwner::CheckAmountOfNumbers(int& n, const int C)
{
	int k = 1;

	while (n / 10 > 0)
	{
		k++;
	}

	if (k == C)
		return true;
	else
		return false;
}

void CarOwner::EnterCarOwner()
{
	const int N = 256;
	char surname[N] = "", firstname[N] = "", secondname[N] = "", country[N] = "", region[N] = "", district[N] = "", city[N] = "", street[N] = "", brand[N] = "";
	cout << "Enter the surname: ";
	cin.ignore();
	cin.getline(surname, N, '\n');
	cout << "Enter the first name: ";
	cin.getline(firstname, N, '\n');
	cout << "Enter the second name: ";
	cin.getline(secondname, N, '\n');
	cout << "Enter phone number: ";
	cin >> phone;
	cout << "Enter the country: ";
	cin.getline(country, N, '\n');
	cout << "Enter the region: ";
	cin.getline(region, N, '\n');
	cout << "Enter the district: ";
	cin.getline(district, N, '\n');
	cout << "Enter the city: ";
	cin.getline(city, N, '\n');
	cout << "Enter index of the city: ";
	cin >> index;
	cout << "Enter the street: ";
	cin.getline(street, N, '\n');
	cout << "Enter number of the house: ";
	cin >> house;
	cout << "Enter number of the flat: ";
	cin >> flat;
	cout << "Enter the brand of car: ";
	cin.getline(brand, N, '\n');
	cout << "Enter number of the car: ";
	cin >> carnumber;
	cout << "Enter number of the passport of the car: ";
	cin >> passport;

	this->SetCarOwner(surname, firstname, secondname, phone, index, country, region, district, city, street, house, flat, brand, carnumber, passport);
}

void CarOwner::DisplayCarOwner()
{
	cout << endl << this->surname << " " << this->firstname << " " << this->secondname << endl;
	cout << "/tPhone number: " << this->phone << endl;
	cout << "/tAdress: " << this->country << ", " << this->region << ", " << this->district << ", " << endl;
	cout << "/t        " << this->city << ", " << this->index << ", " << this->street << ", " << this->house << "/" << this->flat << endl;
	cout << "/tCar information: " << this->brand << ", " << this->carnumber << ", " << this->passport << endl;
}
