/*
function definitions for InDescend

*/

# include "indescen.h"


/**********************************************************************/
	void InDescend::ProcessInput (char KeyHit_i)	{
		char Msg[20];
		int InputAlt;

		if (isdigit (KeyHit_i))	{
			InputAlt = KeyHit_i - '0';

			if (Plane_c->CurAlt() - InputAlt >= 0 )	{
				sprintf (Msg, "%d thousand feet", InputAlt);
				Echo (Msg);
				NewCmnd_c = new DescendCmnd (Plane_c, InputAlt);
				Next_c = new CompleteInput (*this);
				IsCompleted_c = True;
			}
		}
	}


/**********************************************************************/
	void InDescend::PromptMsg ()	{
		char Msg[60];
		int MaxInputAlt = Plane_c->CurAlt();

		if (MaxInputAlt > 0)	{
			sprintf (Msg, "Enter altitude up to %d thousand feet",
				MaxInputAlt);
		} else {
			assert (MaxInputAlt == 0);
			sprintf (Msg, "Plane %c at ground level", Plane_c->Id());
		}
		Out_c->Prompt (Msg);
	}


/**********************************************************************/
	void InDescend::Undo() {
		UndoNewCmnd();
		CommonUndo();
	}
