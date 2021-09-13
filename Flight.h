#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef FLIGHT_H
#define FLIGHT_H
#define MAX_CREW 10

#include <string>
#include <iostream>
#include <fstream>
#include "FlightInfo.h"
#include "Plane.h"
#include "CrewMember.h"
#include "Pilot.h"
#include "Host.h"
#include "validations.h"
class CFlight
{

private:
	CCrewMember *crewMembers[MAX_CREW];
	CFlightInfo *flightInfo = nullptr;
	CPlane *plane = nullptr;
	int numCrewMembers = 0;
	int passengersNumber = 0;

public:
	CFlight(CFlightInfo flightInfo);
	CFlight(CFlightInfo flightInfo, CPlane *plane);
	CFlight(const CFlight &other);
	CFlight(ifstream& inFile, char * buffer);
	~CFlight();

	CFlightInfo& GetFlightInfo() const;
	const CPlane *getPlane() const;
	const int getPassengersNumber() const ;
	const int getNumCrewMembers()const ;
	const CCrewMember ** getCrewMembers()const ;
	void SetPlane(CPlane *plane);

	bool TakeOff();
	const bool hasPlane();

	const CFlight &operator=(const CFlight &other);
	bool operator==(const CFlight &other) const;
	CFlight &operator+(CCrewMember *member) throw(CCompStringException);
	friend ostream &operator<<(ostream &os, const CFlight &other);


};
#endif // !FLIGHT_H
