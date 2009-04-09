/*
Base for steps that may produce delayed commands
*/

# ifndef _DLYBLSTE_H
# define _DLYBLSTE_H

# include "withplan.h"
# include "indelay.h"

class DelayableStep	 : public WithPlaneStep {

protected:

	void Delay ()	{
		Echo ("at ");
		Next_c = new InDelay (*this);
		IsCompleted_c = True;
	}

	DelayableStep (const WithPlaneStep &Last_i)	:
		WithPlaneStep (Last_i)
		{}

};

# endif