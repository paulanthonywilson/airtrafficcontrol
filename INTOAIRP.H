/*
Step to input an airport for a plane to turn towards

Paul Wilson

*/

# ifndef _INTOAIRP_H
# define _INTOAIRP_H

# include "withplan.h"
# include "delayorc.h"

class InToAirport : public WithPlaneStep	{

public :
	InToAirport (const WithPlaneStep &Last_i)	:
		WithPlaneStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif

