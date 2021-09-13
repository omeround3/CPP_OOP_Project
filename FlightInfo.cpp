#include "FlightInfo.h"

// Constructor
CFlightInfo::CFlightInfo(const char destination[], int number, int duration, int distance)
{
	this->setNumber(number);
	this->setDest(destination);
	this->setDuration(duration);
	this->setDistance(distance);
}

// Copy Constructor
CFlightInfo::CFlightInfo(const CFlightInfo &other)
{
	this->number = other.number;
	strcpy(this->destination, other.destination);
	this->duration = other.duration;
	this->distance = other.distance;
}

CFlightInfo::CFlightInfo(ifstream& inFile,char * buffer)
{
	// Read & Set Dest
	inFile >> buffer;
	this->setDest(buffer);

	// Read & Set Num
	inFile >> buffer;
	this->setNumber(atoi(buffer));

	// Read & Set Duration
	inFile >> buffer;
	this->setDuration(atoi(buffer));

	// Read & Set Distance
	inFile >> buffer;
	this->setDistance(atoi(buffer));
}

// Desctructor
CFlightInfo::~CFlightInfo()
{
}

// Getters
int CFlightInfo::GetFNum() const
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
	string msg;
	if (!validatePositiveNumber(number, "flightNumber", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->number = number;
}

void CFlightInfo::setDest(const char destination[])
{
	string msg;
	if (!validateDest(destination,msg)) {
		throw CCompStringException(&msg[0]);
	}
	strcpy(this->destination, destination);
}

void CFlightInfo::setDuration(int duration)
{
	string msg;
	if (!validatePositiveNumber(duration, "flightDuration", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->duration = duration;
}

void CFlightInfo::setDistance(int distance)
{
	string msg;
	if (!validatePositiveNumber(distance, "flightDistance", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->distance = distance;
}

const CFlightInfo &CFlightInfo::operator=(const CFlightInfo &other)
{
	if (this != &other)
	{
		this->setNumber(other.GetFNum());
		this->setDest(other.getDestination());
		this->setDistance(other.getDistance());
		this->setDuration(other.getDuration());
	}
	return *this;
}

bool CFlightInfo::operator==(const CFlightInfo &other) const
{
	return (this->GetFNum() == other.GetFNum());
}

bool CFlightInfo::operator!=(const CFlightInfo &other) const
{
	return !(*this == other);
}

ostream &operator<<(ostream &os, const CFlightInfo &other)
{
	if (typeid(os) == typeid(ofstream)) {
		os << other.destination << " ";
		os << other.number << " ";
		os << other.duration << " ";
		os << other.distance << " ";
	}
	else {
		os << "Flight Info dest: " << other.getDestination();
		os << " Number " << other.GetFNum();
		os << " minutes " << other.getDuration();
		os << " KM " << other.getDistance() << endl;
	}

	return os;
}

CFlightInfo::operator int() const
{
	return this->getDuration();
}