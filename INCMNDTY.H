/*
Selects type of command

*/

# ifndef _INCMNDTY_H
# define _INCMNDTY_H

# include "withplan.h"
# include "incircle.h"
# include "inalt.h"
# include "inturn.h"

class InCmndType :public WithPlaneStep	{

private:
	Boolean IsAirborne()	{
		return Plane_c->CurAlt() != 0;
	}

public:
	InCmndType
		(
		const InputStep &Last_i,
		Plane *Plane_i
		) :
		WithPlaneStep (Last_i, Plane_i)
			{
			PromptMsg();
		}

	void ProcessInput (char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();




};

# endif