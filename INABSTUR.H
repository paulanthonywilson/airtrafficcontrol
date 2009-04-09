/*
Input absolute turn command
*/

# ifndef _INABSTUR_H
# define _INABSTUR_H

# include "dlyblste.h"
# include "delayorc.h"

class InAbsTurn : public DelayableStep {

	Heading Heading_c;

public :

	InAbsTurn (const WithPlaneStep &Last_i, Heading Heading_i)	:
		DelayableStep (Last_i),
		Heading_c (Heading_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();
};

# endif
