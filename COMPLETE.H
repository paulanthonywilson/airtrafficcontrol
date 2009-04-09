/*
Step to complete input

Paul Wilson

*/

# ifndef _COMPLETE_H
# define _COMPLETE_H

# include "withplan.h"

class CompleteInput : public WithPlaneStep	{

public :
	CompleteInput (const WithPlaneStep &Last_i)
		:
		WithPlaneStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	void PromptMsg ();
};

# endif

