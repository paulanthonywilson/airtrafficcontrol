/* Class To desribe an plane at an airport awaiting take off.

Simon Hall
ver 0.0
08-04-96
*/

# ifndef _HOLDINGPLANE_H
# define _HOLDINGPLANE_H

# include "plane.h"
# include "airport.h"

# define MAXWAITINGUPDATES 30


class HoldingPlane {

private:
	Plane *P_c;
	Airport *At_c;
	int UpdatesLeft_c;

public :

	HoldingPlane (char pid, Vector3D &v,
		   Aircraft tp, Destination *des,
		   Airport *d){
		   P_c = new Plane(pid, v, tp, des);
		   At_c = d;
		   UpdatesLeft_c = MAXWAITINGUPDATES;
	}

	Plane *P(void){ return  P_c; }

	Airport *At(void){ return  At_c; }

	int UpdatesLeft(void){ return  UpdatesLeft_c; }

	void Step(void){ UpdatesLeft_c--; }

};

# endif _HOLDINGPLANE_H