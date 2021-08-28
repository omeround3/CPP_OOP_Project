#pragma warning(disable : 4996)
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

class CAddress
{
public:
	// Constructor
	CAddress(int houseNumber, const char *streetName, const char *cityName = "Tel Aviv");
	// Copy Constructor
	CAddress(const CAddress &other);
	// Desctructor
	~CAddress();

	// Getters
	const int getHouseNumber();
	const char *getCityName();
	const char *getStreetName();

	// Class functions
	// void Print(ostream& os);
	void UpdateAddress(const char *cityName, const char *streetName, int houseNumber);
	CAddress *GetCurrentAddress();

	// Operators Overloading
	const CAddress &operator=(const CAddress &other);
	bool operator==(const CAddress &other) const;
	bool operator!=(const CAddress &other) const;
	friend ostream &operator<<(ostream &os, const CAddress &other);
	friend istream &operator>>(istream &in, CAddress &other);

private:
	int houseNumber;
	char *cityName;
	char *streetName;
};

#endif // !ADDRESS_H
