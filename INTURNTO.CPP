/*
function definitions for turn towards command

*/

# include "inturnto.h"

/**********************************************************************/
	void InTurnTowards::ProcessInput (char KeyHit_i)	{
		switch (KeyHit_i)	{
			case K_BEACON :
				Echo ("beacon ");
				Next_c = new InToBeacon (*this);
				IsCompleted_c = True;
				break;

			case K_GATE :
				Echo ("exit ");
				Next_c = new InToGate (*this);
				IsCompleted_c = True;
				break;

			case K_AIRPORT :
				Echo ("airport ");
				Next_c = new InToAirport (*this);
				IsCompleted_c = True;
				break;

			default:
				;//do nothing
		}
	}


/**********************************************************************/
	void InTurnTowards::PromptMsg ()	{
		char Msg[60] = "Select ";

		if (!Landmarks_c->Gates.Empty())	{
			strcat (Msg, "(e) gate");
			if (!Landmarks_c->Airports.Empty() &&
				!Landmarks_c->Beacons.Empty())	{
				strcat (Msg, ", ");
			}
		}

		if (!Landmarks_c->Beacons.Empty())	{
			strcat (Msg, "(b) beacon");
			if (!Landmarks_c->Airports.Empty())	{
				strcat (Msg, ", ");
			}
		}

		if (!Landmarks_c->Airports.Empty())	{
			strcat (Msg, "(a) airport ");
		}

		Out_c->Prompt (Msg);
	}

/**********************************************************************/
	void InTurnTowards::Undo()	{
		CommonUndo();
	}