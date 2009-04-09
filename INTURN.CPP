/*
function definitions for InTurn

*/

# include "inturn.h"

/**********************************************************************/
	void InTurn::ProcessInput (char KeyHit_i)	{
		switch (KeyHit_i)	{

			//absolute turns
			case K_0:
				Echo ("to 0 degrees ");
				Next_c = new InAbsTurn (*this, D0);
				IsCompleted_c = True;
				break;

			case K_45:
				Echo ("to 45 degrees ");
				Next_c = new InAbsTurn (*this, D45);
				IsCompleted_c = True;
				break;

			case K_90:
				Echo ("to 90 degrees ");
				Next_c = new InAbsTurn (*this, D90);
				IsCompleted_c = True;
				break;

			case K_135:
				Echo ("to 135 degrees ");
				Next_c = new InAbsTurn (*this, D135);
				IsCompleted_c = True;
				break;

			case K_180:
				Echo ("to 180 degrees ");
				Next_c = new InAbsTurn (*this, D180);
				IsCompleted_c = True;
				break;

			case K_225:
				Echo ("to 225 degrees ");
				Next_c = new InAbsTurn (*this, D225);
				IsCompleted_c = True;
				break;

			case K_270:
				Echo ("to 270 degrees ");
				Next_c = new InAbsTurn (*this, D270);
				IsCompleted_c = True;
				break;

			case K_315:
				Echo ("to 315 degrees ");
				Next_c = new InAbsTurn (*this, D315);
				IsCompleted_c = True;
				break;

			case K_CLOCKWISE :
				Echo ("right (clockwise) by ");
				Next_c = new InRelTurn (*this, Clockwise);
				IsCompleted_c = True;
				break;

			case K_ANTICLOCKWISE:
				Echo ("left (anticlockwise) by ");
				Next_c = new InRelTurn (*this, AntiClockwise);
				IsCompleted_c = True;
				break;
			case K_TOWARDS:
				Echo ("towards ");
				Next_c = new InTurnTowards (*this);
				IsCompleted_c = True;
			default:
				;//do nothing
		}
	}


/**********************************************************************/
	void InTurn::PromptMsg ()	{
		Out_c->Prompt (
			"Select a heading, (r) clockwise, (l) anticlockwise, or (t) towards");

	}

/**********************************************************************/
	void InTurn::Undo()	{
		CommonUndo();
	}

