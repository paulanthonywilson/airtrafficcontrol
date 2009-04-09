/*
Function definitions for InCmndType

*/
# include "incmndty.h"

/**********************************************************************/
	void InCmndType::ProcessInput (char KeyHit_i)	{
		switch (KeyHit_i)	{
			case K_CHANGE_ALTITUDE:
				Echo ("change altitude ");
				Next_c = new InAltitude (*this);
				IsCompleted_c = True;
				break;
			case K_TURN	:
				if (IsAirborne())	{
					Echo ("turn ");
					Next_c = new InTurn (*this);
					IsCompleted_c = True;
				}
				break;
			case K_CIRCLE:
				if (IsAirborne())	{
					Echo ("circle ");
					IsCompleted_c = True;
					Next_c = new InCircle (*this);
				}
				break;
			default:
				;//do nothing
		}
	}


/**********************************************************************/
	void InCmndType::PromptMsg ()	{
		char Msg[60] = "Select (a) change altitude";

		if (IsAirborne())	{
			strcat (Msg, " (t) turn, or (c) circle");
		}

		Out_c->Prompt (Msg);

	}




/**********************************************************************/
	void InCmndType::Undo(){
		CommonUndo();
	}