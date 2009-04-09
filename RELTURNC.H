/* Relative turn command class

version 0.1

Nick Papa  22/04/96.

*/

# ifndef  _RELTURNCMND_H
# define  _RELTURNCMND_H

# include "turncmnd.h"

 class  RelTurnCmnd : public TurnCmnd {

  
  public : 
	  RelTurnCmnd (Plane *pl, Heading rh, AngDir t)
	  :TurnCmnd(pl){
		  if (t==AntiClockwise) h_c=pl->CurHead()-rh;
		  else
		  h_c = pl->CurHead () + rh;
		  td_c = t;
          }

  };
                
# endif _RELTURNCMND_H
