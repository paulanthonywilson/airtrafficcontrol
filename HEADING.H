/* Class to define a heading in the simulator.  8 step compass heading:
D0 is north (0 degrees) D45 (45 degrees) is North East

Paul Wilson

ver 0.2

24/3/96
1/4/96

ver 0.2

ver 0.3
No (public) equivalence with int
16/4/96 PW

ver 0.31
Function Degrees() added
20/4/96 PW

*/

# ifndef _HEADING_H
# define _HEADING_H


# define MAX_HEAD 7			//The max int value of a heading
# define MAX_HEAD_P_1 8		//The max int value of a heading + 1
# define DEG_STEP 45		//The number of degrees between two adjacent
							//headings
# define DEG_HALF_STEP 23 // Half DEG_HEAD_STEP (rounded up)


# include "stdatc.h"


class Heading	{

private:
	int Value_c;

	static int HeadVal (int IntVal);
	Heading (const int);

public:
	Heading (){}
//	Heading (const int);

	Heading ( const Heading &);

	Heading &operator = (const Heading &);

	Heading &operator += (const Heading &);

	Heading &operator -= (const Heading &);

	Heading &operator - ();
		/* unary minus such that for all int h1, h2;
		 (h1 - h2 ) == (h1 + (-h2));

		Minus Heading 0 (N) is 0 (N); minus heading 6 (W) is 2 (E).
		*/

	Heading &operator + ();

	Heading &operator ++ (); //prefix

	Heading operator ++(int); //postfix

	Heading &operator --();	//prefix

	Heading operator --(int);	//postfix

	int Degrees();
	// returns the heading value in degrees

	friend Heading operator + (const Heading &, const Heading &);

	friend Heading operator -(const Heading &,const Heading &);

	friend Boolean operator == (const Heading &, const Heading &);

	friend Boolean operator != (const Heading &, const Heading &);

	/* <, <=, >, >= compare headings as their integer values
		Heading 0 (N) < Heading NW (7) */

	friend Boolean operator > (const Heading &, const Heading &);

	friend Boolean operator >= (const Heading &, const Heading &);

	friend Boolean operator < (const Heading &, const Heading &);

	friend Boolean operator <= (const Heading &, const Heading &);

	static Heading DegToHeading(int Degrees);
	//returns the nearest Heading to a bearing in degrees

};


/*
Constants preferred for initialising, and heading arithmetic, rather than
integers.

D<degrees> where <degrees> is compass degrees that heading represents. */

const Heading D0   = Heading::DegToHeading (0);
const Heading D45  = Heading::DegToHeading (45);
const Heading D90  = Heading::DegToHeading (90);
const Heading D135 = Heading::DegToHeading (135);
const Heading D180 = Heading::DegToHeading (180);
const Heading D225 = Heading::DegToHeading (225);
const Heading D270 = Heading::DegToHeading (270);
const Heading D315 = Heading::DegToHeading (315);

# endif
