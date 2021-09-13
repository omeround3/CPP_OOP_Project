#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <ostream>
#include <fstream>
#include "validations.h"

class CCargo;
using namespace std;

class CPlane
{
public:
	friend class CFlight; // only CFlight will be able to use TakeOff

	CPlane(int numOfSeats, const char *modelName);
	CPlane(const CPlane &other);
	CPlane(ifstream& inFile, char * buffer, bool isCargo = false);
	virtual ~CPlane();

	int getSerialNumber()const;
	char *getModelName();
	int getNumOfSeats();

	void setNumOfSeats(int numOfSeats);
	void setModelName(const char* modelName);
	void setSerialNumber(int serialNumber);
	friend void setObjectCounter(int objectCounter);

	virtual void Print(ostream &os, bool isCargo=false) const;
	virtual CPlane* clone() const; 
	const CPlane &operator=(const CPlane &other);
	bool operator==(const CPlane &other) const;
	const CPlane &operator++();
	CPlane operator++(int);
	friend ostream &operator<<(ostream &os, const CPlane &other);
	

private:
	static int objCounter;
	int serialNumber;
	char *modelName = nullptr;
	int numOfSeats;
protected:
	virtual void TakeOff(int minutes) {};
};

#endif // !__PLANE_H