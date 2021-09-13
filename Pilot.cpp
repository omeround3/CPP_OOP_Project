#include "Pilot.h"

CPilot::CPilot(const char *name, bool isCaptain, CAddress *homeAddress,int minutes) : CCrewMember(name,minutes)
{
	this->isCaptain = isCaptain;
	this->homeAddress = homeAddress;
}

CPilot::CPilot(ifstream& inFile,char * buffer) : CCrewMember(inFile,buffer)
{
	// Read & Set Address 
	inFile >> buffer;
	if (atoi(buffer) == 1) {
		this->homeAddress = new CAddress(inFile, buffer);
	}

	// Read & Set Captain
	inFile >> buffer;
	if (atoi(buffer) == 1) {
		this->isCaptain = true;
	}
}

void CPilot::GetUniform() const
{
	cout << this->getFullName() << ": this is the fifth time I get a new uniform, this is a waste of money!" << endl;
}

void CPilot::Print(ostream &os) const
{
	if (typeid(os) == typeid(ofstream)) {
		os << "1 ";
		CCrewMember::Print(os);
		if (this->homeAddress) {
			os << "1 ";
			os << *this->homeAddress;
		}
		else {
			os << "0 ";
		}
		os << " "<<(this->isCaptain == true);
	}
	else {
		os << "Pilot ";
		CCrewMember::Print(os);
		if (this->isCaptain)
		{
			os << " a Captain";
		}
		else
		{
			os << "Home " << *this->homeAddress << endl;
			os << " Not a Captain";
		}
	}

}

CCrewMember * CPilot::clone() const
{
	return new CPilot(*this);
}

bool CPilot::compare(const CCrewMember & other) const
{
	const CPilot* pOther = dynamic_cast<const CPilot*>(&other);
	if (!this->CCrewMember::compare(other)) {
		return false;
	}
	if(pOther) {
		if (this->homeAddress && pOther->homeAddress && *this->homeAddress == *pOther->homeAddress) {
			return true;
		}
	}
	else {
		return false;
	}
	return false;
}

bool CPilot::operator==(const CCrewMember & other) const
{
	if (!this->CCrewMember::operator==(other)) {
		return false;
	}
	if (this->homeAddress) {
		const CPilot* pPilot = dynamic_cast<const CPilot*>(&other);
		return *pPilot->homeAddress == *this->homeAddress;
	}
	return true; // or whatever we want if a pilot doesn't have an address

}

bool CPilot::operator+=(int minutes)
{
	int pilotMinutes = minutes;
	if (this->isCaptain)
	{
		pilotMinutes = ((int)minutes * 1.1);
	}
	return this->CCrewMember::operator+=(pilotMinutes);
}

void CPilot::toSimulator() const
{
	cout << "Pilot " << this->getFullName() << " got the message will come soon" << endl;
}
