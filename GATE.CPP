/*Function definitations for Gate ver 0.2
*/


 # include "gate.h"

 /**************************************************************************/
	Gate::Gate
		(
		Position GrndPos_i,
		int ID_i,
		const Heading &Dir_i
		) :

		Destination (GrndPos_i, ID_i, Dir_i),
		Landmark (GrndPos_i, ID_i)

		{
		assert(GrndPos_i.inBoundary());
	}



 /**************************************************************************/
	Boolean Gate::IsSafeCoords (Vector3D Coords_i)	{

		return
			(
			Coords_i.GrndPos == GrndPos_c &&
			Coords_i.Altitude == EXIT_ALTITUDE
			);

		}

/**************************************************************************/
	Vector3D Gate::NewPlaneCoords ()	{

		return Vector3D (
			GrndPos_c.NextMove (Dir_c),
			Dir_c,
			ENTRY_ALTITUDE
		);
	}

/**************************************************************************/
	PlaneState Gate::NewPlaneState ()	{

		return PlaneAirborne;
	}


/**************************************************************************/
	LandmarkTypeId Gate::LandmarkType ()	{

		return TypeGate;
	}