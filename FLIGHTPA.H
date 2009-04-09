/*
Flight path class

Paul Wilson
ver 0.0

5/4/96

*/

# ifndef _FLIGHTPATH_H
# define _FLIGHTPATH_H

# include "position.h"


class FlightPath {

private :
	Position Start_c;
	Position Finish_c;

	const int AngleToFinish_c;
	const int DistToFinishSquared_c;


public :

	FlightPath (Position, Position);

	Position Start();

	Position Finish();

	Boolean OnFlightPath (Position);

};

# endif


