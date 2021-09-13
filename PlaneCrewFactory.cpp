#include "PlaneCrewFactory.h"

PlaneType CPlaneCrewFactory::GetPlaneType(const CPlane *pPlane)
{
	if (typeid(pPlane) == typeid(CPlane *))
	{
		return PlaneType(0);
	}
	else
	{
		return PlaneType(1);
	}
}

CrewType CPlaneCrewFactory::GetCrewType(const CCrewMember *pCrew)
{
	if (typeid(pCrew) == typeid(CHost *))
	{
		return CrewType(0);
	}
	else
	{
		return CrewType(1);
	}
}

void CPlaneCrewFactory::GetCompanyNameFromUser(CFlightCompany & comp) throw(CCompStringException)
{
	bool success = false;
	char name[100];
	while (!success) {
		cout << "Company's Name: ";
		cin >> name;
		try {
			comp.SetName(name);
			success = true;
		}
		catch (CCompStringException e) {
			cout << "Following errors occured, please try again:\n";
			e.Show();
			cleanCin();

		}
		catch (...) {
			cout << "Unknown Error:\n";
			cleanCin();
		}
	}
}

void CPlaneCrewFactory::GetCompanyDataFromUser(CFlightCompany & comp) throw(CCompStringException)
{
	comp.~CFlightCompany();
	comp.SetNumCrewMembers(0);
	comp.SetNumFlights(0);
	comp.SetNumPlanes(0);
	int numCrew, numPlanes, lastId;
	cout << "Please Fill Flight Company's Info:\n";
	GetCompanyNameFromUser(comp);
	cout << "How Many Crew Members? :\n";
	cin >> numCrew;
	for (int i = 0; i < numCrew; i++)
	{
		comp.AddCrewMember(*GetCrewFromUser());
	}
	cout << "How Many Planes? :\n";
	cin >> numPlanes;
	for (int i = 0; i < numPlanes; i++)
	{
		comp.AddPlane(*GetPlaneFromUser());
	}
	cout << "Planes LastId? :\n";
	cin >> lastId;
	setObjectCounter(lastId);
}

CPlane * CPlaneCrewFactory::GetPlaneFromUser() throw(CCompStringException)
{
	CPlane* pPlane = nullptr;
	int pType, numOfSeats,id;
	float maxVol, maxKg, curVol, curKg;
	char model[100];
	bool success = false;

	while (!success) {
		cout << "Please Fill Plane's Info:\n";
		cout << "Plane-Type (0-Regular, 1-Cargo): ";
		cin >> pType;
		if (pType == PlaneType::eCargo) {
			cout << "Max Volume: ";
			cin >> maxVol;
			cout << "Max Weight: ";
			cin >> maxKg;
			cout << "Current Volume: ";
			cin >> curVol;
			cout << "Current Weight: ";
			cin >> curKg;
		}
		cout << "Id: ";
		cin >> id;
		cout << "Model Name: ";
		cin >> model;
		cout << "Number Of Seats: ";
		cin >> numOfSeats;
		try
		{
			if (pType == PlaneType::eRegular) {
				pPlane = new CPlane(numOfSeats, model);
				pPlane->setSerialNumber(id);
			}
			else {
				pPlane = new CCargo(numOfSeats, model, maxKg, maxVol);
				((CCargo*)pPlane)->setCurrentCargoVolume(curVol);
				((CCargo*)pPlane)->setCurrentCargoWeight(curKg);
				pPlane->setSerialNumber(id);
			}
			success = true;
		}
		catch (CCompStringException e)
		{
			cout << "Following errors occured, please try again:\n";
			e.Show();
			cleanCin();
		}
		catch (...) {
			cout << "Unknown Error:\n";
			cleanCin();
		}
	}
	return pPlane;
}

void CPlaneCrewFactory::cleanCin()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

CCrewMember * CPlaneCrewFactory::GetCrewFromUser()
{
	CAddress* address = nullptr;
	CCrewMember* pCrew = nullptr;
	int cType,minutes,type;
	char name[100];
	bool success = false;
	while (!success) {
		cout << "Please Fill CrewMember's Info:\n";
		cout << "Member-Type (0-Host, 1-Pilot): ";
		cin >> cType;
		if (cType == CrewType::eHost) {
			cout << "Host-Type (0-Regular, 1-Super, 2-Calcelan): ";
			cin >> type;
		}
		else {
			cout << "Is Captain? (0-No, 1-Yes): ";
			cin >> type;
			address = GetAddressFromUser();
		}
		cout << "Full-Name: ";
		cin >> name;
		cout << "Flight Minutes: ";
		cin >> minutes;
		try
		{
			if (cType == CrewType::eHost) {
				pCrew = new CHost(name, CHost::hostType(type), minutes);
			}
			else {
				pCrew = new CPilot(name, type, address, minutes);
			}
			success = true;
		}
		catch (CCompStringException e)
		{
			cout << "Following errors occured, please try again:\n";
			e.Show();
			cleanCin();
		}
		catch (...) {
			cout << "Unknown Error:\n";
			cleanCin();
		}
	}


	return pCrew;
}

CAddress * CPlaneCrewFactory::GetAddressFromUser() throw(CCompStringException)
{
	CAddress* pAddress = nullptr;
	bool success = false;
	string street, city;
	int number;
	while (!success) {
		cout << "Please Fill Address's Info:\n";
		cout << "Street Name: ";
		cin >> street;
		cout << "House Number: ";
		cin >> number;
		cout << "City Name: ";
		cin >> city;
		try
		{
			pAddress = new CAddress(number, street.c_str(), city.c_str());
			success = true;
		}
		catch (CCompStringException e)
		{
			cout << "Following errors occured, please try again:\n";
			e.Show();
			cleanCin();
		}
		catch (...) {
			cout << "Unknown Error:\n";
			cleanCin();
		}
	}
	return pAddress;


}



CCrewMember *CPlaneCrewFactory::GetCrewMemberFromFile(ifstream &inFile)
{
	char buffer[100];
	int classType;
	CCrewMember* pCrew = nullptr;
	// Get member type
	inFile >> buffer;
	classType = atoi(buffer);

	switch (classType)
	{
	case CrewType::eHost:
		pCrew = new CHost(inFile, buffer);
		break;
	case CrewType::ePilot:
		pCrew = new CPilot(inFile, buffer);
		break;
	default:
		break;
	}
	return pCrew;
}

CPlane * CPlaneCrewFactory::GetPlaneFromFile(ifstream & inFile)
{
	char buffer[100];
	int classType;
	CPlane* pPlane = nullptr;

	// Get plane type
	inFile >> buffer;
	classType = atoi(buffer);

	switch (classType)
	{
	case PlaneType::eRegular:
		pPlane = new CPlane(inFile, buffer);
		break;
	case PlaneType::eCargo:
		pPlane = new CCargo(inFile, buffer);
		break;
	default:
		break;
	}
	return pPlane;
}
