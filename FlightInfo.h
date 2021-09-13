#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H

#include <string>
#include <ostream>
#include <fstream>
#include "validations.h"

using namespace std;

#define MAX 100

class CFlightInfo
{
public:
	CFlightInfo(const char destination[], int number, int duration, int distance);
	CFlightInfo(const CFlightInfo &other);
	CFlightInfo(ifstream& inFile, char * buffer);
	~CFlightInfo();

	int GetFNum() const;
	const char *getDestination() const;
	int getDuration() const;
	int getDistance() const;

	/* There are no restrictions given, hence setters return "void", not "bool" */
	void setNumber(int number);
	void setDest(const char destination[]);
	void setDuration(int duration);
	void setDistance(int distance);

	const CFlightInfo &operator=(const CFlightInfo &other);
	bool operator==(const CFlightInfo &other) const;
	bool operator!=(const CFlightInfo &other) const;
	friend ostream &operator<<(ostream &os, const CFlightInfo &other);
	operator int() const;

private:
	int number;
	char destination[MAX];
	int duration;
	int distance;
};

#endif // !FLIGHTINFO_H
