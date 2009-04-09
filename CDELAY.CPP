/*
Function definitions for CompleteDelay

*/
# include "cdelay.h"

/*********************************************************************/
	void CompleteDelay::ProcessInput(char KeyHit_i)	{
		assert (NewCmnd_c->Type() == Delayable);

		if (KeyHit_i == '\r')	{
			((DelayableCmnd *) (NewCmnd_c))->DelayAt (DelayAt_c);
			IsCmndEntered_c = True;
		} else {
			;//do nothing
		}
	}

/********************************************************************/
	void CompleteDelay::PromptMsg ()	{
		Out_c->Prompt ("Press <return>");
	}


/********************************************************************/
	void CompleteDelay::Undo ()	{
		CommonUndo();
	}