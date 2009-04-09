/*
Test for radar screen

ver 0.0

*/

# include <dos.h>
# include <math.h>


# include "radarscr.h"
# include "stdio.h"
# include "gate.h"
# include "eiflist.h"
# include "table.h"
# include "flightpa.h"
# include "landmars.h"


int main ()	{

	textmode (ATC_TEXT_MODE);
	clrscr();

	Position::MaxX = 30;
	Position::MaxY = 30;



	char pid;

	Position::MaxX = 30;
	Position::MaxY = 30;

	RadarScreen *r;
	Landmarks l;

	Traffic t;
	Plane *p1;
	Gate g (Position  (0,  10), 1, D90);
	Gate g1 (Position (0,  0),  2, D45);
	Gate g2 (Position (10, 0),  3, D0);
	Gate g3 (Position (MAX_X, MAX_Y), 4, D225);
//	Gate g4 (Position (10, 0), 4, D0);
	Airport a1 (Position (5, 5), 1, Heading (D90));
	Airport a2 (Position (10, 12), 2, Heading (D45));
	Beacon b1 (Position (7,13), 1);
	Beacon b2 (Position (1,1), 2);
	FlightPath fp (Position (MIN_FIELD_X, MIN_FIELD_Y),
		Position (MAX_FIELD_X, MAX_FIELD_Y));

	FlightPath fp1 (Position (MIN_FIELD_X, MAX_FIELD_Y),
		Position (MAX_FIELD_X, MIN_FIELD_Y));

	FlightPath fp2 (Position (10, 1), Position (10, MAX_FIELD_Y));

	int i;

	l.AddAirport (&a1);

	l.AddAirport (&a2);
	l.AddBeacon (&b1);
	l.AddBeacon (&b2);
	l.AddGate (&g);
	l.AddGate (&g1);
	l.AddGate (&g2);
	l.AddGate (&g3);
//	l.AddGate (&g4);
	l.AddFlightPath (&fp);
	l.AddFlightPath (&fp1);
	l.AddFlightPath (&fp2);

	r = new RadarScreen (&l);

	Boolean Crashed = False;

	r->Refresh();

	pid = t.NewId();

	p1 = new Plane (pid, g.NewPlaneCoords(), Prop, &g1);

	t.NewAirborne (p1);

	p1 = new Plane (t.NewId(), g1.NewPlaneCoords(), Jet, &g);

	t.NewAirborne (p1);


	p1 = new Plane (t.NewId(), g2.NewPlaneCoords(), Jet, &g);

	t.NewAirborne (p1);

	r->DisplayPlanes (&t);

	for (i = 0; i < 34; i++) {
		delay (500);


		if (i == 17)	{
			t.SearchAirborne ('a');
			t.FoundAirborne() -> AlterTargHeading (D270, AntiClockwise);

			t.SearchAirborne ('b');
			t.FoundAirborne() -> MakeCircle (AntiClockwise);
		}
		r->UnDisplayPlanes (&t);

		if (i % 2 == 0)	{
			t.StepJets();
		} else {
			t.StepAll();
		}

		r->DisplayPlanes (&t);

		if (!Crashed && t.Crashed ())	{
				cout << '\a';
			Crashed = True;
		}

	}

	textmode (C80);
	_setcursortype (_NORMALCURSOR);
	clrscr();

	return 0;
}

/**/

