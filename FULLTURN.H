/* Full turn command class

version 0.1

Nick Papa  22/04/96.

*/

# ifndef  _FULLTURNCMND_H
# define  _FULLTURNCMND_H

# include "turncmnd.h"

 class  FullTurnCmnd : public TurnCmnd {

  
  public : 
	  FullTurnCmnd (Plane *pl, Heading hd, AngDir t)
	  :TurnCmnd(pl) {
           
	     h_c = hd;
	     td_c = t;
          }

  };
                
# endif _FULLTURNCMND_H
