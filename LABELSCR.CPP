/*
Function definitions for LabelScreen
*/

# include "labelscr.h"

/************************************************************************/
	LabelScreen::LabelScreen
		(
		const unsigned char winleft_i,
		const unsigned char wintop_i,
		const unsigned char winright_i,
		const unsigned char winbottom_i,
		const unsigned char currmode_i,
		int 				TextColour_i,
		int 				BackColour_i,

		char *Label_i,
		int LabelOffsetX_i,
		int LabelOffsetY_i,
		int	LabelTextColour_i,
		int LabelBackColour_i

		) :

		ATCScreen
			(
			winleft_i,
			wintop_i,
			winright_i,
			winbottom_i,
			currmode_i,
			TextColour_i,
			BackColour_i
			) ,

		LabelOffsetX_c (LabelOffsetX_i),
		LabelOffsetY_c (LabelOffsetY_i),
		LabelTextColour_c (LabelTextColour_i),
		LabelBackColour_c (LabelBackColour_i)	{

			Label_c = new char [strlen (Label_i) + 1];
			strcpy (Label_c, Label_i);
		}

/************************************************************************/
	LabelScreen::~LabelScreen ()	{
		delete Label_c;
	}

/************************************************************************/
	void LabelScreen::Label()	{
		int LabelLeft, LabelTop, LabelRight, LabelBottom;

		if (LabelOffsetX_c < 0)	{
			LabelRight = winleft_c - 1;
			LabelLeft = winleft_c + LabelOffsetX_c;
		} else {
			LabelLeft = winleft_c;
			LabelRight = winleft_c + LabelOffsetX_c;
		}
		if (LabelOffsetY_c > 0)	{
			LabelTop = wintop_c;
			LabelBottom = wintop_c + LabelOffsetY_c;
		} else {
			LabelBottom = wintop_c - 1;
			LabelTop = wintop_c + LabelOffsetY_c;
		}

		window (LabelLeft, LabelTop, LabelRight, LabelBottom);

		textbackground (LabelBackColour_c);
		textcolor  (LabelTextColour_c);

		clrscr();
		cprintf (Label_c);
	}
