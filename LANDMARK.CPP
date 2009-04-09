/* Function defintions for Landmark ver 0.0

Paul Wilson

1/4/96
1/4/96

*/

# include "landmark.h"

/**************************************************************************/
	Landmark::Landmark
		(
		Position GrndPos_i,	  // not const & to allow use of inArena()
		//const Position &GrndPos_i
		int ID_i
		)	:
		GrndPos_c (GrndPos_i),
		ID_c (ID_i)	{
			assert (GrndPos_i.inArena());
	}

/**************************************************************************/
	int Landmark::ID()	{

		return ID_c;
	}


/**************************************************************************/
	Position Landmark::GrndPos()	{

		return GrndPos_c;
	}