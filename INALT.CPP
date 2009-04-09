/*
function definitions for InAlt

*/

# include "inalt.h"


/**********************************************************************/
	void InAltitude::ProcessInput (char KeyHit_i)	{
		char Msg[20];
		if (isdigit (KeyHit_i))	{
			sprintf (Msg,"to %c thousand feet", KeyHit_i);
			Echo (Msg);
			NewCmnd_c = new AbsAltCmnd (Plane_c, KeyHit_i - '0');
			Next_c = new CompleteInput (*this);
			IsCompleted_c = True;

		} else	{
			switch (KeyHit_i)	{
				case K_ASCEND :
					Echo ("- climb by ");
					Next_c = new InAscend (*this);
					IsCompleted_c = True;
					break;
				case K_DESCEND :
					Echo ("- descend by ");
					Next_c = new InDescend (*this);
					IsCompleted_c = True;
				default:
					;//do nothing
			}
		}
	}


/**********************************************************************/
	void InAltitude::PromptMsg ()	{
		Out_c->Prompt (
			"Enter an altitude (0 to 9 thousand feet), (c) climb, or (d) descend");
	}

/**********************************************************************/
	void InAltitude::Undo()	{
		UndoNewCmnd();
		CommonUndo();
	}