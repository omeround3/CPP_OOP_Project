#pragma warning(disable : 4996)
#ifndef FLIGHT_H
#define FLIGHT_H
#define MAX_CREW 10

#include <string>
#include <iostream>
#include "FlightInfo.h"
#include "CrewMember.h"

class CPlane;

class CFlight
{
public:
	// Constructor
	CFlight();
	CFlight(CFlightInfo flightInfo);
	CFlight(CFlightInfo flightInfo, CPlane * plane);
	~CFlight();

	// Getters
	const CFlightInfo getFlightInfo();
	const CPlane *getPlane();
	const CCrewMember *getCrewMembers();
	const int getPassengersNumber();
	const int getNumCrewMembers();
	const bool hasPlane();

	// Setters
	void SetPlane(CPlane *plane);

	// Operators Overloading
	const CFlight& operator=(const CFlight& other);
	bool operator==(const CFlight& other) const;	// Compare by FlightInfo
	CFlight operator+(const CCrewMember& member);	// Add CrewMember
	friend ostream& operator<<(ostream& os, const CFlight& other);

private:
	CFlightInfo flightInfo;
	CPlane *plane;
	CCrewMember crewMembers[MAX_CREW];
	int passengersNumber;
	int numCrewMembers;
	bool planeAssigned = false;

};
#endif // !FLIGHT_H
