#include "Plane.h"

// Static Variables
int CPlane::objCounter = 100;

CPlane::CPlane(int numOfSeats, const char *modelName)
{
	this->serialNumber = objCounter++;
	this->setNumOfSeats(numOfSeats);
	this->setModelName(modelName);
}

CPlane::CPlane(const CPlane &other)
{
	this->serialNumber = other.serialNumber;
	this->numOfSeats = other.numOfSeats;
	this->modelName = strdup(other.modelName);
}

CPlane::CPlane(ifstream& inFile, char * buffer, bool isCargo)
{
	if (!isCargo) {
		// Read & Set lastId 
		inFile >> buffer;
		this->objCounter = atoi(buffer);
	}

	// Read & Set id 
	inFile >> buffer;
	this->serialNumber = atoi(buffer);

	// Read & Set model 
	inFile >> buffer;
	this->setModelName(buffer);

	// Read & Set seats 
	inFile >> buffer;
	this->numOfSeats = atoi(buffer);

}

CPlane::~CPlane()
{
	delete[] this->modelName;
}

int CPlane::getSerialNumber() const
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

void CPlane::setModelName(const char * modelName)
{
	string msg;
	if (!validateStrMinLen(modelName, "modelName", msg)) {
		throw CCompStringException(&msg[0]);
	}
	if (this->modelName) {
		delete[] this->modelName;
	}
	this->modelName = strdup(modelName);
}

void CPlane::setSerialNumber(int serialNumber)
{
	string msg;
	if (!validatePositiveNumber(serialNumber, "serialNumber", msg)) {
		throw (CCompStringException(&msg[0]));
	}
	this->serialNumber = serialNumber;
}



void CPlane::setNumOfSeats(int numOfSeats)
{
	string msg;
	if (!validatePositiveNumber(numOfSeats, "numOfSeats", msg)) {
		throw (CCompStringException(&msg[0]));
	}
	this->numOfSeats = numOfSeats;
}

void CPlane::Print(ostream &os,bool isCargo) const
{
	if (typeid(os) == typeid(ofstream)) {
		if (!isCargo) {
			os << "0 "<<this->objCounter<<" ";
		}
		os << this->serialNumber << " " << this->modelName << " " << this->numOfSeats;
	}
	else {
		os << "Plane " << this->serialNumber << " degem ";
		os << this->modelName << " seats ";
		os << this->numOfSeats;
	}

}

CPlane * CPlane::clone() const
{
	return new CPlane(*this);
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

void setObjectCounter(int objectCounter)
{
	string msg;
	if (!validatePositiveNumber(objectCounter, "objectCounter", msg)) {
		throw (CCompStringException(&msg[0]));
	}
	CPlane::objCounter = objectCounter;
}

ostream &operator<<(ostream &os, const CPlane &other)
{
	other.Print(os);
	return os;
}