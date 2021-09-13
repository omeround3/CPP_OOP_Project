#include "Cargo.h"

CCargo::CCargo(int numOfSeats, const char *modelName, float maxCargoWeight, float maxCargoVolume) : CPlane(numOfSeats, modelName), currentCargoVolume(0),currentCargoWeight(0)
{
	this->setMaxCargoWeight(maxCargoWeight);
	this->setMaxCargoVolume(maxCargoVolume);
}

CCargo::CCargo(ifstream& inFile,char * buffer):CPlane(inFile,buffer,true)
{
	// Read & Set m_Volume 
	inFile >> buffer;
	this->setMaxCargoVolume(atof(buffer));

	// Read & Set m_Weight 
	inFile >> buffer;
	this->setMaxCargoWeight(atof(buffer));

	// Read & Set c_Volume 
	inFile >> buffer;
	this->setCurrentCargoVolume(atof(buffer));

	// Read & Set c_Weight
	inFile >> buffer;
	this->setCurrentCargoWeight(atof(buffer));
}

bool CCargo::Load(float weight, float volume)
{
	float newWeight = this->currentCargoWeight + weight;
	float newVolume = this->currentCargoVolume + volume;
	if (newWeight <= this->maxCargoWeight && newVolume <= this->maxCargoVolume)
	{
		this->setCurrentCargoWeight(newWeight);
		this->setCurrentCargoVolume(newVolume);
		return true;
	}
	return false;
}

void CCargo::setMaxCargoWeight(float val)
{
	string msg;
	if (!validatePositiveNumber(val, "Max Cargo Weight", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->maxCargoWeight = val;
}

void CCargo::setMaxCargoVolume(float val)
{
	string msg;
	if (!validatePositiveNumber(val, "Max Cargo Volume", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->maxCargoVolume = val;
}

void CCargo::setCurrentCargoWeight(float val)
{
	string msg;
	if (!validatePositiveNumber(val, "Current Cargo Weight", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->currentCargoWeight = val;
}

void CCargo::setCurrentCargoVolume(float val)
{
	string msg;
	if (!validatePositiveNumber(val, "Current Cargo Volume", msg)) {
		throw CCompStringException(&msg[0]);
	}
	this->currentCargoVolume = val;
}

void CCargo::TakeOff(int minutes)
{
	cout << "Need to add " << minutes << " minutes to my log book" << endl;
}

CPlane * CCargo::clone() const
{
	return new CCargo(*this);
}

void CCargo::Print(ostream &os, bool isCargo) const
{
	if (typeid(os) == typeid(ofstream)) {
		os << "1 ";
		this->CPlane::Print(os, true);
		os << endl<< this->maxCargoVolume << " " << this->maxCargoWeight << " " << this->currentCargoVolume << " " << this->currentCargoWeight;
	}
	else {
		this->CPlane::Print(os);
		os <<endl<< "Cargo M_vol " << this->maxCargoVolume << " M_Kg " << this->maxCargoWeight << " C_vol " << this->currentCargoVolume << " C_Kg " << this->currentCargoWeight;

	}

}
