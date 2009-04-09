/*
Function definitions for InformationScree

*/

# include "informat.h"

/***************************************************************************/
	InformationScreen::InformationScreen (Traffic *Traff_i) :
		Traff_c (Traff_i),

		ATCScreen
			(
			INFORM_LEFT,
			INFORM_TOP,
			INFORM_RIGHT,
			INFORM_BOTTOM,
			ATC_TEXT_MODE,
			INFORM_TEXT_COLOUR,
			INFORM_BACK_COLOUR
			)


		{}

/****************************************************************************/
	void InformationScreen::Refresh()	{

		SelectScreen();
		clrscr();
	}