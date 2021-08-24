#include "FlightCompany.h"

CFlightCompany::CFlightCompany(const char * name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

CFlightCompany::CFlightCompany(const CFlightCompany& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

CFlightCompany::~CFlightCompany()
{
	delete[] this->name;
}

char* CFlightCompany::getName()
{
	return this->name;
}

void CFlightCompany::Print(ostream& os)
{
	os << "Flight company: " << this->name << endl;
}

void CFlightCompany::SetName(const char * name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
