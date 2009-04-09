/* Circling command class

version 0.1

Nick Papa  22/04/96.

*/

# ifndef  _CIRCLINGCMND_H
# define  _CIRCLINGCMND_H

# include "delayabl.h"

 class  CirclingCmnd : public DelayableCmnd {

  protected:
	  AngDir td_c;

  public :
	  CirclingCmnd (Plane *pl, AngDir t)
	  :DelayableCmnd (pl) {

          td_c = t;

         }

	 void Execute(void) { p_c->MakeCircle(td_c);}
   };
                
# endif _CIRCLINGCMND_H
