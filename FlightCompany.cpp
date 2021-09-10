#include "FlightCompany.h"

CFlightCompany::CFlightCompany(const char * name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->numCrewMembers = 0;
	this->numPlanes = 0;
	this->numFlights = 0;
}

CFlightCompany::CFlightCompany(const CFlightCompany& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->numCrewMembers = other.numCrewMembers;
	for (int i = 0; i < this->numCrewMembers; i++)
	{
		this->AddCrewMember(*(other.crewMembers[i]));
	}

	this->numPlanes = other.numPlanes;
	for (int i = 0; i < this->numPlanes; i++)
	{
		this->AddPlane(*(other.planes[i]));
	}

	this->numFlights = other.numFlights;
	for (int i = 0; i < this->numFlights; i++)
	{
		this->AddFlight(*(other.flights[i]));
	}
}

CFlightCompany::~CFlightCompany()
{
	delete[] this->name;

	for (int i = 0; i < this->numCrewMembers; i++)
	{
		delete this->crewMembers[i];
	}

	for (int i = 0; i < this->numPlanes; i++)
	{
		delete this->planes[i];
	}

	for (int i = 0; i < this->numFlights; i++)
	{
		delete this->flights[i];
	}
}

// Getters
const char* CFlightCompany::getName()
{
	return this->name;
}

const int CFlightCompany::getNumCrewMembers()
{
	return this->numCrewMembers;
}

const int CFlightCompany::getNumPlanes()
{
	return this->numPlanes;
}

const int CFlightCompany::getNumFlights()
{
	return this->numFlights;
}

CFlight * CFlightCompany::GetFlightByNum(int flightNumber) const
{
	for (int i = 0; i < this->numFlights; i++)
	{
		if (this->flights[i]->GetFlightInfo().GetFNum() == flightNumber) {
			return this->flights[i];
		}
	}
}

CCrewMember* CFlightCompany::GetCrewMember(int memberIdx) const
{
	if (memberIdx >= this->numCrewMembers) {
		return nullptr;
	}
	return this->crewMembers[memberIdx];
}

// Setters
void CFlightCompany::SetName(const char * name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

bool CFlightCompany::AddCrewMember(const CCrewMember& member)
{
	for (int i = 0; i < this->numCrewMembers; i++) {
		if (*(this->crewMembers[i]) == member) {
			return false;
		}
	}

	const CPilot* pPilot = dynamic_cast<const CPilot*>(&member);
	if (pPilot) {
		this->crewMembers[this->getNumCrewMembers()] = new CPilot(*pPilot);
	}
	else {
		const CHost* pHost = dynamic_cast<const CHost*>(&member);
		if (pHost) {
			this->crewMembers[this->getNumCrewMembers()] = new CHost(*pHost);
		}
	}

	++this->numCrewMembers;
	return true;
}

bool CFlightCompany::AddPlane(const CPlane& plane)
{
	for (int i = 0; i < this->numPlanes; i++)
		if (*(this->planes[i]) == plane)
			return false;

	const CCargo* pCargo = dynamic_cast<const CCargo*>(&plane);
	if (pCargo) {
		this->planes[this->numPlanes] = new CCargo(*pCargo);
	}
	else {
		this->planes[this->numPlanes] = new CPlane(plane);
	}
	++this->numPlanes;
	return true;
}

bool CFlightCompany::AddFlight(const CFlight& flight)
{
	for (int i = 0; i < this->numFlights; i++)
		if (*(this->flights[i]) == flight)
			return false;
	this->flights[this->numFlights] = new CFlight(flight);
	++this->numFlights;
	return true;
}

void CFlightCompany::CrewGetPresent() const
{
	for (int i = 0; i < this->numCrewMembers; i++)
	{
		this->crewMembers[i]->RecievePresent();
	}
}

void CFlightCompany::PilotsToSimulator() const
{
	CPilot* pPilot;
	for (int i = 0; i < this->numCrewMembers; i++)
	{
		pPilot = dynamic_cast<CPilot*>(this->crewMembers[i]);
		if (pPilot) {
			pPilot->toSimulator();
		}
	}
}

void CFlightCompany::CrewGetUniform() const
{
	for (int i = 0; i < this->numCrewMembers; i++)
	{
		this->crewMembers[i]->GetUniform();
	}
}

int CFlightCompany::GetCargoCount()
{
	int counter = 0;
	for (int i = 0; i < this->numPlanes; i++)
	{
		if (strcmp(typeid(*this->planes[i]).name(), typeid(CCargo).name()) == 0) {
			counter++;
		}
		
	}
	return counter;
}

CPlane * CFlightCompany::GetPlane(int index)
{
	if (index <= this->numPlanes)
		return this->planes[index];
	return nullptr;
}

bool CFlightCompany::TakeOff(int flightNum)
{
	CFlight* flight;
	for (int i = 0; i < this->numFlights; i++)
	{
		flight = this->flights[i];
		if (flight->GetFlightInfo().GetFNum() == flightNum) {
			return flight->TakeOff();
		}
	}
	return false;
}

//void CFlightCompany::AddCrewToFlight(const int flightNum, const int employeeNum)
//{
//	int crewMebmerIdx = -1;
//	for (int i = 0; i < this->numCrewMembers; i++)
//	{
//		if (this->crewMembers[i]->getCrewNumber() == employeeNum) {
//			crewMebmerIdx = i;
//			i = this->numCrewMembers;
//		}
//	}
//	if (crewMebmerIdx != -1) {
//		for (int i = 0; i < numFlights; i++)
//		{
//			if (this->flights[i]->getFlightInfo().GetFNum() == flightNum) {
//				*(this->flights[i]) = *(this->flights[i]) + *(this->crewMembers[crewMebmerIdx]);
//				i = numFlights;
//			}
//		}
//	}
//	
//}

// Class Functions
void CFlightCompany::Print(ostream& os)
{
	os << "Flight company: " << this->name << endl;
	os << "There are " << this->numCrewMembers << " Crew members:" << endl;
	if (this->numCrewMembers > 0)
		for (int i = 0; i < numCrewMembers; i++)
			os << *(this->crewMembers[i]);
	os << "There are " << this->numPlanes << " Planes:" << endl;
	if (this->numPlanes > 0)
		for (int i = 0; i < numPlanes; i++)
			os << *(this->planes[i]);
	os << "There are " << this->numFlights << " Flights:" << endl;
	if (this->numFlights > 0)
		for (int i = 0; i < numFlights; i++)
			os << *(this->flights[i]);
}
