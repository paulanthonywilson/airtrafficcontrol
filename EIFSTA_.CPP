/*
Test for eiffel style stack

*/

# include "eifstack.h"


int main()	{

	int i;

	EifStack<int> s;

	for (i = 0; i < 10; i++)
		s.Add (i);

	while (!s.Empty())	{
		cout << '\n' << s.Item();
		s.Remove();
	}

	return 0;
}