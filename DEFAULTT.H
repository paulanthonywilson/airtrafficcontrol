/* Default turn command class

version 0.1

Nick Papa  22/04/96.

ver 0.1
30/4/96
Remove Angdir from initialisation parameters
and resolved angdir on execution

*/

# ifndef  _DEFAULTTURNCMND_H
# define  _DEFAULTTURNCMND_H

# include "turncmnd.h"

 class  DefaultTurnCmnd : public TurnCmnd {


  public :
	  DefaultTurnCmnd (Plane *pl, Heading hd)
	  :TurnCmnd(pl){

			 h_c = hd;
	 }

  void Execute ()	{
	AngDir td;

	if ((h_c - p_c->CurHead()) > D180)	{
		td = AntiClockwise;
	} else {
		td = Clockwise;
	}

	p_c->AlterTargHeading (h_c, td);
  }

};

# endif _DEFAULTTURNCMND_H
