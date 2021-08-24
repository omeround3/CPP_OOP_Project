#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

#include "Plane.h"
#include "FlightInfo.h"
#include "CrewMember.h"
#include "FlightCompany.h"
#include "Address.h"


int main()
{

	cout << endl << "Checking CFlightCompany" << endl;

	CFlightCompany* pDelta = new CFlightCompany("Delta");
	cout << endl << "First company" << endl;
	pDelta->Print(cout);

	pDelta->SetName("AA");
	cout << endl << "After change name" << endl;
	pDelta->Print(cout);

	CFlightCompany* pComp2 = new CFlightCompany(*pDelta);
	cout << endl << "two companies has the same name" << endl;
	pComp2->Print(cout);

	delete pDelta;
	delete pComp2;

	cout << endl << "Checking CCrewMembwe " << endl;

	CCrewMember*  pCm1 = new CCrewMember("Momo", 125);
	cout << endl << "first Crew Member" << endl;
	pCm1->Print(cout);

	CCrewMember*  pCm2 = new CCrewMember("Gogo");
	cout << endl << "second Crew Member" << endl;
	pCm2->Print(cout);

	if (!pCm2->UpdateMinutes(-14))
		cout << "error update minutes" << endl;

	if (!pCm2->UpdateMinutes(200))
		cout << "error update minutes" << endl;

	{ //dont remove!!!
		cout << endl << "two same crewmembers" << endl;
		CCrewMember temp(*pCm1);
		temp.Print(cout);
		if (temp.IsEqual(*pCm1))
			cout << "*****  EQUALS *****" << endl;
		else
			cout << "*****  NOT EQUALS *****" << endl;

		cout << "*****  Checking Address *****" << endl;
		CAddress a(23, "Alenbi");
		CAddress b(34, "Jafa", "Jerusalem");
		a.Print(cout);
		b.Print(cout);
		b.UpdateAddress("Haifa", "KG", 55);
		b.Print(cout);

	}


	{

		CCrewMember temp = *pCm2;
		temp.Print(cout);
		if (temp.IsEqual(*pCm1))
			cout << "*****  EQUALS *****" << endl;
		else
			cout << "*****  NOT EQUALS *****" << endl;
	}

	delete pCm1;
	delete pCm2;


	cout << endl << "Checking CFlightInfo" << endl;
	CFlightInfo fInfo1("Paris", 343, 320, 5000);
	CFlightInfo fInfo2("Rome", 506, 220, 4000);

	fInfo1.Print(cout);
	fInfo2.Print(cout);

	fInfo2.SetDest("London");
	cout << "Info after change destination" << endl;
	fInfo2.Print(cout);


	cout << endl << "Checking CPlane" << endl;

	CPlane p1(101, 200, "Jumbo");
	CPlane p2(p1);
	CPlane p3 = p1;

	p1.Print(cout);
	p2.Print(cout);
	p3.Print(cout);

	if (p1.IsEqual(p2))
		cout << "*****  EQUALS *****" << endl;
	else
		cout << "*****  NOT EQUALS *****" << endl;

	system("pause");
	return 0;
}
