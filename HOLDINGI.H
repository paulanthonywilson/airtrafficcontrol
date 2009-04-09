/*
Screen to display information about holding planes

ver 0.0
Paul Wilson
20/4/96

*/

# ifndef _HOLDINGI_H
# define _HOLDINGI_H

# include "stdatc.h"
# include "labelscr.h"
# include "traffic.h"

# define HOLD_INF_LEFT 35
# define HOLD_INF_TOP  32
# define HOLD_INF_RIGHT 55
# define HOLD_INF_BOTTOM 46
# define HOLD_INF_TEXT_COLOUR WHITE
# define HOLD_INF_BACK_COLOUR BLACK

# define HOLD_INF_LABEL "At airports"


class HoldingInformation : public LabelScreen	{

private:
	Traffic *Traff_c;

public:
	HoldingInformation (Traffic *Traff_i);

	void Refresh();

};

# endif