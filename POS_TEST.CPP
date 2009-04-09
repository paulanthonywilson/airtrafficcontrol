/* Test position class

Paul Wilson

26/3/96

*/

# include <stdio.h>
# include "position.h"
# include "heading.h"


int main (void)	{

	Position P1 (10,10), P2, P3, P4, P5;
	Heading h, h1, h2;

	int Expected;

	printf ("\n\n\nTest\n");
	h = D0;
	Expected = 0;
	do	{
		P2 = P1.NextMove (h);
		printf ("\n%4d%4d\t%4d%4d", P2.X(), P2.Y(),
			P1.AngleTo (P2), Expected);
		assert (h == P1.HeadingTo (P2));
		h++;
		Expected += 45;
	}while (h != D0);

	printf ("\n");

	P2.Set (1,1);

	assert (P2.inArena());
	assert (P2.inField());
	assert (!P2.inBoundary());

	P2 = P2.NextMove (D270);

	assert (P2.inArena());
	assert (!P2.inField());
	assert (P2.inBoundary());

	P2 = P2.NextMove (D270);

	assert (!P2.inArena());
	assert (!P2.inField());
	assert (!P2.inBoundary());

	h1 = P1.HeadingTo (P2);

	h2 = P2.HeadingTo (P1);


	assert (!(&h1 ==  &h2));

	P2 = P1.NextMove (D0);

	P3 = P1.NextMove (D45);

	assert (P2 != P3);

	P1.Set (0,0);

	P2.Set (1,1);

	P3.Set (2,2);

	P4.Set (3,3);

	P5.Set (2,3);

	cout << '\n' <<P1.AngleTo (P2) << '\n';
	cout << '\n' <<P1.AngleTo (P3) << '\n';
	cout << '\n' <<P1.AngleTo (P4) << '\n';
	cout << '\n' <<P1.AngleTo (P5) << '\n';


	return 0;
}