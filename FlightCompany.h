#pragma warning(disable : 4996)
#ifndef FLIGHTCOMPANY_H
#define FLIGHTCOMPANY_H

#include <string>
#include <ostream>

using namespace std;

class CFlightCompany
{
public:
	CFlightCompany(const char* name);
	CFlightCompany(const CFlightCompany& other);
	~CFlightCompany();

	char* getName();
	void Print(ostream& os);
	void SetName(const char* name); /* This wasn't stated in class definition but function is used in given main */

private:
	char* name;
};

#endif // !FLIGHTCOMPANY_H
