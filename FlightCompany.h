#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef FLIGHTCOMPANY_H
#define FLIGHTCOMPANY_H

#define MAX_PLANES 10
#define MAX_FLIGHT 5
#define MAX_CREW 10

#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "CrewMember.h"
#include "Host.h"
#include "Pilot.h"
#include "Cargo.h"
#include "Plane.h"
#include "Flight.h"
#include "FlightCompException.h"
#include "PlaneCrewFactory.h"
#define MAX_STR 100
using namespace std;

class CFlightCompany
{
public:
	CFlightCompany(const char *name);
	CFlightCompany(const char *fileName, int stam);

	CFlightCompany(const CFlightCompany &other);
	~CFlightCompany();


	CCrewMember *GetCrewMember(const CCrewMember& member) const;
	CPlane* getPlaneBySerial(int serialNumber) const;
	CPlane * GetPlane(int index);
	CCrewMember *GetCrewMember(int index) const;
	CFlight *GetFlight(int flightIdx) const;

	const char *getName() const;
	const int getNumCrewMembers()const;
	const int getNumPlanes()const;
	const int getNumFlights()const;

	CFlight *GetFlightByNum(int flightNumber) const;

	int GetCargoCount();
	int GetCrewCount();


	void SetName(const char *name); /* This wasn't stated in class definition but function is used in given main */
	void SetNumCrewMembers(int num);
	void SetNumPlanes(int num);
	void SetNumFlights(int num);

	void SaveToFile(const char* fileName);
	bool AddCrewMember(const CCrewMember &member);
	bool AddPlane(const CPlane &plane);
	bool AddFlight(const CFlight &flight);
	void CrewGetPresent() const;
	void PilotsToSimulator() const;
	void CrewGetUniform() const;
	bool TakeOff(int flightNum);
	void Print(ostream &os);


	CPlane& operator[](int idx) const;
	friend ostream &operator<<(ostream &os, const CFlightCompany &comp);
private:
	char *name = nullptr;

	CCrewMember *crewMembers[MAX_CREW];
	int numCrewMembers;

	CPlane *planes[MAX_PLANES];
	int numPlanes;

	CFlight *flights[MAX_FLIGHT];
	int numFlights;

	void crewMemberFromFile(ifstream& inFile, char * buffer);
	void planesFromFile(ifstream& inFile, char * buffer);
	void flightsFromFile(ifstream& inFile, char * buffer);

};

#endif // !FLIGHTCOMPANY_H
