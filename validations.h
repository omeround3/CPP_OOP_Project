#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include <iostream>
#include <string>
#include "FlightCompException.h"

class CFlight;
#define STR_MIN_LEN 3
#define STR_MAX_LEN 10

#define NAME_MIN_LEN 3
#define STREET_MIN_LEN 3
#define CITY_MIN_LEN 3

using namespace std;

bool validateFullName(const char* fullName, string& msg) throw(CCompStringException);
bool validateFlightTakeOff(const CFlight *flight, string& msg) throw(CCompStringException);
bool validateMinutes(int minutes, string& msg) throw(CCompStringException);
bool validateStreet(const char * streetName, string& msg)throw(CCompStringException);
bool validateCity(const char * cityName, string& msg)throw(CCompStringException);
bool validateHouseNumber(int houseNumber, string& msg)throw(CCompStringException);
bool validateStrMinLen(const char * str, char * varName, string & msg)throw(CCompStringException);
bool validateStrMaxLen(const char * str, char * varName, string & msg)throw(CCompStringException);
bool validateDest(const char * str, string & msg)throw(CCompStringException);
bool validateArrayIdx(int idx,int size)throw(CCompLimitException);


template<class T>
inline bool validatePositiveNumber(T number, char * varName, string & msg)
{
	bool flag = true;
	if (number < 0) {
		flag = false;
		msg += varName;
		msg += " can't be a negative value\n";
	}
	return flag;
}


#endif // !UTILS_H


