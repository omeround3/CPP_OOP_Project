#include "validations.h"
#include "Flight.h"

bool validateFullName(const char * fullName, string& msg) throw(CCompStringException)
{
	bool flag = true;
	if (fullName == nullptr) {
		flag = false;
		msg += "\"nullptr\" is not a valid value as full name\n";
	}
	else {
		if (strlen(fullName) < NAME_MIN_LEN) {
			flag = false;
			msg += "Full-Name lenght must be atleast " + to_string(NAME_MIN_LEN) + " chars long\n";
		}
		//............
	}

	return flag;
}

bool validateMinutes(int minutes, string& msg)
{
	bool flag = true;
	if (minutes < 0) {
		flag = false;
		msg += "Minutes value can't be negative\n";
	}

	return flag;
}
bool validateStreet(const char * streetName, string & msg) throw(CCompStringException)
{
	bool flag = true;
	if (strlen(streetName) < NAME_MIN_LEN) {
		flag = false;
		msg += "Street name lenght must be atleast " + to_string(NAME_MIN_LEN) + " chars long\n";
	}
	return flag;
}
bool validateCity(const char * cityName, string & msg) throw(CCompStringException)
{
	bool flag = true;
	if (strlen(cityName) < CITY_MIN_LEN) {
		flag = false;
		msg += "City name lenght must be atleast " + to_string(NAME_MIN_LEN) + " chars long\n";
	}
	return flag;
}
bool validateHouseNumber(int houseNumber, string & msg) throw(CCompStringException)
{
	bool flag = true;
	if (houseNumber <= 0) {
		flag = false;
		msg += "House number must be a number larger than 0\n";
	}
	return flag;
}

bool validateStrMinLen(const char * str, char * varName, string & msg) throw(CCompStringException)
{
	bool flag = true;
	if (strlen(str) < STR_MIN_LEN) {
		flag = false;
		msg += varName;
		msg += " Must be at least " + to_string(STR_MIN_LEN) + " chars long\n";

	}
	return flag;
}

bool validateStrMaxLen(const char * str, char * varName, string & msg) throw(CCompStringException)
{
	bool flag = true;
	if (strlen(str) > STR_MAX_LEN) {
		flag = false;
		msg += varName;
		msg += " Must be Max " + to_string(STR_MAX_LEN) + " chars long\n";

	}
	return flag;
}

bool validateDest(const char * str, string & msg) throw(CCompStringException)
{
	bool flag = true;
	if (!validateStrMaxLen(str, "flightDest", msg)) {
		flag = false;
	}
	if (!validateStrMinLen(str, "flightDest", msg)) {
		flag = false;
	}
	return flag;
}

bool validateArrayIdx(int idx, int size) throw(CCompLimitException)
{
	bool flag = true;
	if (idx >= size || idx < 0) {
		flag = false;
	}
	return flag;
}

bool validateCrewTakeOff(const CCrewMember** members,int size, int& pilots,int& supers, string& msg)
{
	bool flag = true;
	const CCrewMember *member;

	for (int i = 0; i < size; i++)
	{
		member = members[i];
		if (typeid(*member) == typeid(CPilot))
		{
			++pilots;
		}
		else if (typeid(*member)==typeid(CHost) && strcmp(((CHost *)member)->getType(), "Super") == 0)
		{
			++supers;
		}
		if (member->isInFlight())
		{
			flag = false;
			msg += member->getFullName();
			msg += " is still in flight\n";
		}
	}
	return flag;
}
bool validateFlightTakeOff(const CFlight *flight, string& msg)
{
	int pilots = 0, supers = 0;
	bool flag = true;

	//Check if crew available & count their types (pilot/host-super..) 
	flag = validateCrewTakeOff(flight->getCrewMembers(), flight->getNumCrewMembers(), pilots, supers, msg);

	// Check if condotions for take off are met
	const CPlane* plane = flight->getPlane();

	if (plane)
	{
		if (typeid(*plane) == typeid(CPlane)) // Commercial Flight
		{
			if (pilots != 1)
			{
				flag = false;
				msg += to_string(pilots) + " Pilots assigned to a commercial flight (must be exactly 1)\n";
			}
			if (supers > 1) {
				flag = false;
				msg += to_string(supers) + " Super hosts assigned to a commercial flight (must be 0 or 1)\n";
			}
		}
		else //Cargo Flight
		{
			if (pilots < 1)
			{
				flag = false;
				msg += to_string(pilots) + " Pilots assigned to a cargo flight (must be atleast 1)\n";
			}
		}
	}
	else //No Plane assigned
	{
		flag=false;
		msg += "No Plane assigned to flight ";
		msg += to_string(flight->GetFlightInfo().GetFNum());
		msg += " Yet\n"; // can be done in one row, but we like it this way
	}
	return flag;
}


