#pragma warning(disable : 4996)
#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H

#include <string>
#include <ostream>

using namespace std;

#define MAX 100

class CFlightInfo
{
public:
	CFlightInfo(const char destination[],int number, int duration, int distance);
	/* The default copy c'tor is enough here, no allocation in creation */
	~CFlightInfo();
	int getNumber();
	char* getDestination();
	int getDuration();
	int getDistance();

	/* There are no restrictions given, hence setters return "void", not "bool" */
	void setNumber(int number);
	void SetDest(const char destination[]);
	void setDuration(int duration);
	void setDistance(int distance);

	void Print(ostream& os);
	bool IsEqual(CFlightInfo& other);


private:
	int number;
	char destination[MAX];
	int duration;
	int distance;
};

#endif // !FLIGHTINFO_H
