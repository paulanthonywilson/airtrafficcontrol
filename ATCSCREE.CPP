	/*
Function Definitions for ATCScreen ver 0.0
Paul Wilson
*/

# include "atcscree.h"

/**************************************************************************/
	ATCScreen::ATCScreen
		(
		const unsigned char winleft_i,
		const unsigned char wintop_i,
		const unsigned char winright_i,
		const unsigned char winbottom_i,
		const unsigned char currmode_i,
		int 				TextColour_i,
		int 				BackColour_i
		)	:

		winleft_c  	 (winleft_i),
		wintop_c   	 (wintop_i),
		winright_c	 (winright_i),
		winbottom_c	 (winbottom_i),
		currmode_c	 (currmode_i),
		TextColour_c (TextColour_i),
		BackColour_c (BackColour_i)
		{

	# ifndef NDEBUG

		struct text_info ti;
		gettextinfo(&ti);

		assert (ti.currmode == currmode_c);

	# endif
	}

/**************************************************************************/
	void ATCScreen::SelectScreen ()	{

		 window
			(
			winleft_c,
			wintop_c,
			winright_c,
			winbottom_c
			);

		 textcolor (TextColour_c);
		 textbackground (BackColour_c);
	}

/**************************************************************************/
	void ATCScreen::LandmarkDesc (char *Desc_o, Landmark *Land_i)	{

		switch (Land_i->LandmarkType())	{
			case TypeAirport :
				Desc_o[0] = 'A';
				break;

			case TypeBeacon :
				Desc_o[0] = 'B';
				break;

			case TypeGate:
				Desc_o[0] = 'E';
				break;

			default:
				assert (False);
		}

		Desc_o [1] = '0' + Land_i->ID();
		Desc_o [2] = '\0';
	}


