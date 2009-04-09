/*
function definitions for InAbsTurn

*/

# include "inabstur.h"

/**********************************************************************/
	void InAbsTurn::ProcessInput (char KeyHit_i)	{
		switch (KeyHit_i)	{
			case RETURN :
				NewCmnd_c = new DefaultTurnCmnd (Plane_c, Heading_c);
				IsCompleted_c = True;
				IsCmndEntered_c = True;
				break;

			case K_DELAY :
				NewCmnd_c = new DefaultTurnCmnd (Plane_c, Heading_c);
				Delay();
				break;

			case K_CLOCKWISE :
				Echo ("to the right (clockwise) ");
				NewCmnd_c = new FullTurnCmnd (Plane_c, Heading_c, Clockwise);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			case K_ANTICLOCKWISE:
				Echo ("to the left (anticlockwise) ");
				NewCmnd_c = new FullTurnCmnd (Plane_c, Heading_c,
					 AntiClockwise);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;

			default:
				;//do nothing
		}
	}


/**********************************************************************/
	void InAbsTurn::PromptMsg ()	{
		Out_c->Prompt (
			"Select (r) clockwise, (l) anticlockwise (a) delay, or <RETURN>");
	}


/**********************************************************************/
	void InAbsTurn::Undo()	{
		UndoNewCmnd();
		CommonUndo();
	}