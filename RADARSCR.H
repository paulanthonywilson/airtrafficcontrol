/*
Class for radar screen

Paul Wilson

ver 0.0
16/4/96

*/

# ifndef _RADARSCR_H
# define _RADARSCR_H


# include "stdatc.h"
# include "atcscree.h"
# include "position.h"
# include "traffic.h"
# include "landmars.h"
# include "flightpa.h"
# include "eiflist.h"
# include "table.h"




# define RADAR_LEFT 4
# define RADAR_TOP  3
# define RADAR_TEXT_COLOUR BLACK
# define RADAR_BACK_COLOUR LIGHTGRAY
# define BOUNDARY_TEXT_COLOUR BLACK
# define BOUNDARY_BACK_COLOUR CYAN
# define FLIGHTPATH_BACK_COLOUR CYAN
# define EMPTY_POSITION_TEXT_COLOUR YELLOW
# define LANDMARK_TEXT_COLOUR BLACK


# define POSITION_WIDTH  2
# define POSITION_HEIGHT 1

# define PROP_COLOUR BLUE
# define JET_COLOUR RED
# define LAST_POS_COLOUR WHITE

# define POSITION_FILL ""
# define PRINT_EMPTY_POSITION " ."
# define PRINT_AIRPORT_LIGHT " *"
# define PRINT_AIRPORT		  "A"
# define PRINT_BEACON 		  "B"
# define PRINT_GATE  		  "E"


class RadarScreen : public ATCScreen	{

private:
	Table   <AtLandmark *, Position> AtLandmarks_c;
	EifList <Gate *> Gates_c;
	EifList <FlightPath *> FlightPaths_c;
	EifList <Position>	AirportLights_c;

	void GotoFieldPosition (Position Pos_i);
	void GotoBoundaryPosition (Position Pos_i);
	Boolean OnFlightPath (Position Pos_i);
	void PrintBackPosition (Position Pos_i);




public :
	RadarScreen (Landmarks *Lands_i);

	void Refresh();

	void UnDisplayPlanes (Traffic *Traff_i);

	void DisplayPlanes (Traffic *Traff_i);

	void Select ();
};

# endif

