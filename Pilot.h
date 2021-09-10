#pragma warning(disable : 4996)
#ifndef PILOT_H
#define PILOT_H

#include "CrewMember.h"
#include "Address.h"

class CPilot : public CCrewMember
{
public:
	CPilot(const char* name, bool isCaptain, CAddress* homeAddress=nullptr);

	virtual void GetUniform() override;
	virtual void Print(ostream& os)const override;
	virtual bool compare(const CCrewMember& other) const override;
	virtual bool operator+=(int minutes)override;

	void toSimulator();

private:
	bool isCaptain;
	CAddress* homeAddress;



};

#endif // !PILOT_H

