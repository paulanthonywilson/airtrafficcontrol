/*Playing around with polymorphism, airports and gates

*/

# include "stdatc.h"
# include "airport.h"
# include "gate.h"
# include "beacon.h"

void DestId (Destination *);
void AirportId (Airport *);
void GateId (Gate *);



int main ()	{

	Airport *a1, *a2, *a3;
	Gate *g1, *g2, *g3;
	Destination *d1, *d2, *d3;
	Beacon *b1;

	a1 = new Airport (Position (5,5), 1, D0);

	b1 = new Beacon (Position (4,4), 1);

	g1 = new Gate (Position (0,0), 1, D45);

	AirportId (a1);

	DestId (a1);

	d1 = a1;

	DestId (d1);

	AirportId (d1);

	cout << a1->LandmarkType();

	cout << b1->LandmarkType();

	cout << g1->LandmarkType();

	return 0;
}

void DestId (Destination *d_i)	{

	cout << "\nName of destination is " << d_i->ID() << '\n';
}

void AirportId (Airport *a_i)	{

	cout << "\nName of airport is " << a_i->ID() << '\n';
}


void GateId (Gate *g_i)	{

	cout << "\nName of destination is " << g_i->ID() << '\n';
}

