/* Descend Altitude command class 

version 0.1

Nick Papa  23/04/96.

*/

# ifndef  _DESCENDCMND_H
# define  _DESCENDCMND_H

# include "altcmnd.h"

class  DescendCmnd : public AltCmnd {



public : 
		  DescendCmnd (Plane *pl,int a)
		  :AltCmnd(pl)
							{
							if (pl->CurAlt() <= 0 )  Altitude_c = 0 ;
								else
								  Altitude_c = pl -> CurAlt () - a;
																		}


                             
};

# endif _DESCENDCMND_H
