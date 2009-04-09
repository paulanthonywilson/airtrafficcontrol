/*
Function definitions for UpdatesScreen

*/

# include "updatess.h"

/***************************************************************************/
	UpdatesScreen::UpdatesScreen () :

		LabelScreen
			(
			UP_SCR_LEFT,
			UP_SCR_TOP,
			UP_SCR_RIGHT,
			UP_SCR_BOTTOM,
			ATC_TEXT_MODE,
			UP_SCR_TEXT_COLOUR,
			UP_SCR_BACK_COLOUR,


			UP_SCR_LABEL,
			UP_SCR_RIGHT - UP_SCR_LEFT, //label right
			-1
			)


		{}

/****************************************************************************/
	void UpdatesScreen::Refresh()	{


		Label();

		SelectScreen();
		clrscr();

	}

/****************************************************************************/
	void UpdatesScreen::Refresh (int Updates_i)	{
		Refresh();

		cprintf ("\n\r%7d",Updates_i);
	}