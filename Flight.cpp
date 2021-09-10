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
const CFlightInfo CFlight::GetFlightInfo() const
{
	return *(this->flightInfo);
}


const CPlane * CFlight::getPlane()
{
	return this->plane;
}

//const CCrewMember * CFlight::getCrewMembers()
//{
//	return *(this->crewMembers);
//}

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
	return (*this->flightInfo == *other.flightInfo);
}

CFlight& CFlight::operator+(CCrewMember* member)
{
	if (this->getNumCrewMembers() < MAX_CREW) { 
		/* Also needed to check that member isn't in 
		flight but it wasn't matching the output given by Yarden, 
		so we did whatever seems most logical */
		this->crewMembers[this->getNumCrewMembers()] = member;
		++this->numCrewMembers;
		return *this;
	}
	return *this;
}

bool CFlight::TakeOff()
{
	if (!CheckTakeOff()) {
		return false;
	}

	this->plane->TakeOff(this->flightInfo->getDuration());
	for (int i = 0; i < this->getNumCrewMembers(); i++)
	{
		if (!(this->crewMembers[i]->TakeOff(this->flightInfo->getDuration()))) {
			return false;
		}
	}
	return true;
}

bool CFlight::CheckTakeOff()
{
	int pilots = 0, supers = 0;
	CCrewMember* member;

	// Checks for "InFlight" members and counts Pilots and Super Hosts
	for (int i = 0; i < this->numCrewMembers; i++)
	{
		member = this->crewMembers[i];
		if (member->isInFlight()) {
			return false;
		} 
		if (strcmp(typeid(*member).name(), typeid(CPilot).name()) == 0) {
			++pilots;
		}
		else if (strcmp(typeid(*member).name(), typeid(CHost).name()) == 0 &&  strcmp(((CHost*)member)->getType(),"Super")==0) {
			++supers;
		}
	}

	// Check that condotions for take off are met
	if (this->plane) {
		// Commercial Flight
		if (strcmp(typeid(*this->plane).name(), typeid(CPlane).name())) {
			if (pilots != 1 || supers > 1) {
				return false;
			}
		}
		//Cargo Flight
		else {
			if (pilots < 1) {
				return false;
			}
		}
	}
	//No Plase assigned
	else {
		return false;
	}

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
		os << *(other.crewMembers[i]);
	}
	return os;
}