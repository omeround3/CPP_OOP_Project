#include "Host.h"

CHost::CHost(char * name, hostType type) : CCrewMember(name)
{
	this->type = type;
}

void CHost::Print(ostream & os) const
{
	os << "Host " << this->getType();
	CCrewMember::Print(os);
	os << endl;
}

void CHost::GetUniform()
{
	cout << this->getFullName()<<": I think the new uniform is very nice!" << endl;
}


void CHost::RecievePresent() {
	this->CCrewMember::RecievePresent();
	cout << "I was not expecting it" << endl;
}

char * CHost::getType() const
{
	return this->typeArr[this->type];
}

bool CHost::TakeOff(int minutes)
{
	return this->CCrewMember::TakeOff(minutes);
}
