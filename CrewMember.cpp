#include "CrewMember.h"

CCrewMember::CCrewMember(const char * fullName, int minutes)
{
	this->fullName = new char[strlen(fullName) + 1];
	strcpy(this->fullName, fullName);

	this->minutes = 0;
	this->UpdateMinutes(minutes); /* minutes value has restrictions */
}

CCrewMember::CCrewMember(const CCrewMember & other)
{
	this->fullName = new char[strlen(other.fullName) + 1];
	strcpy(this->fullName, other.fullName);
	this->minutes = other.minutes;
}

CCrewMember::~CCrewMember()
{
	delete[] this->fullName;
}

bool CCrewMember::UpdateMinutes(int minutes)
{
	if (minutes < 0) /* If we use "<=", we wouldn't be able to initialize with minutes=0 */
		return false;
	this->minutes += minutes;
	return true;
}

char * CCrewMember::getFullName()
{
	return this->fullName;
}

int CCrewMember::getMinutes()
{
	return this->minutes;
}

void CCrewMember::setFullName(const char *fullName)
{
	delete[] this->fullName;
	this->fullName = new char[strlen(fullName) + 1];
	strcpy(this->fullName, fullName);
}

void CCrewMember::Print(ostream& os)
{
	os << "Crewmember " << this->getFullName();
	os << " minutes " << this->getMinutes() << endl;
}

bool CCrewMember::IsEqual(CCrewMember& other)
{
	return strcmp(this->getFullName(), other.getFullName()) == 0;
}
