#include "CrewMember.h"

// Static Variables
int CCrewMember::crewCount = 1000;

// Constructor
CCrewMember::CCrewMember(const char * fullName, int minutes)
{
	this->fullName = new char[strlen(fullName) + 1];
	strcpy(this->fullName, fullName);
	this->crewNumber = ++crewCount;

}

//  Copy Constructor
CCrewMember::CCrewMember(const CCrewMember & other)
{
	this->fullName = new char[strlen(other.fullName) + 1];
	strcpy(this->fullName, other.fullName);
	this->crewNumber = other.crewNumber;
	this->minutes = other.minutes;
}

// Desctructor
CCrewMember::~CCrewMember()
{
	delete[] this->fullName;
}

// Getterr
const char * CCrewMember::getFullName() const
{
	return this->fullName;
}

const int CCrewMember::getMinutes() const
{
	return this->minutes;
}

const int CCrewMember::getCrewNumber() const
{
	return this->crewNumber;
}

// Setters
void CCrewMember::setFullName(const char *fullName)
{
	delete[] this->fullName;
	this->fullName = new char[strlen(fullName) + 1];
	strcpy(this->fullName, fullName);
}

// Class Functions
// bool CCrewMember::UpdateMinutes(int minutes)
// {
// 	if (minutes < 0) /* If we use "<=", we wouldn't be able to initialize with minutes=0 */
// 		return false;
// 	this->minutes += minutes;
// 	return true;
// }

// void CCrewMember::Print(ostream& os)
// {
// 	os << "Crewmember " << this->getFullName();
// 	os << " minutes " << this->getMinutes() << endl;
// }

// bool CCrewMember::IsEqual(CCrewMember& other)
// {
// 	return strcmp(this->getFullName(), other.getFullName()) == 0;
// }

// Operators Overloading
const CCrewMember &CCrewMember::operator=(const CCrewMember &other)
{
	if (this != &other)
	{
		this->crewNumber = other.getCrewNumber();
		this->setFullName(other.getFullName());
		this->minutes = other.getMinutes();
	}
	return *this;
}

bool CCrewMember::operator==(const CCrewMember &other) const
{
	return (this->getCrewNumber() == other.getCrewNumber());
}

CCrewMember &CCrewMember::operator+=(const CCrewMember &other)
{
	if (other.getMinutes() < 0) /* If we use "<=", we wouldn't be able to initialize with minutes=0 */
		printf("ERROR: %d minutes - value is negative", minutes);
	else
		this->minutes += other.getMinutes();
	return *this;
}
CCrewMember &CCrewMember::operator+=(int minutes)
{
	if (minutes < 0) /* If we use "<=", we wouldn't be able to initialize with minutes=0 */
		printf("ERROR: %d minutes - value is negative", minutes);
	else
		this->minutes += minutes;
	return *this;
}