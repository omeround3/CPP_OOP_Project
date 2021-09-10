#pragma warning(disable : 4996)
#ifndef FLIGHTCOMPANY_H
#define FLIGHTCOMPANY_H
#define MAX_PLANES 10
#define MAX_FLIGHT 5
#define MAX_CREW 10

#include <string>
#include <iostream>
#include <typeinfo>
#include "CrewMember.h"
#include "Host.h"
#include "Pilot.h"
#include "Cargo.h"
#include "Plane.h"
#include "Flight.h"

using namespace std;


class CFlightCompany
{
public:
	CFlightCompany(const char* name);
	CFlightCompany(const CFlightCompany& other);
	~CFlightCompany();

	const char* getName();
	const int getNumCrewMembers();
	const int getNumPlanes();
	const int getNumFlights();

	CFlight* GetFlightByNum(int flightNumber) const;
	CCrewMember* GetCrewMember(int memberIdx) const;
	CPlane *GetPlane(int index);
	int GetCargoCount();

	void SetName(const char* name); /* This wasn't stated in class definition but function is used in given main */

	bool AddCrewMember(const CCrewMember& member);
	bool AddPlane(const CPlane& plane);
	bool AddFlight(const CFlight& flight);
	void CrewGetPresent()const ;
	void PilotsToSimulator()const ;
	void CrewGetUniform() const;
	bool TakeOff(int flightNum);
	void Print(ostream& os);

private:
	char* name;

	CCrewMember* crewMembers[MAX_CREW];
	int numCrewMembers;

	CPlane* planes[MAX_PLANES];
	int numPlanes;

	CFlight* flights[MAX_FLIGHT];
	int numFlights;
};

#endif // !FLIGHTCOMPANY_H
