/*
Function definitions for DelayATAirport

*/
# include "atairpor.h"

/**********************************************************************/
	void DelayAtAirport::ProcessInput (char KeyHit_i)	{
		int AirportId;
		Airport *AtAirport;

		if (isdigit (KeyHit_i))	{
			AirportId = int (KeyHit_i) - '0';
			Landmarks_c->Airports.Search (AirportId);
			if (Landmarks_c->Airports.Found())	{

				EchoChar (KeyHit_i);
				EchoChar (' ');
				AtAirport = Landmarks_c->Airports.FoundItem();

				Next_c = new CompleteDelay (*this, AtAirport);
				IsCompleted_c = True;
			}
		}
	}


/**********************************************************************/
	void DelayAtAirport::PromptMsg ()	{
		char Msg[3] = "  ";
		EifIterator AirportIt = Landmarks_c->Airports.Iterator();

		Out_c->Prompt ("Select airport number from :");
		while (!AirportIt.Finished())	{
			Msg[0] = '0' +  Landmarks_c->Airports.Item (AirportIt)->ID();
			Out_c->AddToPrompt (Msg);

			AirportIt.Forth();
		}
	}

/**********************************************************************/
	void DelayAtAirport::Undo() {
		CommonUndo();
	}