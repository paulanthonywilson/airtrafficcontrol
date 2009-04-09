/*
Function definitions for InPlaneStep

*/

# include "inplanes.h"


/***************************************************************************/
	void InPlaneStep::ProcessInput(char KeyHit_i)	{

		char Msg[15];

		Traff_c->SearchKnown (KeyHit_i);

		if (Traff_c->IsFoundKnown())	{
			sprintf (Msg, "Plane %c ", KeyHit_i);
			Echo (Msg);

			IsCompleted_c = True;
			Next_c = new InCmndType (*this, Traff_c->FoundKnown());
		}
	}


/***************************************************************************/
	void InPlaneStep::PromptMsg ()	{
		char Msg[3] = "  ";

		EifIterator AirIt = Traff_c->AirborneIterator();
		EifIterator HoldIt = Traff_c->HoldingIterator();

		Out_c->Prompt ("Select plane from : ");

		while (!AirIt.Finished())	{
			Msg[1] = Traff_c->Airborne (AirIt)->Id();
			Out_c->AddToPrompt (Msg);
			AirIt.Forth();
		}

		while (!HoldIt.Finished())	{
			Msg[1] = Traff_c->Holding (HoldIt)->P()->Id();
			Out_c->AddToPrompt (Msg);
			HoldIt.Forth();
		}

	}



/***************************************************************************/
	void InPlaneStep::Undo()	{
		CommonUndo();
	}
