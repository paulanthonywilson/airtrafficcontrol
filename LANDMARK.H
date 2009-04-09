/*
Base class for landmarks.

Paul Wilson
ver 0.0

1/4/96

ver 0.1
ID changed from char * to int
1/4/96
PW
*/

# ifndef _LANDMARK_H
# define _LANDMARK_H

# include "position.h"
# include "string.h"

class Landmark {

protected :


	Position GrndPos_c;	// ground position of landmark

	const int ID_c; // name of landmark

public :

	Landmark
	(
	Position,			//not const & to allow use of inArena()
	//const Position &
	int
	);


	int ID();	// returns name of landmark

	Position GrndPos ();	// returns ground position of landmark

	virtual LandmarkTypeId LandmarkType() = DEFERRED;

};

# endif


