/*
test for exit command
*/


# include "atcstatu.h"
# include "exitcmnd.h"

int main ()	{

	ExitCmnd c;

	cout << '\n' << ATCStatus::Finished << '\n';

	c.Execute ();

	cout << ATCStatus::Finished << '\n';

	return 0;
}