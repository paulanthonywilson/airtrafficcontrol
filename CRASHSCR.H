/*
Screen to display information about crashed planes

ver 0.0
Paul Wilson
20/4/96

*/

# ifndef _CRASHSCR_H
# define _CRASHSCR_H

# include "stdatc.h"
# include "labelscr.h"
# include "traffic.h"

# define CRASH_INF_LEFT 21
# define CRASH_INF_TOP  33
# define CRASH_INF_RIGHT 61
# define CRASH_INF_BOTTOM 50
# define CRASH_INF_TEXT_COLOUR BLACK
# define CRASH_INF_BACK_COLOUR WHITE

# define CRASH_INF_LABEL "                GAME OVER\n\r               Press space"


class CrashInformation : public LabelScreen	{

private:
	void Refresh();

public:
	CrashInformation ();

	void Display(Traffic *Traff_i);

};

# endif