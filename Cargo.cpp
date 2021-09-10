#include "Cargo.h"

CCargo::CCargo(int numOfSeats, const char * modelName, float maxCargoWeight, float maxCargoVolume):CPlane(numOfSeats, modelName)
{
	this->currentCargoVolume = 0;
	this->currentCargoWeight = 0;
	this->maxCargoWeight = maxCargoWeight;
	this->maxCargoVolume = maxCargoVolume;
}


bool CCargo::Load(float weight, float volume)
{
	float newWeight = this->currentCargoWeight + weight;
	float newVolume = this->currentCargoVolume + volume;
	if (newWeight <= this->maxCargoWeight && newVolume <= this->maxCargoVolume) {
		this->currentCargoWeight = newWeight;
		this->currentCargoVolume = newVolume;
		return true;
	}
	return false;
}

void CCargo::TakeOff(int minutes)
{
	cout << "Need to add " << minutes << " minutes to my log book" << endl;
}

void CCargo::Print(ostream & os) const
{
	this->CPlane::Print(os);
	os << "Cargo M_vol " << 
		this->maxCargoVolume << " M_Kg " << 
		this->maxCargoWeight << " C_vol " << 
		this->currentCargoVolume << " C_Kg " << 
		this->currentCargoWeight << endl;;


}
