#pragma warning(disable : 4996)
#pragma warning(disable : 4290)
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#define MAX_LEN 100
#include <iostream>
using namespace std;
class CFlightCompException
{
public:
	virtual void Show() const = 0;
};

class CCompStringException : public CFlightCompException
{
	char msg[MAX_LEN];
public:
	CCompStringException(const char*msg) {
		strcpy(this->msg, msg);
	}
	virtual void Show() const override { cout << this->msg; }
};

class CCompLimitException : public CFlightCompException
{
	int limit;
public:
	CCompLimitException(int limit) : limit(limit) {}
	virtual void Show() const override { cout << "Index value out-of-bound (LastIdx: "<<this->limit<<")" << endl; }
};

class CCompFileException : public CFlightCompException
{
	char fileName[MAX_LEN];
public:
	CCompFileException(const char* fileName) {
		strcpy(this->fileName, fileName);
	}
	virtual void Show() const override { cout << "Unknown issue with file " << this->fileName<< endl; }
};


#endif // !EXCEPTIONS_H