#include "FlightInfo.h"

CFlightInfo::CFlightInfo(const char destination[], int number, int duration, int distance)
{
	this->number = number;
	strcpy(this->destination, destination);
	this->duration = duration;
	this->distance = distance;
}

CFlightInfo::~CFlightInfo()
{
}

int CFlightInfo::getNumber()
{
	return this->number;
}

char * CFlightInfo::getDestination()
{
	return this->destination;
}

int CFlightInfo::getDuration()
{
	return this->duration;
}

int CFlightInfo::getDistance()
{
	return this->distance;
}

void CFlightInfo::setNumber(int number)
{
	this->number = number;
}

void CFlightInfo::SetDest(const char destination[])
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

void CFlightInfo::Print(ostream & os)
{
	os << "Flight Info dest: " << this->getDestination();
	os << " Number " << this->getNumber();
	os << " minutes " << this->getDuration();
	os << " KM "<< this->getDistance() << endl;
}

bool CFlightInfo::IsEqual(CFlightInfo & other)
{
	return this->getNumber() == other.getNumber();
}
