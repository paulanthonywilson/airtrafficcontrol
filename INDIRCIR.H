/*
Input circle command with direction already explicity chosen

*/

# ifndef _INDIRCIR_H
# define _INDIRCIR_H

# include "dlyblste.h"


class InDirCircle	: public DelayableStep {

private:
	AngDir TurnDir_c;

public :

	InDirCircle (const WithPlaneStep &Last_i, AngDir TurnDir_i)	:
		DelayableStep (Last_i),
		TurnDir_c (TurnDir_i)
		{
		PromptMsg();
	}


	void ProcessInput (char KeyHit_i);

	void Undo()	{
		assert (NewCmnd_c != NULL);

			delete NewCmnd_c;
			NewCmnd_c = NULL;

		CommonUndo();
	}

	virtual void PromptMsg ();
};


# endif