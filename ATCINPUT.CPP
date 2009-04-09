/*
function definitions for input.h
*/


# include "atcinput.h"

/****************************************************************************/
	ATCInputScreen::ATCInputScreen () :

		//Screen initialisations
		ATCScreen
			(
			1, 	// left
			47, // top
			80, // right
			50, // bottom
			ATC_TEXT_MODE,
			BLACK,
			WHITE
			),
		CrntColumn_c (1),
		PromptColumn_c (1) {}

/****************************************************************************/
	void ATCInputScreen::Cursor()	{
		textcolor (TextColour_c + BLINK);
		cprintf ("_");
		textcolor (TextColour_c);
	}
/****************************************************************************/
	void ATCInputScreen::Select()	{

		_setcursortype(_NOCURSOR);
		SelectScreen();
	}
/****************************************************************************/
	void ATCInputScreen::Refresh ()	{
		SelectScreen();
		clrscr();
		CrntColumn_c = 1;
		Echo ("");

	}

/****************************************************************************/
	void ATCInputScreen::Echo (char *Msg)	{
		Select();

		gotoxy (CrntColumn_c, INPUT_LINE);
		cprintf(Msg);
		CrntColumn_c = wherex();
		Cursor();
	}

/****************************************************************************/
	void ATCInputScreen::ClearEchoBy (int Column_i)	{
		Select();
		CrntColumn_c -= Column_i;
		gotoxy (CrntColumn_c, INPUT_LINE);
		clreol();
		Cursor();

	}

/****************************************************************************/
	void ATCInputScreen::Prompt (char *Msg)	{
		Select();
		gotoxy (1, PROMPT_LINE);
		clreol();
		cprintf (Msg);
		PromptColumn_c = wherex();
	}

/****************************************************************************/
	void ATCInputScreen::AddToPrompt (char *Msg)	{
		Select();
		gotoxy (PromptColumn_c, PROMPT_LINE);
		cprintf (Msg);
		PromptColumn_c = wherex();
	}

/**/