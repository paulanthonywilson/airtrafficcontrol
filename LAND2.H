/*
Alternative struct for landmarks

*/

# ifndef _LAND2_H
# define _LAND2_H


# include "gate.h"
# include "airport.h"
# include "beacon.h"
# include "table.h"


struct LandmarkCollection	{

	LandmarkCollection()	:
		Gates (True),
		Airports (True),
		Beacons (True)	{}

	//Landmark tables keyed by Id
	Table <Gate *, int>	Gates;
	Table <Airport *, int> Airports;
	Table <Beacon *, int> Beacons;
};

# endif

