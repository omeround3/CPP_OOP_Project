#pragma warning(disable : 4996)
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <ostream>

using namespace std;

class CAddress
{
public:
	CAddress(int houseNumber, const char *streetName, const char* cityName = "Tel Aviv");
	CAddress(const CAddress& other); /* Even thgouht it is not used, it is needed */
	~CAddress();

	int getHouseNumber();
	char* getCityName();
	char* getStreetName();

	void Print(ostream& os);
	void UpdateAddress(const char* cityName, const char* streetName, int houseNumber);


private:
	int houseNumber;
	char *cityName;
	char *streetName;
};


#endif // !ADDRESS_H
