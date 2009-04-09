/*
Test for ATC input class

*/


# include "atcinput.h"
# include "cmndinpu.h"

# include "atcstatu.h"


int main ()	{

	textmode (ATC_TEXT_MODE);

	Landmarks l;
	Traffic t;
	Gate g1 (Position (0,  0),  2, D45);
	Airport a1 (Position (10, 10), 1, D0);
	Plane *p1, *p2;

	CmndInput *in;


	l.AddGate (&g1);
	l.AddBeacon (new Beacon (Position (5,5), 1));
	l.AddAirport (&a1);

	p1 = new Plane ('j', g1.NewPlaneCoords(), Jet, &g1);
	p2 = new Plane ('k', a1.NewPlaneCoords(), Jet, &g1);
	t.NewAirborne (p1);
	t.NewAirborne (p2);

	in = new CmndInput (&l, &t);


	while (!ATCStatus::Finished)	{
		in->ProcessInput();
	}


	textmode (C80);
	return 0;

}