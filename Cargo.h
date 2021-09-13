#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef CARGO_H
#define CARGO_H
#include <iostream>
#include "Plane.h"
#include "validations.h"
using namespace std;

class CCargo : public CPlane
{
public:
	CCargo(int numOfSeats, const char *modelName, float maxCargoWeight, float maxCargoVolume);
	CCargo(ifstream& inFile, char * buffer);

	bool Load(float weight, float volume);

	void setMaxCargoWeight(float val);
	void setMaxCargoVolume(float val);
	void setCurrentCargoWeight(float val);
	void setCurrentCargoVolume(float val);

	
	virtual CPlane* clone() const override;
	virtual void Print(ostream &os, bool isCargo) const override;

private:
	float maxCargoWeight;
	float maxCargoVolume;
	float currentCargoWeight;
	float currentCargoVolume;
	
	void TakeOff(int minutes);

};

#endif // !CARGO_H
