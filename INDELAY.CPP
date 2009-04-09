/*
Function definitions for InDelay

*/
# include "indelay.h"

/**********************************************************************/
	void InDelay::ProcessInput (char KeyHit_i)	{
		switch (KeyHit_i)	{
			case K_AIRPORT:
				if (!Landmarks_c->Airports.Empty())	{
					Echo ("airport ");
					Next_c = new DelayAtAirport (*this);
					IsCompleted_c = True;
				}
				break;
			case K_BEACON:
				if (!Landmarks_c->Beacons.Empty())	{
					Echo ("beacon ");
					Next_c = new DelayAtBeacon (*this);
					IsCompleted_c = True;
				}
				break;
			default:
				;//do nothing
		}
	}


/**********************************************************************/
	void InDelay::PromptMsg ()	{
		char Msg[60] = "Select ";

		if (!Landmarks_c->Beacons.Empty())	{
			strcat (Msg, "(b) beacon");
			if (!Landmarks_c->Airports.Empty())	{
				strcat (Msg, ",");
			}
		}

		if (!Landmarks_c->Airports.Empty())	{
			strcat (Msg, " (a) airport ");
		}

		Out_c->Prompt (Msg);
	}


/**********************************************************************/
	void InDelay::Undo()	{
		CommonUndo();
	}
