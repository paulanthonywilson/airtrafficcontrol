/* function definitions for Destination class

Paul Wilson

3/4/96
4/4/96

*/

# include "Destinat.h"

/**************************************************************************/
	Destination::Destination
		(
		Position 		GrndPos_i,
		int				ID_i,
		const Heading 	&Dir_i
		)	:
		Landmark (GrndPos_i, ID_i),
		Dir_c (Dir_i)
		{

		assert (GrndPos_i.NextMove(Dir_c).inField());
	}


/**************************************************************************/
	Heading Destination::Dir()	{

		return Dir_c;
	}


