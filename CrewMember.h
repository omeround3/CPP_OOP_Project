#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <string>
#include <iostream>
#include <fstream>
#include "FlightCompException.h"
#include "validations.h"
using namespace std;

class CCrewMember
{
public:
	CCrewMember(const char *fullName) throw(CCompStringException);
	CCrewMember(const char *fullName, int minutes) throw(CCompStringException);
	CCrewMember(ifstream& infile, char * buffer);
	CCrewMember(const CCrewMember &other);
	virtual ~CCrewMember();

	char *getFullName() const;
	int getMinutes() const;
	bool isInFlight() const;

	void setFullName(const char *name)throw(CCompStringException);
	void setInFlight(bool flag);
	void setMinutes(int minutes) throw(CCompStringException);

	virtual bool compare(const CCrewMember& other) const { return strcmp(this->getFullName(), other.getFullName()) == 0; };
	virtual void RecievePresent() const;
	virtual void GetUniform() const = 0;
	virtual void Print(ostream &os) const;
	virtual CCrewMember* clone() const = 0;

	virtual bool TakeOff(int minutes);

	const CCrewMember &operator=(const CCrewMember &other);
	virtual bool operator==(const CCrewMember &other) const;
	virtual bool operator+=(int minutes);
	friend ostream &operator<<(ostream &os, const CCrewMember &other);

private:
	char *fullName = nullptr;
	int minutes;
	bool inFlight = false;
};

#endif // !CREWMEMBER_H
