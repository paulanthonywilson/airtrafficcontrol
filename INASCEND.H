/*
Input a change altitude command
Paul Wilson
*/

# ifndef _INASCEND_H
# define _INASCEND_H

# include "withplan.h"
# include "complete.h"

class InAscend :public WithPlaneStep	{

public:
	InAscend(const WithPlaneStep &Last_i) :
		WithPlaneStep (Last_i)
			{
			PromptMsg();
		}

	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();




};

# endif