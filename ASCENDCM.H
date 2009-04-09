/* Ascend Altitude command class 

version 0.1

Nick Papa  23/04/96.

*/

# ifndef  _ASCENDCMND_H
# define  _ASCENDCMND_H

# include "altcmnd.h"

class  AscendCmnd : public AltCmnd {



public : 
		  AscendCmnd (Plane *pl,int a)
		  :AltCmnd(pl)
							{
							if (pl->CurAlt()+a  > MAXALT )  Altitude_c = MAXALT ;
						  else
							Altitude_c = pl -> CurAlt () + a;
																		}


};

# endif _ASCENDCMND_H
