#include "Flight.h"

// Constructors
CFlight::CFlight(const CFlightInfo flightInfo)
{
	this->flightInfo = new CFlightInfo(flightInfo);
	this->passengersNumber = 0;
	this->numCrewMembers = 0;
}

CFlight::CFlight(const CFlightInfo flightInfo, CPlane *plane)
{
	this->flightInfo = new CFlightInfo(flightInfo);
	this->plane = plane;
	this->passengersNumber = 0;
	this->numCrewMembers = 0;
}

CFlight::CFlight(const CFlight &other)
{

	this->passengersNumber = other.passengersNumber;
	this->plane = other.plane;
	this->numCrewMembers = other.numCrewMembers;
	this->flightInfo = new CFlightInfo(*(other.flightInfo));

	for (int i = 0; i < this->numCrewMembers; i++)
	{
		this->crewMembers[i] = other.crewMembers[i];
	}
}

CFlight::CFlight(ifstream& inFile,char * buffer)
{
	this->flightInfo = new CFlightInfo(inFile,buffer);
	
}

// Desctructor
CFlight::~CFlight()
{
	delete this->flightInfo;
}

// Getters
CFlightInfo& CFlight::GetFlightInfo() const
{
	return *(this->flightInfo);
}

const CPlane *CFlight::getPlane()const
{
	return this->plane;
}

//const CCrewMember * CFlight::getCrewMembers()
//{
//	return *(this->crewMembers);
//}

const int CFlight::getPassengersNumber()const
{
	return this->passengersNumber;
}

const int CFlight::getNumCrewMembers()const
{
	return this->numCrewMembers;
}

const CCrewMember ** CFlight::getCrewMembers() const
{
	return ((const CCrewMember**)this->crewMembers);
}

const bool CFlight::hasPlane()
{
	return !(this->plane == nullptr);
}

// Setters
void CFlight::SetPlane(CPlane *plane)
{
	this->plane = plane;
}

// Operators Overloading

// Compare by FlightInfo
bool CFlight::operator==(const CFlight &other) const
{
	return (*this->flightInfo == *other.flightInfo);
}

CFlight &CFlight::operator+(CCrewMember *member)
{
	if (this->getNumCrewMembers() < MAX_CREW)
	{
		for (int i = 0; i < this->numCrewMembers; i++)
		{
			if (*this->crewMembers[i] == *member) {
				throw CCompStringException("Crewmember already on this flight...\n");
			}
		}
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
	string msg;
	if (!validateFlightTakeOff(this,msg))
	{
		throw CCompStringException(&msg[0]);
		return false; // if we will decide to "set_terminate" one day
	}

	this->plane->TakeOff(this->flightInfo->getDuration());
	for (int i = 0; i < this->getNumCrewMembers(); i++)
	{
		if (!(this->crewMembers[i]->TakeOff(this->flightInfo->getDuration())))
		{
			return false;
		}
	}
	return true;
}

const CFlight &CFlight::operator=(const CFlight &other)
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

ostream &operator<<(ostream &os, const CFlight &other)
{

	if (typeid(os) == typeid(ofstream)) {
		os << (other.GetFlightInfo());
		if (other.plane) {
			os << "1 " << other.getPlane()->getSerialNumber();
		}
		else {
			os << 0;
		}
		os << endl;
		os << other.getNumCrewMembers()<<endl;
	}
	else {
		os << "Flight " << *(other.flightInfo);
		if (other.plane)
			os << *(other.plane) << endl;
		else
			os << " No plane assign yet ";
		os << " There are " << other.numCrewMembers << " crew memebers in flight:" << endl;
	}

	for (int i = 0; i < other.numCrewMembers; i++)
	{
		os << *(other.crewMembers[i]) << endl;
	}
	return os;
}