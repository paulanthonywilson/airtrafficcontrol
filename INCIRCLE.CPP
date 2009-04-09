/*
function definitions for InCircle

*/

# include "incircle.h"
# include "indircircle.h"

/**********************************************************************/
	void InCircle::ProcessInput (char KeyHit_i)	{
		switch (KeyHit_i)	{
			case RETURN:
				NewCmnd_c = new CirclingCmnd (Plane_c, Clockwise);
				IsCmndEntered_c = True;
				IsCompleted_c = True;
				break;
			case K_DELAY :
				NewCmnd_c = new CirclingCmnd (Plane_c, Clockwise);
				Delay();
				break;
			case K_CLOCKWISE:
				Echo ("right (clockwise) ");
				NewCmnd_c = new CirclingCmnd (Plane_c, Clockwise);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;
			case K_ANTICLOCKWISE:
				Echo ("left (anticlockwise) ");
				NewCmnd_c = new CirclingCmnd (Plane_c, AntiClockwise);
				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
				break;
			default:
				;//do nothing
		}
	}


/**********************************************************************/
	void InCircle::PromptMsg ()	{
		Out_c->Prompt (
			"Select (r) clockwise, (l) anticlockwise, (a) delay at, or <return>");
	}


/**********************************************************************/
	void InCircle::Undo()	{
		UndoNewCmnd();
		CommonUndo();
	}
