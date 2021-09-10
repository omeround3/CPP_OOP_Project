#include "CrewMember.h"

// Constructors
CCrewMember::CCrewMember(const char* fullName)
{
	this->fullName = strdup(fullName);
	//this->employeeNum = crewCount++;
	this->minutes = 0;

}
CCrewMember::CCrewMember(const char * fullName, int minutes) : CCrewMember(fullName)
{
	this->minutes = minutes;	   
}


//  Copy Constructor
CCrewMember::CCrewMember(const CCrewMember & other)
{
	this->fullName = strdup(other.fullName);
	//this->employeeNum = other.employeeNum;
	this->minutes = other.minutes;
	this->inFlight = other.inFlight;
}

// Desctructor
CCrewMember::~CCrewMember()
{
	delete[] this->fullName;
}

// Getterr
char * CCrewMember::getFullName() const
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

// Setters
void CCrewMember::setFullName(const char *fullName)
{
	delete[] this->fullName;
	this->fullName = strdup(fullName);
}

void CCrewMember::setInFlight(bool flag)
{
	this->inFlight = flag;
}

// Class Functions
void CCrewMember::RecievePresent()
{
	cout << this->getFullName() << " thanking the company for receiving the holiday gift" << endl;
}

bool CCrewMember::compare(const CCrewMember & other) const
{
	return strcmp(this->getFullName(), other.getFullName()) == 0;
}


// bool CCrewMember::UpdateMinutes(int minutes)
// {
// 	if (minutes < 0) /* If we use "<=", we wouldn't be able to initialize with minutes=0 */
// 		return false;
// 	this->minutes += minutes;
// 	return true;
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
		//this->employeeNum = other.employeeNum;
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
	if (minutes < 0) /* If we use "<=", we wouldn't be able to initialize with minutes=0 */
	{
		printf("ERROR: %d minutes - value is negative", minutes);
		return false;
	}
	else
	{
		this->minutes += minutes;
		return true;
	}
}

ostream& operator<<(ostream& os, const CCrewMember& other)
{
	other.Print(os);
	return os;
}

void CCrewMember::Print(ostream & os) const
 {
 	os << " "<< this->getFullName();
 	os << " minutes " << this->getMinutes()<< " ";
 }

bool CCrewMember::TakeOff(int minutes)
{
	this->inFlight = true;
	return (*this += minutes);
}
