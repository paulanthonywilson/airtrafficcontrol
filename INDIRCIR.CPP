/*
Function definitions for InDirCircle

*/

# include "indircir.h"

/**********************************************************************/
	void InDirCircle::ProcessInput (char KeyHit_i)	{
		switch (KeyHit_i)	{
			case '\r':
				NewCmnd_c = new CirclingCmnd (Plane_c, TurnDir_c);
				IsCmndEntered_c = True;
				IsCompleted_c = True;
				break;
			case 'a':
				NewCmnd_c = new CirclingCmnd (Plane_c, TurnDir_c);
				Delay();
				break;
			default:
				;//do nothing
		}
	}


/**********************************************************************/
	void InDirCircle::PromptMsg ()	{
		Out_c->Prompt (
			"Select  (a) delay at, or <return>");
	}
