#include "Host.h"
CHost::CHost(const char * name, hostType type, int minutes) throw(CCompStringException) : CCrewMember(name,minutes)
{
	this->type = type;
}

CHost::CHost(ifstream& inFile,char * buffer) : CCrewMember(inFile,buffer)
{
	inFile >> buffer;
	this->type = hostType(atoi(buffer));

}

CCrewMember * CHost::clone() const
{
	return new CHost(*this);
}

void CHost::Print(ostream &os) const
{
	if (typeid(os) == typeid(ofstream)) {
		os << "0 ";
		CCrewMember::Print(os);
		os << type;
	}
	else {
		os << "Host " << this->getType();
		CCrewMember::Print(os);
	}

}

void CHost::GetUniform() const
{
	cout << this->getFullName() << ": I think the new uniform is very nice!" << endl;
}

void CHost::RecievePresent() const
{
	this->CCrewMember::RecievePresent();
	cout << "I was not expecting it" << endl;
}

char *CHost::getType() const
{
	return this->typeArr[this->type];
}

bool CHost::TakeOff(int minutes)
{
	return this->CCrewMember::TakeOff(minutes);
}
