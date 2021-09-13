#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef PILOT_H
#define PILOT_H

#include "CrewMember.h"
#include "Address.h"

class CPilot : public CCrewMember
{
public:
	CPilot(const char *name, bool isCaptain, CAddress *homeAddress = nullptr, int minutes = 0) throw(CCompStringException);
	CPilot(ifstream& inFile, char * buffer);
	virtual void GetUniform() const override;
	virtual void Print(ostream &os) const override;
	virtual CCrewMember* clone() const override;
	virtual bool compare(const CCrewMember& other) const override;
	
	virtual bool operator==(const CCrewMember& other) const override;
	virtual bool operator+=(int minutes) override;

	void toSimulator() const;

private:
	bool isCaptain = false;
	CAddress *homeAddress;
};

#endif // !PILOT_H
