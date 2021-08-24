#pragma warning(disable : 4996)
#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <string>
#include <ostream>

using namespace std;

class CCrewMember
{
public:
	CCrewMember(const char* fullName, int minutes = 0);
	CCrewMember(const CCrewMember& other);
	~CCrewMember();
	
	bool UpdateMinutes(int minutes);

	char* getFullName();
	int getMinutes();

	void setFullName(const char *);

	void Print(ostream& os);
	bool IsEqual(CCrewMember& other);

private:
	char *fullName;
	int minutes;


};

#endif // !CREWMEMBER_H
