# include "airport.h"


/**************************************************************************/
	Airport::Airport
		(
		Position GrndPos_i,
		int ID_i,
		const Heading &Dir_i
		)	:
		Destination (GrndPos_i, ID_i, Dir_i),
		AtLandmark (GrndPos_i, ID_i),
		Landmark (GrndPos_i, ID_i)
		{

		assert (GrndPos_i.inField());
	}


/**************************************************************************/
	Boolean Airport::IsSafeCoords(Vector3D Coords_i)	{

	// Note ver 0.4 safe landing direction reversed from previous versions
		return
			(
			Coords_i.GrndPos  == GrndPos_c &&
			Coords_i.Head     == Dir_c &&
			Coords_i.Altitude == LANDING_ALTITUDE
			);
		}


/**************************************************************************/
	Vector3D Airport::NewPlaneCoords ()	{

		return Vector3D (
			GrndPos_c,
			Dir_c,
			TAKEOFF_ALTITUDE
		);
	}


/**************************************************************************/
	PlaneState Airport::NewPlaneState ()	{

		return PlaneHolding;
	}


/**************************************************************************/
	LandmarkTypeId Airport::LandmarkType ()	{

		return TypeAirport;
    }