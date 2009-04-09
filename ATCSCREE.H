/*
Base class for ATC  windows

Paul Wilson

ver 0.0
16/4/96

*/


# ifndef _ATCSCREE_H
# define _ATCSCREE_H

# include <conio.h>
# include "stdatc.h"
# include "landmark.h"

# define ATC_TEXT_MODE C4350

class ATCScreen		{

protected:

	const unsigned char winleft_c;        /* left window coordinate */
	const unsigned char wintop_c;         /* top window coordinate */
	const unsigned char winright_c;       /* right window coordinate */
	const unsigned char winbottom_c;      /* bottom window coordinate */
	const unsigned char currmode_c;       /* current video mode:
								 BW40, BW80, C40, C80, or C4350 */

	int TextColour_c;	// Normal text foreground colour
	int BackColour_c;	// Normal background colour;

	void SelectScreen();
public:
	ATCScreen
		(
		const unsigned char winleft_i,
		const unsigned char wintop_i,
		const unsigned char winright_i,
		const unsigned char winbottom_i,
		const unsigned char currmode_i,
		int 				TextColour_i,
		int 				BackColour_i
		);


	virtual void Refresh() = DEFERRED;

	void LandmarkDesc (char *Desc_o, Landmark *Land_i);
};



# endif