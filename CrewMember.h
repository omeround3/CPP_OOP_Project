#pragma warning(disable : 4996)
#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <string>
#include <ostream>

using namespace std;

class CCrewMember
{
public:
	// Constructor
	CCrewMember(const char* fullName, int minutes = 0);
	// Copy Constructor
	CCrewMember(const CCrewMember& other);
	// Desctructor
	~CCrewMember();
		
	// Getters
	const char* getFullName() const;
	const int getMinutes() const;
	const int getCrewNumber() const;

	// Setters
	void setFullName(const char *);
	
	// Class Functions
	// bool UpdateMinutes(int minutes);
	// void Print(ostream& os);
	// bool IsEqual(CCrewMember& other);
	
	// Operators Overloading
	const CCrewMember &operator=(const CCrewMember &other);
	bool operator==(const CCrewMember &other) const;
	CCrewMember &operator+=(const CCrewMember &other);
	CCrewMember &operator+=(int minutes);

private:
	static int crewCount;
	int crewNumber; 
	char *fullName;
	int minutes;
};

#endif // !CREWMEMBER_H
