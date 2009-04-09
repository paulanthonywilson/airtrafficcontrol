/*testing heading class

Paul Wilson

ver 0.1
26/3/96
30/3/96

ver 0.2
Testing for Heading ver 0.3, no equivalence with int.
*/


# include <stdio.h>
# include <iostream.h>
# include <assert.h>

# include "stdatc.h"

# include "heading.h"


int main (void)	{

//	assert (D0 == 0);
//	assert (D45 == 1);

	Heading h1 = D180 , h2, h3, h4;

	cout << "\nTest started:\n";

	h2 = D180;


	assert (h1 == h2);

	assert (h2 == D180);

	h3 = h2 + h1;

	assert (h3 == D0);

	h3 = h2 + D180;

	assert (h3 == D0);


	h3 = D180 + h2;

	assert (h3 == D0);


	h3 = h3 - h2;

	assert (h3 == D180);

	h3 = h3 - D90;

	assert (h3 == D90);

	h3 = D270 - h3;

	assert (h3 == D180);

	assert (!(h3 != D180));

	assert (h3 == D180);

	h1 = D135;

	h2 = D180;

	h3 = D180;

	h4 = D315;

	assert (h1 < h2);

	assert (!(h2 < h1));

	assert (h1 <= h2);

	assert (h4 > h2);

	assert (!(h4 < h2));

	assert (h4 >= h2);

	assert (h2 == h3);

	assert (h2 >= h3);

	assert (h3 < D315);

	assert (h2 <= h3);


	assert (Heading (D0).Degrees() == 0);

	assert (Heading (D315).Degrees() == 315);

	printf ("\nTest completed\n\n");

	return 0;
}

