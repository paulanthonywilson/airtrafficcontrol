/*
Function definitions for DelayOrCompleteInput

*/
# include "delayorc.h"

/*********************************************************************/
	void DelayOrCompleteInput::ProcessInput(char KeyHit_i)	{
		assert (NewCmnd_c != NULL);

		switch (KeyHit_i)	{
			case RETURN:
				IsCmndEntered_c = True;
				break;

			case K_DELAY:
				Delay();
				break;

			default:
				;//do nothing
		}
	}

/********************************************************************/
	void DelayOrCompleteInput::PromptMsg ()	{
		Out_c->Prompt ("Press (a) delay at, or <return>");
	}


/********************************************************************/
	void DelayOrCompleteInput::Undo()	{
		CommonUndo();
	}