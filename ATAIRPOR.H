/*
Step to input an airport for a delayable command to delay at

Paul Wilson

*/

# ifndef _ATAIRPORT_H
# define _ATAIRPORT_H

# include "withplan.h"
# include "cdelay.h"

class DelayAtAirport : public WithPlaneStep	{

public :
	DelayAtAirport (const WithPlaneStep &Last_i)	:
		WithPlaneStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif

