/*
Screen to display current score, time, and updates

ver 0.0
Paul Wilson
20/4/96

*/

# ifndef _SCORESCR_H
# define _SCORESCR_H

# include "stdatc.h"
# include "labelscr.h"

# define SCORE_SCR_LEFT 62
# define SCORE_SCR_TOP  33
# define SCORE_SCR_RIGHT 69
# define SCORE_SCR_BOTTOM 34
# define SCORE_SCR_TEXT_COLOUR WHITE
# define SCORE_SCR_BACK_COLOUR BLACK

# define SCORE_SCR_LABEL "  Score"


class ScoreScreen : public LabelScreen	{

private:

	void Refresh();

public:
	ScoreScreen ();


	void Refresh (int NewScore_i);

};

# endif