#pragma warning(disable : 4996)
#ifndef FLIGHTCOMPANY_H
#define FLIGHTCOMPANY_H
#define MAX_PLANES 10
#define MAX_FLIGHT 5
#define MAX_CREW 10

#include <string>
#include <Iostream>
#include "CrewMember.h"
#include "Plane.h"
#include "Flight.h"

using namespace std;


class CFlightCompany
{
public:
	// Costructor
	CFlightCompany(const char* name);
	// Copy Costructor
	CFlightCompany(const CFlightCompany& other);
	// Destructor
	~CFlightCompany();

	// Getters
	const char* getName();

	const int getNumCrewMembers();
	const int getNumPlanes();
	const int getNumFlights();


	// Setters
	void SetName(const char* name); /* This wasn't stated in class definition but function is used in given main */
	bool AddCrewMember(CCrewMember member);
	bool AddPlane(CPlane plane);
	bool AddFlight(CFlight flight);
	CPlane *GetPlane(int index);
	void AddCrewToFlight(const int flightNum, const int employeeNum);
	
	// Class Functions
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
