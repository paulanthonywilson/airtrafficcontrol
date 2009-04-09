/*
Flight path class  function definitions ver 0.0
Paul Wilson
5/4/96

*/
# include "flightpa.h"

/***************************************************************************/
	FlightPath::FlightPath
		(
		Position Start_i,
		Position Finish_i
		) :

		Start_c  (Start_i),
		Finish_c (Finish_i),
		AngleToFinish_c (Start_c.AngleTo (Finish_c)),
		DistToFinishSquared_c ((Finish_c.X() - Start_c.X()) *
			(Finish_c.X() - Start_c.X()) + (Finish_c.Y() - Start_c.Y()) *
			(Finish_c.Y() - Start_c.Y()))

		{

		assert (Start_i != Finish_c);
		assert (Start_i.inField());
		assert (Finish_i.inField());
		assert (Start_i.AngleTo (Finish_i) % DEG_STEP == 0);

		}

/***************************************************************************/
	Position FlightPath::Start()	{

		return Start_c;
	}

/***************************************************************************/
	Position FlightPath::Finish()	{

		return Finish_c;
	}

/***************************************************************************/
	Boolean	FlightPath::OnFlightPath (Position Position_i)	{

		Boolean OnAngle, InRange;
		int AngleToPosition;
		int DistToPositionSquared;


		if (Position_i == Start_c)	{
			OnAngle = True;
			InRange = True;
		} else {

			AngleToPosition = Start_c.AngleTo (Position_i);

			OnAngle = (AngleToPosition == AngleToFinish_c);

			if (OnAngle)	{


				DistToPositionSquared = (Position_i.X() - Start_c.X()) *
					(Position_i.X() - Start_c.X())	+
					(Position_i.Y() - Start_c.Y()) *
					(Position_i.Y() - Start_c.Y());

				InRange = (DistToPositionSquared <= DistToFinishSquared_c);

			}
		}
		return OnAngle && InRange;
	}

/**/