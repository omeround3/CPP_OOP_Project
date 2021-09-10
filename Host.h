#pragma warning(disable : 4996)
#ifndef HOST_H
#define HOST_H

#include "CrewMember.h"

class CHost : public CCrewMember
{

public:
	enum hostType { eRegular, eSuper, eCalcelan };
	CHost(char* name, hostType type);

	virtual void Print(ostream& os) const override;
	virtual void GetUniform() override;
	virtual void RecievePresent() override;
	virtual bool TakeOff(int minutes) override;
	char* getType() const;

private:
	char* typeArr[3] = { "Regular",  "Super","Calaelan" };
	hostType type;
};

#endif // !HOST_H

