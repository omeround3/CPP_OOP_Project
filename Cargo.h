#pragma warning(disable : 4996)
#ifndef CARGO_H
#define CARGO_H
#include <iostream>
#include "Plane.h"

using namespace std;

class CCargo : public CPlane
{
public:
	CCargo(int numOfSeats, const char *modelName, float maxCargoWeight, float maxCargoVolume);

	bool Load(float weight, float volume);
	void TakeOff(int minutes);

	virtual void Print(ostream& os) const override;
private:
	float maxCargoWeight;
	float maxCargoVolume;
	float currentCargoWeight;
	float currentCargoVolume;

};

#endif // !CARGO_H

