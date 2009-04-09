/* Exit command class

version 0.1

Nick Papa  22/04/96.
ver 0.2
27/4/96
Execution body added PW

*/

# ifndef  _EXITCMND_H
# define  _EXITCMND_H

# include "cmnd.h"
# include "atcstatu.h"

class  ExitCmnd : public Cmnd {

public :
	ExitCmnd (void) {}
	void Execute(void)    {
		ATCStatus::Finished = True;
	}

	CmndType Type()	{
		return Exit;
	}
};

# endif _EXITCMND_H
