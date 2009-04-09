/* Turn Towards command class

version 0.1

Nick Papa  22/04/96.

*/

# ifndef  _TURNTOWARDSCMND_H
# define  _TURNTOWARDSCMND_H

# include "turncmnd.h"
# include "landmark.h"

 class  TurnTowardsCmnd : public TurnCmnd {
		Landmark *To_c;

  public :
	  TurnTowardsCmnd (Plane *pl, Landmark *la)
	  :TurnCmnd(pl),
		To_c (la)
								{

				 }
	  void  Execute () {

		  if (p_c->CurPos() != To_c->GrndPos())	{

			  h_c =  p_c -> CurPos().HeadingTo(To_c -> GrndPos());

			  if (p_c -> CurHead() - h_c > D180)	{
				td_c = Clockwise;

			  } else {
				td_c = AntiClockwise;
			  }
			TurnCmnd::Execute();
		  }
}

  };

# endif _TURNTOWARDSCMND_H
