/*
Screen to display current score, time, and updates

ver 0.0
Paul Wilson
20/4/96

*/

# ifndef _TIMESCR_H
# define _TIMESCR_H

# include "stdatc.h"
# include "labelscr.h"

# define TIME_SCR_LEFT 62
# define TIME_SCR_TOP  43
# define TIME_SCR_RIGHT 69
# define TIME_SCR_BOTTOM 44
# define TIME_SCR_TEXT_COLOUR WHITE
# define TIME_SCR_BACK_COLOUR BLACK

# define TIME_SCR_LABEL "Seconds"


class TimeScreen : public LabelScreen	{

private:

	int OldTime_c;

	void Refresh();

public:
	TimeScreen ();


	void Refresh (int NewTime_i);

};

# endif