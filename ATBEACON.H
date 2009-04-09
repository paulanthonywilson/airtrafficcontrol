/*
Step to input a beacon for a delayable command to delay at

Paul Wilson

*/

# ifndef _ATBEACON_H
# define _ATBEACON_H

# include "withplan.h"
# include "cdelay.h"

class DelayAtBeacon : public WithPlaneStep	{

public :
	DelayAtBeacon (const WithPlaneStep &Last_i)	:
		WithPlaneStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif

