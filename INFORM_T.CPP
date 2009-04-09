/*
test for information screen

*/

# include "stdatc.h"
# include "airborne.h"
# include "holdingi.h"
# include "traffic.h"
# include "radarscr.h"
# include "scorescr.h"
# include "updatess.h"
# include "timescre.h"
# include "crashscr.h"

int main()	{

	textmode (ATC_TEXT_MODE);
	textbackground (CYAN);
	clrscr();

	Position::MaxX = 29;
	Position::MaxY = 29;

	AirborneInformation *AI;
	ScoreScreen *SC;
	UpdatesScreen *US;
	HoldingInformation *HI;
	TimeScreen	*TS;
	RadarScreen *r;
	CrashInformation *CS;

	Airport a (Position (5,5), 1, D90);
	Gate g (Position  (0,  10), 1, D90);

	Plane p1 ('a', g.NewPlaneCoords(), Prop, &a);
	HoldingPlane hp1 ('b', g.NewPlaneCoords(), Prop, &g, &a);

	hp1.P()->SetStatus (WaitedTooLong);


	Traffic *t = new Traffic();
	Landmarks *land = new Landmarks();

	t->NewAirborne (&p1);

	t->NewHolding (&hp1);
	r = new RadarScreen(land);

	AI = new AirborneInformation (t);

	HI= new HoldingInformation (t);

	SC = new ScoreScreen();

	US = new UpdatesScreen();

	TS = new TimeScreen();

	CS = new CrashInformation();

	AI->Refresh();

	HI->Refresh();

	r->Refresh();

	SC->Refresh(5);

	US->Refresh (20);

	TS->Refresh (5);

	getch();

	CS->Display (t);

	getch();

	delete r;
	delete t;
	delete land;

	delete AI;
	delete HI;
	delete SC;
	delete TS;

	textmode (C80);
	return 0;
}