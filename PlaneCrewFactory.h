#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#pragma once

enum PlaneType
{
	eRegular,
	eCargo,
	nofPlaneType
};

enum CrewType
{
	eHost,
	ePilot,
	nofCrewType
};
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include "Host.h"
#include "Pilot.h"
#include "Cargo.h"
#include "Plane.h"
#include "FlightCompany.h"
using namespace std;

const string PlaneType_TITLE[nofPlaneType] = { "Regular", "Cargo" };
const string CrewType_TITLE[nofCrewType] = { "Host", "Pilot" };

class CPlane;
class CCrewMember;
class CFlightCompany;
class CAddress;


class CPlaneCrewFactory
{
public:
	static PlaneType GetPlaneType(const CPlane *pPlane);
	static CrewType GetCrewType(const CCrewMember *pCrew);
	static void GetCompanyDataFromUser(CFlightCompany &comp) throw (CCompStringException);
	static CPlane *GetPlaneFromUser() throw (CCompStringException);
	static void cleanCin();
	static CCrewMember *GetCrewFromUser() throw (CCompStringException);
	static CAddress* GetAddressFromUser() throw (CCompStringException);
	static void GetCompanyNameFromUser(CFlightCompany& comp) throw (CCompStringException);

	static CCrewMember *GetCrewMemberFromFile(ifstream &inFile);
	static CPlane *GetPlaneFromFile(ifstream &inFile);

private:
	CPlaneCrewFactory(void) { ; }
};
