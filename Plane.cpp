#include "Plane.h"
CPlane::CPlane(int serialNumber, int numOfSeats, const char *modelName)
{
	this->serialNumber = serialNumber;
	this->numOfSeats = numOfSeats;

	this->modelName = new char[strlen(modelName) + 1];
	strcpy(this->modelName, modelName);
}

CPlane::CPlane(const CPlane & other)
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

char * CPlane::getModelName()
{
	return this->modelName;
}

int CPlane::getNumOfSeats()
{
	return this->numOfSeats;
}

void CPlane::Print(ostream & os)
{
	os << "Plane " << this->getSerialNumber();
	os << " degem " << this->getModelName();
	os << " seats " << this->getNumOfSeats() << endl;
}

bool CPlane::IsEqual(CPlane & other)
{
	return this->getSerialNumber() == other.getSerialNumber();
}
