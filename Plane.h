#pragma warning(disable : 4996)
#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <ostream>

using namespace std;

class CPlane
{
public:
	CPlane(int serialNumber, int numOfSeats, const char *modelName);
	CPlane(const CPlane& other);
	~CPlane();

	int getSerialNumber();
	char* getModelName();
	int getNumOfSeats();
	void Print(ostream &os);
	bool IsEqual(CPlane& other);

private:
	int serialNumber;
	char* modelName;
	int numOfSeats;
};

#endif // !__PLANE_H
