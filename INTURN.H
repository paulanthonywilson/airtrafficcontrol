/*
First stage input for a turn command

Paul Wilson
*/

# ifndef _INTURN_H
# define _INTURN_H

# include "withplan.h"
# include "inabstur.h"
# include "inturnto.h"
# include "inreltur.h"

class InTurn : public WithPlaneStep {

public :

	InTurn (const WithPlaneStep &Last_i)	:
		WithPlaneStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif
