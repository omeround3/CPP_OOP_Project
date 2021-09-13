#include "FlightCompany.h"
enum crewType {HOST, PILOT};
enum planeType {COMMERCIAL, CARGO};

CFlightCompany::CFlightCompany(const char *name) : numCrewMembers(0),numFlights(0),numPlanes(0)
{
	this->SetName(name);
}

CFlightCompany::CFlightCompany(const char * fileName, int stam) : numCrewMembers(0), numFlights(0), numPlanes(0)
{
	char buffer[MAX_STR];
	ifstream inFile(fileName);
	if (inFile.fail()) {
		throw CCompFileException(fileName);
	}

	//Read & Set Company Name
	inFile >> buffer;
	this->SetName(buffer);

	//Read & Set numCrewMembers
	inFile >> buffer;
	this->numCrewMembers = atoi(buffer);

	//Initialize CrewMembers
	crewMemberFromFile(inFile, buffer);

	//Read & Set numPlanes
	inFile >> buffer;
	this->numPlanes = atoi(buffer);

	//Initialize planes
	planesFromFile(inFile,buffer);

	//Read & Set numFlights
	inFile >> buffer;
	this->numFlights = atoi(buffer);

	//Initialize flights
	flightsFromFile(inFile, buffer);

}
void CFlightCompany::flightsFromFile(ifstream& inFile, char * buffer) {
	int numCrewMembers, classType;
	const CHost* tmpHost;
	const CPilot* tmpPilot;

	for (int i = 0; i < this->numFlights; i++)
	{
		this->flights[i] = new CFlight(inFile, buffer);

		//Read & Set Plane (if exist)
		inFile >> buffer;
		if (atoi(buffer) == 1) {
			inFile >> buffer;
			this->flights[i]->SetPlane(this->getPlaneBySerial(atoi(buffer)));
		}

		//Read & Set CrewMembers
		inFile >> buffer;
		numCrewMembers = atoi(buffer);
		for (int j = 0; j < numCrewMembers; j++)
		{
			inFile >> buffer;
			classType = atoi(buffer);

			switch (classType)
			{
			case crewType::HOST:
				tmpHost = new CHost(inFile, buffer);
				*this->flights[i] + this->GetCrewMember(*tmpHost);
				delete tmpHost;
				break;
			case crewType::PILOT:
				tmpPilot = new CPilot(inFile, buffer);
				*this->flights[i] + this->GetCrewMember(*tmpPilot);
				delete tmpPilot;
				break;
			default:
				break;
			}
		}
	}
}
void CFlightCompany::SaveToFile(const char * fileName)
{
	try {
		ofstream outFile(fileName); // file will be overriten every time
		if (outFile.is_open()) {
			outFile << *this;
		}
	}
	catch(CFlightCompException& e){
		e.Show();
	}


}
void CFlightCompany::planesFromFile(ifstream& inFile, char * buffer) {
	for (int i = 0; i < this->numPlanes; i++)
	{
		this->planes[i] = CPlaneCrewFactory::GetPlaneFromFile(inFile);
	}
}
void CFlightCompany::crewMemberFromFile(ifstream& inFile, char *buffer) {
	for (int i = 0; i < this->numCrewMembers; i++)
	{
		this->crewMembers[i] = CPlaneCrewFactory::GetCrewMemberFromFile(inFile);
	}
}

CFlightCompany::CFlightCompany(const CFlightCompany &other)
{
	this->name = strdup(other.name);

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
	this->name = nullptr;
}

// Getters
const char *CFlightCompany::getName() const
{
	return this->name;
}

const int CFlightCompany::getNumCrewMembers()const
{
	return this->numCrewMembers;
}

const int CFlightCompany::getNumPlanes()const
{
	return this->numPlanes;
}

const int CFlightCompany::getNumFlights()const
{
	return this->numFlights;
}

CFlight *CFlightCompany::GetFlightByNum(int flightNumber) const
{
	for (int i = 0; i < this->numFlights; i++)
	{
		if (this->flights[i]->GetFlightInfo().GetFNum() == flightNumber)
		{
			return this->flights[i];
		}
	}
	return nullptr;
}

CCrewMember *CFlightCompany::GetCrewMember(int memberIdx) const
{
	if (!validateArrayIdx(memberIdx,this->numCrewMembers))
	{
		throw CCompLimitException(this->numCrewMembers-1);
	}
	return this->crewMembers[memberIdx];
}

CFlight *CFlightCompany::GetFlight(int flightIdx) const
{
	if (!validateArrayIdx(flightIdx, this->numFlights))
	{
		throw CCompLimitException(this->numFlights - 1);
	}
	return this->flights[flightIdx];
}

CPlane* CFlightCompany::getPlaneBySerial(int serialNumber) const
{
	for (int i = 0; i < this->numPlanes; i++)
	{
		if (this->planes[i]->getSerialNumber() == serialNumber) {
			return this->planes[i];
		}
	}
	return nullptr;
}

CPlane * CFlightCompany::GetPlane(int index)
{
		return &(*this)[index];

}

CCrewMember *CFlightCompany::GetCrewMember(const CCrewMember& member) const
{
	for (int i = 0; i < this->numCrewMembers; i++)
	{
		if (*this->crewMembers[i] == member) {
			return this->crewMembers[i];
		}
	}
	return nullptr;
}

// Setters
void CFlightCompany::SetName(const char *name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = strdup(name);
}

void CFlightCompany::SetNumCrewMembers(int num)
{
	string msg;
	if (!validatePositiveNumber(num, "numCrewMembers", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->numCrewMembers = num;
}

void CFlightCompany::SetNumPlanes(int num)
{
	string msg;
	if (!validatePositiveNumber(num, "numPlanes", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->numPlanes = num;
}

void CFlightCompany::SetNumFlights(int num)
{
	string msg;
	if (!validatePositiveNumber(num, "numFlights", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->numFlights = num;
}

bool CFlightCompany::AddCrewMember(const CCrewMember &member)
{
	for (int i = 0; i < this->numCrewMembers; i++)
	{
		if (*(this->crewMembers[i]) == member)
		{
			return false;
		}
	}

	this->crewMembers[this->getNumCrewMembers()] = member.clone();
	++this->numCrewMembers;
	return true;
}

bool CFlightCompany::AddPlane(const CPlane &plane)
{
	for (int i = 0; i < this->numPlanes; i++)
		if (*(this->planes[i]) == plane)
			return false;

	this->planes[this->numPlanes] = plane.clone();
	++this->numPlanes;
	return true;
}

bool CFlightCompany::AddFlight(const CFlight &flight)
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
	CPilot *pPilot;
	for (int i = 0; i < this->numCrewMembers; i++)
	{
		pPilot = dynamic_cast<CPilot *>(this->crewMembers[i]);
		if (pPilot)
		{
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
		if (typeid(*this->planes[i]) == typeid(CCargo))
		{
			counter++;
		}
	}
	return counter;
}

int CFlightCompany::GetCrewCount()
{
	return this->numCrewMembers;
}

bool CFlightCompany::TakeOff(int flightNum)
{
	CFlight *flight;
	for (int i = 0; i < this->numFlights; i++)
	{
		flight = this->flights[i];
		if (flight->GetFlightInfo().GetFNum() == flightNum)
		{
			return flight->TakeOff();
		}
	}
	return false;
}

void CFlightCompany::Print(ostream &os)
{
	os << "Flight company: " << this->name << endl;
	os << "There are " << this->numCrewMembers << " Crew members:" << endl;
	if (this->numCrewMembers > 0)
		for (int i = 0; i < numCrewMembers; i++)
			os << *(this->crewMembers[i])<<endl;
	os << "There are " << this->numPlanes << " Planes:" << endl;
	if (this->numPlanes > 0)
		for (int i = 0; i < numPlanes; i++)
			os << *(this->planes[i]) << endl;
	os << "There are " << this->numFlights << " Flights:" << endl;
	if (this->numFlights > 0)
		for (int i = 0; i < numFlights; i++)
			os << *(this->flights[i]) << endl;
}

CPlane& CFlightCompany::operator[](int idx) const
{
	if (!validateArrayIdx(idx, this->numPlanes)) {
		throw CCompLimitException(this->numPlanes - 1);
	}
	return *this->planes[idx];
}

ostream & operator<<(ostream & os, const CFlightCompany & comp)
{
	os << comp.getName()<<endl;
	os << comp.getNumCrewMembers() << endl;;
	for (int i = 0; i < comp.getNumCrewMembers(); i++)
	{
		os << *comp.GetCrewMember(i) << endl;
	}
	os << comp.getNumPlanes() << endl;
	for (int i = 0; i < comp.getNumPlanes(); i++)
	{
		os << comp[i] << endl;
	}
	os << comp.getNumFlights() << endl;
	for (int i = 0; i < comp.getNumFlights(); i++)
	{
		os << *comp.GetFlight(i) << endl;
	}
	return os;
}
