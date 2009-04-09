# include "eiflist.h"


int main ()	{
	EifList<int> l (True);

	l.Add (1);
	l.Add (2);
	l.Add (1);

	l.Remove (2);

	return 0;
}