/* Altitude command class 

version 0.1

Nick Papa  23/04/96.

*/

# ifndef  _ALTCMND_H
# define  _ALTCMND_H

# include "planecmn.h"
# define MAXALT  9

class  AltCmnd : public PlaneCmnd {

protected:
			 int Altitude_c;

		  AltCmnd (Plane *pl)
		  :PlaneCmnd (pl)  {}

public :
		  void Execute (void) { p_c ->AlterTargAlt (Altitude_c) ;}

		  CmndType Type ()	{
			return Alt;
		  }

};

# endif _ALTCMND_H
