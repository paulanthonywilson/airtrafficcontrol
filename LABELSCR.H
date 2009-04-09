/*
Screen with a label, starting at top left corner

Paul Wilson
*/

# ifndef _LABELSCR_H
# define _LABELSCR_H

# include "atcscree.h"

class LabelScreen : public ATCScreen	{


protected:

	char *Label_c;
	int LabelTextColour_c;
	int LabelBackColour_c;

	int LabelOffsetX_c;
	int LabelOffsetY_c;


	LabelScreen
		(
		const unsigned char winleft_i, 		//screen coordinates
		const unsigned char wintop_i,
		const unsigned char winright_i,
		const unsigned char winbottom_i,
		const unsigned char currmode_i,
		int 				TextColour_i,
		int 				BackColour_i,
		char *Label_i,						//label coordinates
		int LabelOffsetX_i,
		int LabelOffsetY_i,
		int	LabelTextColour_i = WHITE,
		int LabelBackColour_i = BLUE
		) ;


	~LabelScreen();

	void Label();

};

# endif