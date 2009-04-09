/*
function definitions for InAscend

*/

# include "inascend.h"


/**********************************************************************/
	void InAscend::ProcessInput (char KeyHit_i)	{
		char Msg[20];
		int InputAlt;

		if (isdigit (KeyHit_i))	{
			InputAlt = KeyHit_i - '0';

			if (Plane_c->CurAlt() + InputAlt <= MAXALT)	{
				sprintf (Msg, "%d thousand feet", InputAlt);
				Echo (Msg);
				NewCmnd_c = new AscendCmnd (Plane_c, InputAlt);
				Next_c = new CompleteInput (*this);
				IsCompleted_c = True;
			}
		}
	}


/**********************************************************************/
	void InAscend::PromptMsg ()	{
		char Msg[60];
		int MaxInputAlt = MAXALT - Plane_c->CurAlt();

		if (MaxInputAlt > 0)	{
			sprintf (Msg, "Enter altitude up to %d thousand feet",
				MaxInputAlt);
		} else {
			assert (MaxInputAlt == 0);
			sprintf (Msg, "Plane %c is at its ceiling", Plane_c->Id());
		}
		Out_c->Prompt (Msg);
	}
/**********************************************************************/
	void InAscend::Undo (){
		UndoNewCmnd();
		CommonUndo();
	}