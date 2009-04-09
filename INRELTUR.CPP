/*
function definitions for InRelTurn

*/

# include "inreltur.h"

/**********************************************************************/
	void InRelTurn::ProcessInput (char KeyHit_i)	{
		switch (KeyHit_i)	{
			case RETURN :
				NewCmnd_c = new RelTurnCmnd (Plane_c, D45, AngDir_c);
				IsCompleted_c = True;
				IsCmndEntered_c = True;
				break;

			case K_0:
				Echo ("0 degrees ");
				NewCmnd_c = new RelTurnCmnd (Plane_c, D0, AngDir_c);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			case K_45:
				Echo ("45 degrees ");
				NewCmnd_c = new RelTurnCmnd (Plane_c, D45, AngDir_c);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			case K_90:
				Echo ("90 degrees ");
				NewCmnd_c = new RelTurnCmnd (Plane_c, D90, AngDir_c);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			case K_135:
				Echo ("135 degrees ");
				NewCmnd_c = new RelTurnCmnd (Plane_c, D135, AngDir_c);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			case K_180:
				Echo ("180 degrees ");
				NewCmnd_c = new RelTurnCmnd (Plane_c, D180, AngDir_c);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			case K_225:
				Echo ("225 degrees ");
				NewCmnd_c = new RelTurnCmnd (Plane_c, D225, AngDir_c);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			case K_270:
				Echo ("270 degrees ");
				NewCmnd_c = new RelTurnCmnd (Plane_c, D270, AngDir_c);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			case K_315:
				Echo ("315 degrees ");
				NewCmnd_c = new RelTurnCmnd (Plane_c, D315, AngDir_c);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			default:
				;//do nothing
		}
	}


/**********************************************************************/
	void InRelTurn::PromptMsg ()	{
		Out_c->Prompt (
			"Enter a heading, or <return> for 45 degree turn");
	}


/**********************************************************************/
	void InRelTurn::Undo()	{
		UndoNewCmnd();
		CommonUndo();
	}