/* Turn command class

version 0.1

Nick Papa  22/04/96.

*/

# ifndef  _TURNCMND_H
# define  _TURNCMND_H

# include "delayabl.h"

 class  TurnCmnd : public DelayableCmnd {

  protected:
	  Heading h_c;
	  AngDir td_c;

  public :
	  TurnCmnd (Plane *pl)
	  :DelayableCmnd (pl)
	 // ,PlaneCmnd (pl), Cmnd()
	  {;}



	 void Execute(void) { p_c->AlterTargHeading (h_c,td_c);}
   };

# endif _TURNCMND_H
