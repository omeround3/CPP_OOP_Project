#include "FlightInfo.h"

// Constructor
CFlightInfo::CFlightInfo()
{
	this->number = 0;
	this->duration = 0;
	this->distance = 0;
}

CFlightInfo::CFlightInfo(const char destination[], int number, int duration, int distance)
{
	this->number = number;
	strcpy(this->destination, destination);
	this->duration = duration;
	this->distance = distance;
}

// Copy Constructor
CFlightInfo::CFlightInfo(const CFlightInfo &other)
{
	this->number = other.number;
	strcpy(this->destination, other.destination);
	this->duration = other.duration;
	this->distance = other.distance;
}

// Desctructor
CFlightInfo::~CFlightInfo()
{
}

// Getters
int CFlightInfo::getNumber() const
{
	return this->number;
}

const char *CFlightInfo::getDestination() const
{
	return this->destination;
}

int CFlightInfo ::getDuration() const
{
	return this->duration;
}

int CFlightInfo::getDistance() const
{
	return this->distance;
}

// Setters
void CFlightInfo::setNumber(int number)
{
	this->number = number;
}

void CFlightInfo::setDest(const char destination[])
{
	strcpy(this->destination, destination);
}

void CFlightInfo::setDuration(int duration)
{
	this->duration = duration;
}

void CFlightInfo::setDistance(int distance)
{
	this->distance = distance;
}

// Class Functions
// void CFlightInfo::Print(ostream & os)
// {
// 	os << "Flight Info dest: " << this->getDestination();
// 	os << " Number " << this->getNumber();
// 	os << " minutes " << this->getDuration();
// 	os << " KM "<< this->getDistance() << endl;
// }

// bool CFlightInfo::IsEqual(CFlightInfo & other)
// {
// 	return this->getNumber() == other.getNumber();
// }

//  Operators Overloading
const CFlightInfo &CFlightInfo::operator=(const CFlightInfo &other)
{
	if (this != &other)
	{
		this->setNumber(other.getNumber());
		this->setDest(other.getDestination());
		this->setDistance(other.getDistance());
		this->setDuration(other.getDuration());
	}
	return *this;
}

bool CFlightInfo::operator==(const CFlightInfo &other) const
{
	return (this->getNumber() == other.getNumber());
}

bool CFlightInfo::operator!=(const CFlightInfo &other) const
{
	return !(*this == other);
}

ostream &operator<<(ostream &os, const CFlightInfo &other)
{
	os << "Flight Info dest: " << other.getDestination();
	os << " Number " << other.getNumber();
	os << " minutes " << other.getDuration();
	os << " KM " << other.getDistance() << endl;
	return os;
}

CFlightInfo::operator int() const
{
	return this->getDuration();
}