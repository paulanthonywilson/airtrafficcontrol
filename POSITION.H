/*
Ground position class for ATC

Paul Wilson

ver 0.1

26/3/96
1/4/96

*/

# ifndef _POSITION_H
# define _POSITION_H

# include <assert.h>
# include <math.h>


# include "stdatc.h"
# include "heading.h"

# define MAX_X   (Position::MaxX)
# define MAX_Y   (Position::MaxY)
# define MIN_FIELD_X 1
# define MAX_FIELD_X (MAX_X - 1)
# define MIN_FIELD_Y 1
# define MAX_FIELD_Y (MAX_Y - 1)


class Position	{

private:

	int X_c, Y_c;

public:

	static int MaxX;

	static int MaxY;

	Position (const int = 0, const int = 0);

	Position (const Position &);

	Position  &operator = (const Position &);

	Position &Set (const int, const int);
	// Set new position coordinates

	friend Boolean operator == (const Position &, const Position &);

	friend Boolean operator != (const Position &, const Position &);

	Boolean inArena ();

	Boolean inField ();

	Boolean inBoundary ();

	Boolean AdjacentTo(const Position &);

	Position &NextMove (const Heading &);

	int AngleTo (const Position &);
	// Positions compared may not be equal

	Heading HeadingTo (const Position &);
	// Positions compared may not be equal

	int X ();

	int Y ();
};

# endif