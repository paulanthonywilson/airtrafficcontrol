/*
Function definitions for holding planes

*/

# include "holdingi.h"

/***************************************************************************/
	HoldingInformation::HoldingInformation (Traffic *Traff_i) :
		Traff_c (Traff_i),

		LabelScreen
			(
			HOLD_INF_LEFT,
			HOLD_INF_TOP,
			HOLD_INF_RIGHT,
			HOLD_INF_BOTTOM,
			ATC_TEXT_MODE,
			HOLD_INF_TEXT_COLOUR,
			HOLD_INF_BACK_COLOUR,


			HOLD_INF_LABEL,
			-1,
			HOLD_INF_BOTTOM - HOLD_INF_TOP
			)


		{}

/****************************************************************************/
	void HoldingInformation::Refresh()	{

		EifIterator HoldIt;
		HoldingPlane *CrntPlane;
		char Id;
		char AtAirport[3];
		char Destination[3];
		int UpdatesLeft;

		Label();

		SelectScreen();
		clrscr();

		cprintf ("   Airport Dest Time");
		//        12345678901234567890123456   print guides

		HoldIt = Traff_c->HoldingIterator();
		while (!HoldIt.Finished())	{
			CrntPlane = Traff_c->Holding (HoldIt);

			Id = CrntPlane->P()->Id();

			UpdatesLeft = CrntPlane->UpdatesLeft();

			LandmarkDesc (AtAirport, CrntPlane->At());

			LandmarkDesc (Destination, CrntPlane->P()->PDest());

			cprintf ("\r\n%2c%5s%8s%5d",
				Id, AtAirport, Destination, UpdatesLeft);

			HoldIt.Forth();
		}

	}
