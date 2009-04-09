/*
test driver class for traffic

Paul Wilson

8/4/96

*/


# include "stdatc.h"
# include "airport.h"
# include "gate.h"

# include "traffic.h"


int main()	{


	Traffic t;

	Plane *p;

	Position::MaxX = 20;
	Position::MaxY = 20;

	Airport a2 (Position (5,5), 1, D180);

	p = new Plane ('a' , Vector3D (Position (5,4), D0,1) , Jet, &a2);

	cout <<"\n\n\n";

	p->AlterTargAlt (0);

	t.NewAirborne (p);

	cout << '\n' << t.SafeCnt() << '\t' << t.Crashed();

	t.StepAll();

	cout << '\n' << t.SafeCnt() << '\t' << t.Crashed();

	return 0;

}

/**/

