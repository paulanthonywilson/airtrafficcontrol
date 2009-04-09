/*
Step to input a gate for a plane to turn towards

Paul Wilson

*/

# ifndef _INTOGATE_H
# define _INTOGATE_H

# include "withplan.h"
# include "delayorc.h"

class InToGate : public WithPlaneStep	{

public :
	InToGate (const WithPlaneStep &Last_i)	:
		WithPlaneStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif

