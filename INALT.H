/*
Input a change altitude command
*/

# ifndef _INALT_H
# define _INALT_H

# include "withplan.h"
# include "complete.h"
# include "inascend.h"
# include "indescen.h"

class InAltitude :public WithPlaneStep	{

public:
	InAltitude(const WithPlaneStep &Last_i) :
		WithPlaneStep (Last_i)
			{
			PromptMsg();
		}

	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();




};

# endif