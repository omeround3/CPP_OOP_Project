#pragma warning(disable : 4996)
#ifndef FLIGHTCOMPANY_H
#define FLIGHTCOMPANY_H
#define MAX_PLANES 10
#define MAX_FLIGHT 5

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
	bool AddCrewMember(const CCrewMember member);
	bool AddPlane(const CPlane plane);
	bool AddFlight(const CFlight flight);
	CPlane *GetPlane(int index);
	//void AddCrewToFlight();
	
	// Class Functions
	void Print(ostream& os);

private:
	char* name;
	CCrewMember crewMembers[MAX_CREW];
	CPlane planes[MAX_PLANES];
	CFlight flights[MAX_FLIGHT];
	int numCrewMembers;
	int numPlanes;
	int numFlights;
};

#endif // !FLIGHTCOMPANY_H
