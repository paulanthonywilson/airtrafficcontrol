/*
Screen to display current Updates, time, and updates

ver 0.0
Paul Wilson
20/4/96

*/

# ifndef _UPDATESS_H
# define _UPDATESS_H

# include "stdatc.h"
# include "labelscr.h"

# define UP_SCR_LEFT 62
# define UP_SCR_TOP  38
# define UP_SCR_RIGHT 69
# define UP_SCR_BOTTOM 39
# define UP_SCR_TEXT_COLOUR WHITE
# define UP_SCR_BACK_COLOUR BLACK

# define UP_SCR_LABEL "Updates"


class UpdatesScreen : public LabelScreen	{

private:

	void Refresh();

public:
	UpdatesScreen ();


	void Refresh (int NewUpdates_i);

};

# endif