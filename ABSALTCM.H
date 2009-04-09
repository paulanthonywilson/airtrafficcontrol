/* Absolute Altitude command class 

version 0.1

Nick Papa  23/04/96.

*/

# ifndef  _ABSALTCMND_H
# define  _ABSALTCMND_H

# include "altcmnd.h"

class  AbsAltCmnd : public AltCmnd {



public : 
		  AbsAltCmnd (Plane *pl,int a)
		  :AltCmnd(pl)
							{

							 Altitude_c = a;

			}



};

# endif _ABSALTCMND_H
