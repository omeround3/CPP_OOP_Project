#include "Plane.h"

// Static Variables
int CPlane::objCounter = 100;

// Constructor
CPlane::CPlane(int numOfSeats, const char *modelName)
{
	this->serialNumber = objCounter++;
	this->numOfSeats = numOfSeats;
	this->modelName = new char[strlen(modelName) + 1];
	strcpy(this->modelName, modelName);
}

// Copy Constructor
CPlane::CPlane(const CPlane &other)
{
	this->serialNumber = other.serialNumber;
	this->numOfSeats = other.numOfSeats;
	this->modelName = new char[strlen(other.modelName) + 1];
	strcpy(this->modelName, other.modelName);
}

// Desctructor
CPlane::~CPlane()
{
	delete[] this->modelName;
}

// Getters
int CPlane::getSerialNumber()
{
	return this->serialNumber;
}

char *CPlane::getModelName()
{
	return this->modelName;
}

int CPlane::getNumOfSeats()
{
	return this->numOfSeats;
}

// Pretty print
// void CPlane::Print(ostream &os)
// {
// 	os << "Plane " << this->getSerialNumber();
// 	os << " degem " << this->getModelName();
// 	os << " seats " << this->getNumOfSeats() << endl;
// }

// bool CPlane::IsEqual(CPlane &other)
// {
// 	return this->getSerialNumber() == other.getSerialNumber();
// }

//  Operators Overloading
const CPlane &CPlane::operator=(const CPlane &other)
{
	if (this != &other)
	{
		this->serialNumber = other.serialNumber;
		this->modelName = strdup(other.modelName);
		this->numOfSeats = other.numOfSeats;
	}
	return *this;
}

bool CPlane::operator==(const CPlane &other) const
{
	return (this->serialNumber == other.serialNumber);
}

const CPlane &CPlane::operator++()
{
	numOfSeats++;
	return *this;
}

CPlane CPlane::operator++(int)
{
	CPlane temp(*this);
	numOfSeats++;
	return temp;
}


ostream &operator<<(ostream &os, const CPlane &other)
{
	os << "Plane " << other.serialNumber << " degem ";
	os << other.modelName << " seats ";
	os << other.numOfSeats << endl;
	return os;
}