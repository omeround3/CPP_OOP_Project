#include "Address.h"
#include <iostream>


const size_t MAX_LEN = 256;

// Constructor
CAddress::CAddress(int houseNumber, const char *streetName, const char* cityName)
{
	this->houseNumber = houseNumber;
	if (streetName != NULL)
	{
		this->streetName = new char[strlen(streetName) + 1];
		strcpy(this->streetName, streetName);
	}
	if (cityName != NULL)
	{
		this->cityName = new char[strlen(cityName) + 1];
		strcpy(this->cityName, cityName);
	}	
}

// Copy Constructor
CAddress::CAddress(const CAddress & other)
{
	this->streetName = new char[strlen(other.streetName) + 1];
	strcpy(this->streetName, other.streetName);

	this->cityName = new char[strlen(other.cityName) + 1];
	strcpy(this->cityName, other.cityName);

	this->houseNumber = other.houseNumber;
}

// Desctructor
CAddress::~CAddress()
{
	delete[] this->streetName;
	delete[] this->cityName;
}

// Getters
int CAddress::getHouseNumber()
{
	return this->houseNumber;
}

char * CAddress::getCityName()
{
	return this->cityName;
}

char * CAddress::getStreetName()
{
	return this->streetName;
}

// OLD Print function
// void CAddress::Print(ostream& os)
// {
// 	os << this->getStreetName() << "  ";
// 	os << this->getHouseNumber() << ", ";
// 	os << this->getCityName() << endl;
// }

void CAddress::UpdateAddress(const char * cityName, const char * streetName, int houseNumber)
{
	delete[] this->streetName;
	this->streetName = new char[strlen(streetName) + 1];
	strcpy(this->streetName, streetName);

	delete[] this->cityName;
	this->cityName = new char[strlen(cityName) + 1];
	strcpy(this->cityName, cityName);

	this->houseNumber = houseNumber;
}

CAddress * CAddress::GetCurrentAddress() { return this; }

//  Operators Overloading
const CAddress& CAddress::operator = (const CAddress& other)
{
	if (this != &other) 
	{
		this->houseNumber = other.houseNumber;
		delete[] this->streetName;
		delete[] this->cityName;
		this->streetName = strdup(other.streetName);
		this->cityName = strdup(other.cityName);
	}
	return *this;
}

bool CAddress::operator == (const CAddress& other) const
{
	return (this->houseNumber == other.houseNumber) 
		&& (this->streetName == other.streetName)
		&& (this->cityName == other.cityName);
}

bool CAddress::operator != (const CAddress& other) const
{
	return !(*this == other);
}

ostream& operator << (ostream& os, const CAddress& other)
{
	os << other.streetName << "  ";
	os << other.houseNumber << ", ";
	os << other.cityName << endl;
	return os;
}

istream& operator >> (istream& in, CAddress& other)
{
	cout << "Please enter the house number" << endl;
	in >> other.houseNumber;

	cout << "Please enter the street name" << endl;
	string str;
	in >> str;
	other.streetName = new char[str.length() + 1];
	strcpy(other.streetName, str.c_str());

	cout << "Please enter the city name" << endl;
	in >> str;
	other.cityName = new char[str.length() + 1];
	strcpy(other.cityName, str.c_str());

	return in;
}