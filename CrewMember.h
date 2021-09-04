#pragma warning(disable : 4996)
#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <string>
#include <ostream>

using namespace std;

class CCrewMember
{
public:
	static constexpr int START_ID = 1000;

	// Constructor
	CCrewMember(const char* fullName);
	CCrewMember(const char* fullName, int minutes);
	// Copy Constructor
	CCrewMember(const CCrewMember& other);
	// Desctructor
	~CCrewMember();

	// Getters
	const char* getFullName() const;
	const int getMinutes() const;
	const int getCrewNumber() const;
	const bool isInFlight() const;

	// Setters
	void setFullName(const char *);
	void setInFlight(bool flag);

	// Class Functions
	// bool UpdateMinutes(int minutes);
	// void Print(ostream& os);
	// bool IsEqual(CCrewMember& other);

	// Operators Overloading
	const CCrewMember &operator=(const CCrewMember &other);
	bool operator==(const CCrewMember &other) const;
	bool operator+=(int minutes);
	friend ostream& operator<<(ostream& os, const CCrewMember& other);

private:
	static int crewCount;
	int employeeNum;
	char *fullName;
	int minutes;
	bool inFlight = false;
};

#endif // !CREWMEMBER_H
