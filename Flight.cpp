#include "Flight.h"

// Constructors
CFlight::CFlight(const CFlightInfo flightInfo)
{
	this->flightInfo = new CFlightInfo(flightInfo);
	this->passengersNumber = 0;
	this->numCrewMembers = 0;
}

CFlight::CFlight(const CFlightInfo flightInfo, CPlane* plane)
{
	this->flightInfo = new CFlightInfo(flightInfo);
	this->plane = plane;
	this->passengersNumber = 0;
	this->numCrewMembers = 0;
	this->planeAssigned = true;
}

CFlight::CFlight(const CFlight & other)
{

	this->passengersNumber = other.passengersNumber;
	this->planeAssigned = other.planeAssigned;
	this->plane = other.plane;
	this->numCrewMembers = other.numCrewMembers;
	this->flightInfo = new CFlightInfo(*(other.flightInfo));

	for (int i = 0; i < this->numCrewMembers; i++)
	{
		this->crewMembers[i] = other.crewMembers[i];
	}
}

// Desctructor
CFlight::~CFlight()
{
	delete this->flightInfo;
}

// Getters
const CFlightInfo CFlight::getFlightInfo()
{
	return *(this->flightInfo);
}


const CPlane * CFlight::getPlane()
{
	return this->plane;
}

const CCrewMember * CFlight::getCrewMembers()
{
	return *(this->crewMembers);
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
void CFlight::SetPlane(CPlane* plane)
{
	this->plane = plane;
	this->planeAssigned = true;
}

// Operators Overloading

// Compare by FlightInfo
bool CFlight::operator==(const CFlight& other) const
{
	return (this->flightInfo == other.flightInfo);
}

const CFlight& CFlight::operator=(const CFlight& other)
{
	if (this != &other)
	{
		*this->flightInfo = *other.flightInfo;
		this->plane = other.plane;
		this->numCrewMembers = other.numCrewMembers;
		for (int i = 0; i < other.numCrewMembers; i++)
		{
			this->crewMembers[i] = other.crewMembers[i];
		}
		this->passengersNumber = other.passengersNumber;
	}
	return *this;
}
// Add CrewMember
CFlight CFlight::operator+(CCrewMember& member)
{
	if (this->getNumCrewMembers() < MAX_CREW && !member.isInFlight())
	{
		CFlight tmp(*this);
		tmp.crewMembers[tmp.numCrewMembers] = &member;
		tmp.numCrewMembers++;
		return tmp;
	}
	cout << "Can't add crew member to flight" << endl;
	return *this;
}

ostream& operator<<(ostream& os, const CFlight& other)
{
	os << "Flight " << *(other.flightInfo);
	if (other.planeAssigned)
		os << *(other.plane);
	else
		os << " No plane assign yet ";
	os << " There are " << other.numCrewMembers << " crew memebers in flight:" << endl;
	for (int i = 0; i < other.numCrewMembers; i++)
	{
		os << *(other.crewMembers[i]) << endl;
	}
	return os;
}