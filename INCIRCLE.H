/*
First stage in put for circle command
Paul Wilson
*/

# ifndef _INCIRCLE_H
# define _INCIRCLE_H

# include "dlyblste.h"
# include "delayorc.h"

class InCircle : public DelayableStep {

public :

	InCircle (const WithPlaneStep &Last_i)	:
		DelayableStep (Last_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif
