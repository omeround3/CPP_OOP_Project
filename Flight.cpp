#include "Flight.h"

// Constructors
CFlight::CFlight()
{
	this->flightInfo = flightInfo;
	this->passengersNumber = 0;
	this->numCrewMembers = 0;
}
CFlight::CFlight(CFlightInfo flightInfo)
{
	this->flightInfo = flightInfo;
	this->passengersNumber = 0;
	this->numCrewMembers = 0;
}

CFlight::CFlight(CFlightInfo flightInfo, CPlane* plane)
{
	this->flightInfo = flightInfo;
	this->plane = plane;
	this->passengersNumber = 0;
	this->numCrewMembers = 0;
}

// Desctructor
CFlight::~CFlight()
{
	delete[] this->plane;
}

// Getters
const CFlightInfo CFlight::getFlightInfo()
{
	return this->flightInfo;
}


const CPlane * CFlight::getPlane()
{
	return this->plane;
}

const CCrewMember * CFlight::getCrewMembers()
{
	return this->crewMembers;
}

const int CFlight::getPassengersNumber()
{
	return this->passengersNumber;
}

const int CFlight::getNumCrewMembers()
{
	return this->numCrewMembers;
}

const bool CFlight::hasPlane()
{
	return this->planeAssigned;
}

// Setters
void CFlight::SetPlane(CPlane * plane)
{
	this->plane = plane;
	this->planeAssigned = true;
}

// Operators Overloading
const CFlight& CFlight::operator=(const CFlight& other)
{
	if (this != &other)
	{
		this->flightInfo = other.flightInfo;
		delete[] this->plane;
		this->plane = other.plane;
		for (int i = 0; i < MAX_CREW; i++)
		{
			this->crewMembers[i] = other.crewMembers[i];
		}
		this->passengersNumber = other.passengersNumber;
	}
	return *this;
}

// Compare by FlightInfo
bool CFlight::operator==(const CFlight& other) const
{
	return (this->flightInfo == other.flightInfo);
}

// Add CrewMember
CFlight CFlight::operator+(const CCrewMember& member)
{
	if (this->getNumCrewMembers() < MAX_CREW && !member.isInFlight())
	{
		this->crewMembers[this->numCrewMembers] = member;
		this->numCrewMembers++;
	}
	else
		printf("The Crew Member %s is in flight already", member.getFullName());
	return *this;
}

ostream& operator<<(ostream& os, const CFlight& other)
{
	os << "Flight " << other.flightInfo;
	if (other.planeAssigned)
		os << other.plane;
	else
		os << "No plane assign yet ";
	os << "There are " << other.numCrewMembers << " crew members in flight:" << endl;
	return os;
}