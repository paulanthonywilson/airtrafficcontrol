/*
Input relative turn command
*/

# ifndef _INRELTUR_H
# define _INRELTUR_H

# include "withplan.h"
# include "delayorc.h"

class InRelTurn : public WithPlaneStep {

	AngDir AngDir_c;

public :

	InRelTurn (const WithPlaneStep &Last_i, AngDir AngDir_i)	:
		WithPlaneStep (Last_i),
		AngDir_c (AngDir_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif
