/*
Screen to display information about airborne planes

ver 0.0
Paul Wilson
20/4/96

*/

# ifndef _AIRBORNE_H
# define _AIRBORNE_H

# include "stdatc.h"
# include "labelscr.h"
# include "traffic.h"

# define AIR_INF_LEFT 4
# define AIR_INF_TOP  32
# define AIR_INF_RIGHT 31
# define AIR_INF_BOTTOM 46
# define AIR_INF_TEXT_COLOUR WHITE
# define AIR_INF_BACK_COLOUR BLACK

# define AIR_INF_LABEL "Airborne"


class AirborneInformation : public LabelScreen	{

private:
	Traffic *Traff_c;

public:
	AirborneInformation (Traffic *Traff_i);

	void Refresh();

};

# endif