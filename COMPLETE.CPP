/*
Function definitions for CompleteInput

*/
# include "complete.h"

/*********************************************************************/
	void CompleteInput::ProcessInput(char KeyHit_i)	{

		if (KeyHit_i == RETURN)	{
			IsCmndEntered_c = True;
		} else {
			;//do nothing
		}
	}

/********************************************************************/
	void CompleteInput::PromptMsg ()	{
		Out_c->Prompt ("Press <return>");
	}

/********************************************************************/
	void CompleteInput::Undo() {
		//cannot be undone
	}

