/*
Function definitions for TimeScreen

*/

# include "timescre.h"

/***************************************************************************/
	TimeScreen::TimeScreen () :

		LabelScreen
			(
			TIME_SCR_LEFT,
			TIME_SCR_TOP,
			TIME_SCR_RIGHT,
			TIME_SCR_BOTTOM,
			ATC_TEXT_MODE,
			TIME_SCR_TEXT_COLOUR,
			TIME_SCR_BACK_COLOUR,


			TIME_SCR_LABEL,
			TIME_SCR_RIGHT - TIME_SCR_LEFT, //label right
			-1
			),
			OldTime_c (-1)


		{}

/****************************************************************************/
	void TimeScreen::Refresh()	{


		Label();

		SelectScreen();
		clrscr();

	}

/****************************************************************************/
	void TimeScreen::Refresh (int Time_i)	{

		if (OldTime_c != Time_i)	{
			Refresh();
			cprintf ("\n\r%7d",Time_i);
			OldTime_c = Time_i;
		}
	}