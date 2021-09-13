#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef ADDRESS_H
#define ADDRESS_H

#include "validations.h"
using namespace std;

class CAddress
{
public:
	CAddress(int houseNumber, const char *streetName, const char *cityName = "Tel Aviv") throw(CCompStringException);
	CAddress(const CAddress& other);
	CAddress(ifstream& inFile,char * buffer);
	~CAddress();

	const int getHouseNumber();
	const char *getCityName();
	const char *getStreetName();

	void UpdateAddress(const char *cityName, const char *streetName, int houseNumber) throw(CCompStringException);
	CAddress *GetCurrentAddress();

	const CAddress &operator=(const CAddress &other);
	bool operator==(const CAddress &other) const;
	bool operator!=(const CAddress &other) const;
	friend ostream &operator<<(ostream &os, const CAddress &other);
	friend istream &operator>>(istream &in, CAddress &other) throw(CCompStringException);

private:
	int houseNumber;
	char *cityName =nullptr;
	char *streetName= nullptr;

	void setStreet(const char *streetName) throw(CCompStringException);
	void setCity(const char *cityName) throw(CCompStringException);
	void setNumber(int houseNumber) throw(CCompStringException);
};

#endif // !ADDRESS_H
