#include "Address.h"

CAddress::CAddress(int houseNumber, const char *streetName, const char* cityName)
{
	this->streetName = new char[strlen(streetName) + 1];
	strcpy(this->streetName, streetName);

	this->cityName = new char[strlen(cityName) + 1];
	strcpy(this->cityName, cityName);

	this->houseNumber = houseNumber;
}

CAddress::CAddress(const CAddress & other)
{
	this->streetName = new char[strlen(other.streetName) + 1];
	strcpy(this->streetName, other.streetName);

	this->cityName = new char[strlen(other.cityName) + 1];
	strcpy(this->cityName, other.cityName);

	this->houseNumber = other.houseNumber;
}

CAddress::~CAddress()
{
	delete[] this->streetName;
	delete[] this->cityName;
}

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

void CAddress::Print(ostream& os)
{
	os << this->getStreetName() << "  ";
	os << this->getHouseNumber() << ", ";
	os << this->getCityName() << endl;
}

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

