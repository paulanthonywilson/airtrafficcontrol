/*
Function definitions for Plane ver 0.02
*/

# include "plane.h"
# include <math.h>


	int Plane::NextUniqueIx = 100;

	EifList <int> Plane::LiveIx (True);

Plane::Plane (char pid, Vector3D &v,
	const Aircraft tp, Destination *des) :
	Id_c(pid),
	CurPos_c (v.GrndPos),
	CurHead_c (v.Head),
	TargHead_c (v.Head),
	CurAlt_c (v.Altitude),
	TargAlt_c (v.Altitude),
	PType_c (tp),
	PDest_c (des),
	CurFuel_c (MAXFUEL),
	Circling_c (False),
	TurnDir_c (Clockwise),
	UniqueIx_c (NextUniqueIx),
	Status_c	(NotCrashed)
		{
		LiveIx.Add (UniqueIx_c);
		NextUniqueIx++;
	}


	Plane::~Plane ()	{

		LiveIx.Remove (UniqueIx_c);
	}

Boolean Plane::InAirspace(Plane *p){
	if (CurPos_c.AdjacentTo(p->CurPos())
		&& abs(CurAlt_c - p->CurAlt()) <= 1 ) return True;
	return  False;
}


void Plane::Step( void ){
/* changed for ver 0.02 to remove integer conversions to headings
	PW 16/4/96*/

	if ( Circling_c )	{
		if (TurnDir_c == Clockwise)	{
			TargHead_c +=  MaxTurn;
		} else	{
			TRAP (TurnDir_c == AntiClockwise);
			TargHead_c -= MaxTurn;
		}
	}

	if ( TargHead_c != CurHead_c )	{
		if (TurnDir_c == AntiClockwise && (CurHead_c - TargHead_c) > MaxTurn)	{

			//Max anticlockwise turn
			CurHead_c -= MaxTurn;

		} else if (TurnDir_c == Clockwise && TargHead_c - CurHead_c > MaxTurn)	{

			// Max clockwise turn
			CurHead_c += MaxTurn;

		} else	{
//			TRAP (Clockwise ? CurHead_c - TargHead_c <= MaxTurn :
  //				TargHead_c - CurHead_c <= MaxTurn);

			// Full turn
			CurHead_c = TargHead_c;
		}
	}

	CurPos_c = CurPos_c.NextMove ( CurHead_c );

	CurFuel_c--;

	if ( TargAlt_c > CurAlt_c ) CurAlt_c++;

	if ( TargAlt_c < CurAlt_c ) CurAlt_c--;

	TRAP (CurPos_c.inArena());

}

/**/