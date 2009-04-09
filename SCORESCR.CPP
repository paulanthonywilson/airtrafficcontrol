/*
Function definitions for ScoreScreen

*/

# include "scorescr.h"

/***************************************************************************/
	ScoreScreen::ScoreScreen () :

		LabelScreen
			(
			SCORE_SCR_LEFT,
			SCORE_SCR_TOP,
			SCORE_SCR_RIGHT,
			SCORE_SCR_BOTTOM,
			ATC_TEXT_MODE,
			SCORE_SCR_TEXT_COLOUR,
			SCORE_SCR_BACK_COLOUR,


			SCORE_SCR_LABEL,
			SCORE_SCR_RIGHT - SCORE_SCR_LEFT, //label right
			-1
			)


		{}

/****************************************************************************/
	void ScoreScreen::Refresh()	{


		Label();

		SelectScreen();
		clrscr();

	}

/****************************************************************************/
	void ScoreScreen::Refresh (int Score_i)	{
		Refresh();

		cprintf ("\n%7d",Score_i);
	}