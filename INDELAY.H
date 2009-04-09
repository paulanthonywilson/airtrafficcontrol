/*
Step to input a delay for a delayable command

Paul Wilson

*/

# ifndef _INDELAY_H
# define _INDELAY_H

# include "withplan.h"
# include "atairport.h"
# include "atbeacon.h"

class InDelay : public WithPlaneStep	{

public :
	InDelay (const WithPlaneStep &Last_i)	:
		WithPlaneStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif

