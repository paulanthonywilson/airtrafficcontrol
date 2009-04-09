/*
Input a change altitude command
*/

# ifndef _INDESCEN_H
# define _INDESCEN_H

# include "withplan.h"
# include "complete.h"

class InDescend :public WithPlaneStep	{

public:
	InDescend(const WithPlaneStep &Last_i) :
		WithPlaneStep (Last_i)
			{
			PromptMsg();
		}

	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();




};

# endif