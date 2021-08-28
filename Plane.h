#pragma warning(disable : 4996)
#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <ostream>

using namespace std;

class CPlane
{
public:
	// Constructor
	CPlane(int numOfSeats, const char *modelName);
	// Copy Constructor
	CPlane(const CPlane &other);
	// Desctructor
	~CPlane();

	// Getters
	int getSerialNumber();
	char *getModelName();
	int getNumOfSeats();

	// Class functions
	// void Print(ostream &os);
	// bool IsEqual(CPlane &other);

	// Operators Overloading
	const CPlane &operator=(const CPlane &other);
	bool operator==(const CPlane &other) const;
	const CPlane &operator++();
	CPlane operator++(int);
	friend ostream &operator<<(ostream &os, const CPlane &other);
	
private:
	static int objCounter;
	int serialNumber;
	char *modelName;
	int numOfSeats;
};

#endif // !__PLANE_H