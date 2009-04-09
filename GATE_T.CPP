/* Development testing for Gate class

Paul Wilson

5/4/96
*/

# include "Gate.h"

int main ()	{

	Gate *g;
	Position p(0,10);
	Heading h (D90);

	g = new Gate (p, "E1", h);

	cout << "\nGate\n";

	cout << g->ID() << '\t';

	cout << (g->Dir() == D90);

	cout <<'\t' << (g->GrndPos()  == p) <<'\n';

	return 0;
}