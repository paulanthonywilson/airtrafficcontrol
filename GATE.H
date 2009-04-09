/* Class to describe a gate as being a destination where planes can enter
the simulation or exit it.

Simon Hall

ver 0.2
Derived from Destination 0.1

01/04/96
7/4/96 PW

ver 0.3
19/4/96
ID changed from char * to int
PW
*/

# ifndef _GATE_H
# define _GATE_H

# include "stdatc.h"
# include "destinat.h"

# define ENTRY_ALTITUDE 7
# define EXIT_ALTITUDE 9

class Gate : public Destination {

public:
	Gate (Position pos, int id, const Heading &head);

	Boolean IsSafeCoords (Vector3D);

	Vector3D NewPlaneCoords ();

	PlaneState NewPlaneState ();

	LandmarkTypeId LandmarkType();

};

# endif