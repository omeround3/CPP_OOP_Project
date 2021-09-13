#include "CrewMember.h"

CCrewMember::CCrewMember(const char *fullName) : CCrewMember(fullName, 0) {}

CCrewMember::CCrewMember(ifstream& inFile,char * buffer)
{
	// Read & Set fullName
	inFile >> buffer;
	this->setFullName(buffer);
	
	// Read & Set minutes
	inFile >> buffer;
	this->setMinutes(atoi(buffer));
}

CCrewMember::CCrewMember(const char *fullName, int minutes) 
{
	this->setFullName(fullName);
	this->setMinutes(minutes);
}

CCrewMember::CCrewMember(const CCrewMember &other)
{
	this->fullName = strdup(other.fullName);
	this->minutes = other.minutes;
	this->inFlight = other.inFlight;
}

CCrewMember::~CCrewMember()
{
	if (this->fullName) {
		delete[] this->fullName;
	}
}

// Getterr
char *CCrewMember::getFullName() const
{
	return this->fullName;
}

int CCrewMember::getMinutes() const
{
	return this->minutes;
}

bool CCrewMember::isInFlight() const
{
	return this->inFlight;
}

void CCrewMember::setFullName(const char *fullName)
{
	string msg;
	if (!validateFullName(fullName,msg)) { // Name restrictions...
		this->~CCrewMember();
		throw CCompStringException(&msg[0]);
	}
	if (!this->fullName) {
		delete[] this->fullName;
	}
	this->fullName = strdup(fullName);
}

void CCrewMember::setInFlight(bool flag)
{
	this->inFlight = flag;
}

void CCrewMember::setMinutes(int minutes)
{

	string msg;
	if (!validateFullName(fullName, msg)) { // Name restrictions...
		this->~CCrewMember();
		throw CCompStringException(&msg[0]);
	}		
	this->minutes = minutes;
}

// Class Functions
void CCrewMember::RecievePresent() const
{
	cout << this->getFullName() << " thanking the company for receiving the holiday gift" << endl;
}

// Operators Overloading
const CCrewMember &CCrewMember::operator=(const CCrewMember &other)
{
	if (this != &other)
	{
		this->setFullName(other.fullName);
		this->minutes = other.minutes;
	}
	return *this;
}

bool CCrewMember::operator==(const CCrewMember &other) const
{
	return this->compare(other);
}

bool CCrewMember::operator+=(int minutes)
{
	string msg;
	if (!validateMinutes(minutes,msg)) 
	{
		throw CCompStringException(&msg[0]);
		return false; // if we will decide to "set_terminate" one day
	}
	else
	{
		this->minutes += minutes;
		return true;
	}
}

ostream &operator<<(ostream &os, const CCrewMember &other)
{
	other.Print(os);
	return os;
}

void CCrewMember::Print(ostream &os) const
{
	if (typeid(os) == typeid(ofstream)) {
		os << this->fullName << " " << this->minutes<<" ";
	}
	else {
		os << " " << this->getFullName();
		os << " minutes " << this->getMinutes() << " ";
	}

}

bool CCrewMember::TakeOff(int minutes)
{
	this->inFlight = true;
	return (*this += minutes);
}
