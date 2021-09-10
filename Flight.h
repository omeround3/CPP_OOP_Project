#pragma warning(disable : 4996)
#ifndef FLIGHT_H
#define FLIGHT_H
#define MAX_CREW 10

#include <string>
#include <iostream>
#include "FlightInfo.h"
#include "Plane.h"
#include "CrewMember.h"
#include "Pilot.h"
#include "Host.h"

class CFlight
{
public:
	CFlight(CFlightInfo flightInfo);
	CFlight(CFlightInfo flightInfo, CPlane * plane);
	CFlight(const CFlight& other);
	~CFlight();
	
	const CFlightInfo GetFlightInfo() const;
	const CPlane *getPlane();
	const int getPassengersNumber();
	const int getNumCrewMembers();
	
	void SetPlane(CPlane* plane);

	bool TakeOff();
	bool CheckTakeOff();
	const bool hasPlane();

	const CFlight& operator=(const CFlight& other);
	bool operator==(const CFlight& other) const;
	CFlight& operator+(CCrewMember* member);
	friend ostream& operator<<(ostream& os, const CFlight& other);

private:
	CCrewMember* crewMembers[MAX_CREW];
	CFlightInfo* flightInfo;
	CPlane* plane;
	int numCrewMembers;
	int passengersNumber;
	bool planeAssigned = false;

};
#endif // !FLIGHT_H
