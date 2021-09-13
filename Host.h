#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef HOST_H
#define HOST_H

#include "CrewMember.h"

class CHost : public CCrewMember
{

public:
	enum hostType
	{
		eRegular,
		eSuper,
		eCalcelan
	};
	CHost(const char *name, hostType type, int minutes=0) throw(CCompStringException);
	CHost(ifstream& inFile, char * buffer);
	virtual CCrewMember* clone() const override;
	virtual void Print(ostream &os) const override;
	virtual void GetUniform() const override;
	virtual void RecievePresent() const override;
	virtual bool TakeOff(int minutes) override;
	char *getType() const;

private:
	char *typeArr[3] = {"Regular", "Super", "Calaelan"};
	hostType type;
};

#endif // !HOST_H
