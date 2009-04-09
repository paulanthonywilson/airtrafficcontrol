/*
Step to complete input of a delayed command

Paul Wilson

*/

# ifndef _CDELAY_H
# define _CDELAY_H

# include "withplan.h"

class CompleteDelay : public WithPlaneStep	{

protected:
	AtLandmark *DelayAt_c;

public :
	CompleteDelay (const WithPlaneStep &Last_i, AtLandmark *DelayAt_i)
		:
		WithPlaneStep (Last_i),
		DelayAt_c (DelayAt_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	void PromptMsg ();
};

# endif

