/*
Screen to display information about planes

ver 0.0
Paul Wilson
20/4/96

*/

# ifndef _INFORMAT_H
# define _INFORMAT_H

# include "stdatc.h"
# include "atcscree.h"
# include "traffic.h"

# define INFORM_LEFT 1
# define INFORM_TOP  34
# define INFORM_RIGHT 79
# define INFORM_BOTTOM 44
# define INFORM_TEXT_COLOUR BLACK
# define INFORM_BACK_COLOUR WHITE


class InformationScreen : public ATCScreen	{

private:
	Traffic *Traff_c;

public:
	InformationScreen (Traffic *Traff_i);

	void Refresh();

};

# endif