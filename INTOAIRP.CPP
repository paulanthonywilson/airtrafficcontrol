/*
Function definitions for InToAirport

*/
# include "intoairp.h"

/**********************************************************************/
	void InToAirport::ProcessInput (char KeyHit_i)	{
		char Msg[5];
		int AirportId;
		Airport *ToAirport;

		if (isdigit (KeyHit_i))	{
			AirportId = int (KeyHit_i) - '0';
			Landmarks_c->Airports.Search (AirportId);
			if (Landmarks_c->Airports.Found())	{
				EchoChar (KeyHit_i);
				EchoChar (' ');

				ToAirport = Landmarks_c->Airports.FoundItem();

				NewCmnd_c = new TurnTowardsCmnd (Plane_c, ToAirport);

				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
			}
		}
	}


/**********************************************************************/
	void InToAirport::PromptMsg ()	{
		char Msg[3] = "  ";
		EifIterator AirportIt = Landmarks_c->Airports.Iterator();

		Out_c->Prompt ("Select airport number from :");
		while (!AirportIt.Finished())	{
			Msg[0] =  '0' + Landmarks_c->Airports.Item (AirportIt)->ID();
			Out_c->AddToPrompt (Msg);

			AirportIt.Forth();
		}
	}


/**********************************************************************/
	void InToAirport::Undo()	{
		UndoNewCmnd();
		CommonUndo();
	}
