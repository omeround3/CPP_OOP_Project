#include "Pilot.h"

CPilot::CPilot(const char * name, bool isCaptain, CAddress * homeAddress) : CCrewMember(name)
{
	this->isCaptain = isCaptain;
	this->homeAddress = homeAddress;
}

void CPilot::GetUniform()
{
	cout << this->getFullName() << ": this is the fifth time I get a new uniform, this is a waste of money!" << endl;
}


void CPilot::Print(ostream & os) const
{
	os << "Pilot ";
	CCrewMember::Print(os);
	if (this->isCaptain) {
		os << " a Captain"<<endl;
	}
	else {
		os << "Home " << *this->homeAddress << endl;
		os << " Not a Captain" << endl;
	}

}

bool CPilot::compare(const CCrewMember & other) const
{
	if (this->homeAddress) {
		const CPilot* pPilot = dynamic_cast<const CPilot*>(&other);
		return this->CCrewMember::compare(other) && *this->homeAddress == *pPilot->homeAddress;
	}
	return this->CCrewMember::compare(other);
}

bool CPilot::operator+=(int minutes)
{
	int pilotMinutes = minutes;
	if (this->isCaptain) {
		pilotMinutes = ((int)minutes * 1.1);
	}
	return this->CCrewMember::operator+=(pilotMinutes);
}

void CPilot::toSimulator()
{
	cout << "Pilot " << this->getFullName() << " got the message will come soon" << endl;
}
