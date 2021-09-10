#pragma warning(disable : 4996)
#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <string>
#include <iostream>

using namespace std;

class CCrewMember
{
public:

	CCrewMember(const char* fullName);
	CCrewMember(const char* fullName, int minutes);
	CCrewMember(const CCrewMember& other);
	~CCrewMember();

	char* getFullName() const;
	int getMinutes() const;
	bool isInFlight() const;

	void setFullName(const char *);
	void setInFlight(bool flag);

	virtual void RecievePresent();
	virtual bool compare(const CCrewMember& other) const;
	virtual void GetUniform() {};
	virtual void Print(ostream& os) const;
	virtual bool TakeOff(int minutes);

	const CCrewMember &operator=(const CCrewMember &other);
	bool operator==(const CCrewMember &other) const;
	virtual bool operator+=(int minutes);
	friend ostream& operator<<(ostream& os, const CCrewMember& other);

private:
	char *fullName;
	int minutes;
	bool inFlight = false;
};

#endif // !CREWMEMBER_H
