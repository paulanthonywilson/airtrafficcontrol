/* test for plane stub */


# include "plane.h"
# include "stdio.h"
# include "airport.h"


int main ()	{


	Plane p;
	Heading h = D0;
	Position pos(10,10);
	Airport *a;
	Vector3D npc;

	Destination *d;
	Landmark *l;

	a = new Airport ( pos, "A1", h);

	d = a;

	printf ("\n\n\nAirport\n");
	cout << d->ID() << '\t' << (d->Dir() == D0) <<'\n';

	cout <<"\nSafe Plane coordinates\n\n";

	cout << "Should be safe:\t";

	cout << d->IsSafeCoords (Vector3D (pos , h + D180, 0)) << '\n';

	cout << "Not safe:\t" << d->IsSafeCoords (Vector3D (pos, h, 0))<< '\n';

	cout << "New plane stuff\n\n";

	npc = d->NewPlaneCoords();

	cout << "X: " << npc.GrndPos.X() << "\tY: " << npc.GrndPos.Y();

	cout << "\tAlt: " << npc.Altitude << '\n';

	cout << "Heading Ok:\t" << (npc.Head == h);

	return 0;

}


