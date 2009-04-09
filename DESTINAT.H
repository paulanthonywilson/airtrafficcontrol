/*
Base class for destinations.  Derived form Landmark (ver 0.0)

Contains function with side effects (NewPlane)

Paul Wilson
ver 0.2
plane information passed as Vector3d structure


1/4/96
7/4/96

ver 0.3
19/4/96

ID changed from char * to int
PW
*/

# ifndef _DESTINATION_H
# define _DESTINATION_H

# include "landmark.h"
# include "vector3d.h"


class Destination : virtual public Landmark {

protected:

	Heading Dir_c;

public :

	Destination
		(
		Position GrndPos_i,
		int ID_i,
		const Heading &Dir_i
		);

	Heading Dir();

	virtual LandmarkTypeId LandmarkType() = DEFERRED;

	virtual Boolean IsSafeCoords (Vector3D) = DEFERRED;

	virtual Vector3D NewPlaneCoords () = DEFERRED;

	virtual PlaneState NewPlaneState() = DEFERRED;
};

# endif





