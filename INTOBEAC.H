/*
Step to input a beacon for a plane to turn towards

Paul Wilson

*/

# ifndef _INTOBEAC_H
# define _INTOBEAC_H

# include "withplan.h"
# include "delayorc.h"

class InToBeacon : public WithPlaneStep	{

public :
	InToBeacon (const WithPlaneStep &Last_i)	:
		WithPlaneStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif

