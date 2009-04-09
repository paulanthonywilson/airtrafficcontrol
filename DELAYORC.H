/*
Step to complete input

Paul Wilson

*/

# ifndef _DELAYORC_H
# define _DELAYORC_H

# include "dlyblste.h"

class DelayOrCompleteInput : public DelayableStep	{

public :
	DelayOrCompleteInput (const WithPlaneStep &Last_i)
		:
		DelayableStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	void PromptMsg ();
};

# endif

