#include "Plane.h"

// Static Variables
int CPlane::objCounter = 100;

CPlane::CPlane(int numOfSeats, const char *modelName)
{
	this->serialNumber = objCounter++;
	this->numOfSeats = numOfSeats;
	this->modelName = new char[strlen(modelName) + 1];
	strcpy(this->modelName, modelName);
}

CPlane::CPlane(const CPlane &other)
{
	this->serialNumber = other.serialNumber;
	this->numOfSeats = other.numOfSeats;
	this->modelName = new char[strlen(other.modelName) + 1];
	strcpy(this->modelName, other.modelName);
}

CPlane::~CPlane()
{
	delete[] this->modelName;
}

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

void CPlane::Print(ostream &os) const
 {
	os << "Plane " << this->serialNumber << " degem ";
	os << this->modelName << " seats ";
	os << this->numOfSeats << endl;
 }

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
	other.Print(os);
	return os;
}