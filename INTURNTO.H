/*
Input turn towards command
*/

# ifndef _INTURNTO_H
# define _INTURNTO_H

# include "withplan.h"
# include "intobeac.h"
# include "intogate.h"
# include "intoairp.h"

class InTurnTowards : public WithPlaneStep {


public :

	InTurnTowards (const WithPlaneStep &Last_i)	:
		WithPlaneStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif
