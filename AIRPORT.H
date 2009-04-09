/* Class to describe an airport as being a destination where planes can
enter the simulation or exit it.

Simon Hall


ver 0.2
derived from Destination ver 0.2

01/04/96

7/4/96 PW


ver 0.3
19/4/96
ID changed from char * to int
PW

ver 0.4
4/5/96 PW
Safe landing direction reversed (Specification error)

*/

# ifndef _AIRPORT_H
# define _AIRPORT_H

# include "stdatc.h"
# include "destinat.h"
# include "atlandma.h"

# define TAKEOFF_ALTITUDE 0
# define LANDING_ALTITUDE 0

class Airport : public Destination, public AtLandmark
{

public:
	Airport (Position, int , const Heading &);

	Boolean IsSafeCoords (Vector3D);

	Vector3D NewPlaneCoords ();

	PlaneState NewPlaneState ();

	virtual LandmarkTypeId LandmarkType();
};

# endif _AIRPORT_H
