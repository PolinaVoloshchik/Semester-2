#ifndef carowner_h
#define carowner_h

const int N = 50;
const int M = 5;

class CarOwner
{
public:
	CarOwner() {}
	CarOwner(char*, char*, char*, int, int, char*, char*, char*, char*, char*, int, int, char*, int, int);
	~CarOwner();

	char* GetSurname() const;
	char* GetFirstName() const;
	char* GetSecondName() const;
	int GetPhoneNumber() const;
	void GetAddress(int, char*, char*, char*, char*, char*, int, int) const;
	int GetIndex() const;
	char* GetCountry() const;
	char* GetRegion() const;
	char* GetDistrict() const;
	char* GetCity() const;
	char* GetStreet() const;
	int GetHouseNumber() const;
	int GetFlatNumber() const;
	char* GetBrand() const;
	int GetCarNumber() const;
	int GetPassportNumber() const;

	void SetCarOwner(char*, char*, char*, int, int, char*, char*, char*, char*, char*, int, int, char*, int, int);
	void SetSurname(char*);
	void SetFirstName(char*);
	void SetSecondName(char*);
	void SetPhoneNumber(int);
	void SetAddress(int, char*, char*, char*, char*, char*, int, int);
	void SetIndex(int);
	void SetCountry(char*);
	void SetRegion(char*);
	void SetDistrict(char*);
	void SetCity(char*);
	void SetStreet(char*);
	void SetHouseNumber(int);
	void SetFlatNumber(int);
	void SetBrand(char*);
	void SetCarNumber(int);
	void SetPassportNumber(int);

	void EnterCarOwner();
	void DisplayCarOwner();

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

#endif