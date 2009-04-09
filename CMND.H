/* Base class for command hierchy

version 0.1

Nick Papa  22/04/96.

ver 0.2
27/4/96 PW
Added CmndType () virtual function


*/

# ifndef  _CMND_H
# define  _CMND_H

# include "stdatc.h"

class  Cmnd  {

public : 
	Cmnd (void) {}
	virtual void Execute (void) = DEFERRED;

	virtual CmndType Type() = DEFERRED;

	virtual Boolean IsDelayed() {
		return False;
	}
};

# endif _CMND_H
