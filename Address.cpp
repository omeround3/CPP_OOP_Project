#include "Address.h"
#include <iostream>

// Constructor
CAddress::CAddress(int houseNumber, const char *streetName, const char *cityName)
{
	this->setStreet(streetName);
	this->setNumber(houseNumber);
	this->setCity(cityName);
}

// Copy Constructor
CAddress::CAddress(const CAddress &other)
{
	this->streetName = strdup(other.streetName);
	this->cityName = strdup(other.cityName);
	this->houseNumber = other.houseNumber;
}

CAddress::CAddress(ifstream& inFile,char * buffer)
{
	// Read & Set Number
	inFile >> buffer;
	this->setNumber(atoi(buffer));

	// Read & Set Street
	inFile >> buffer;
	this->setStreet(buffer);

	// Read & Set City
	inFile >> buffer;
	this->setCity(buffer);

}

// Desctructor
CAddress::~CAddress()
{
	delete[] this->streetName;
	delete[] this->cityName;
}

// Getters
const int CAddress::getHouseNumber()
{
	return this->houseNumber;
}

const char *CAddress::getCityName()
{
	return this->cityName;
}

const char *CAddress::getStreetName()
{
	return this->streetName;
}

void CAddress::setStreet(const char * streetName)
{
	string msg;
	if (!validateStreet(streetName, msg)) {
		throw CCompStringException(&msg[0]);
	}

	if (this->streetName) {
		delete[] this->streetName;
	}
	this->streetName = strdup(streetName);
}
void CAddress::setCity(const char * cityName)
{
	string msg;
	if (!validateCity(cityName, msg)) {
		throw CCompStringException(&msg[0]);
	}

	if (this->cityName) {
		delete[] this->cityName;
	}
	this->cityName = strdup(cityName);
}

void CAddress::setNumber(int houseNumber)
{
	string msg;
	if (!validateHouseNumber(houseNumber, msg)) {
		throw CCompStringException(&msg[0]);
	}

	this->houseNumber = houseNumber;
}

void CAddress::UpdateAddress(const char *cityName, const char *streetName, int houseNumber)
{
	this->setStreet(streetName);
	this->setNumber(houseNumber);
	this->setCity(cityName);
}

CAddress *CAddress::GetCurrentAddress() { return this; }

//  Operators Overloading
const CAddress &CAddress::operator=(const CAddress &other)
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

bool CAddress::operator==(const CAddress &other) const
{
	return (this->houseNumber == other.houseNumber) && strcmp(this->streetName, other.streetName) == 0 && strcmp(this->cityName, other.cityName) == 0;
}

bool CAddress::operator!=(const CAddress &other) const
{
	return !(*this == other);
}

ostream &operator<<(ostream &os, const CAddress &other)
{
	if (typeid(os) == typeid(ofstream)) {
		os << other.houseNumber << " ";
		os << other.streetName << " ";
		os << other.cityName;
	}
	else {
		os << other.streetName << " ";
		os << other.houseNumber << "  ";
		os << other.cityName;
	}
	return os;
}

istream &operator>>(istream &in, CAddress &other)
{
	string street, city;
	int number;
	cout << "Please enter house number street name and city name:" << endl;
	in >> number;
	other.setNumber(number);
	in >> street;
	other.setStreet(street.c_str());
	in >> city;
	other.setCity(city.c_str());
	return in;
}