# include "plane.h"
# include "stdatc.h"
# include "vector3d.h"
# include "airport.h"

int main(){

	Position pos(5,5);
	Heading h(D0);
	Airport *d;

	d = new Airport(pos,"Tim",h);
	Plane *p;
	p = new Plane("PET",Vector3D(pos,h,0),Jet,d);

	return 0;
}