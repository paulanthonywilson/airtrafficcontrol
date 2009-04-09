
# include "flightpa.h"

int main  ()	{

	Position Start (15 , 15), Finish (5, 5);

	FlightPath f (Start, Finish);
	Boolean b;

	cout << "\n\n\n\n" << f.Start().X() << '\t' << f.Finish().X() << '\n';

	b = f.OnFlightPath (Start);

	cout << '\n' << b << '\n';

	cout << '\n' << f.OnFlightPath (Finish) << '\n';

	cout << '\n' << f.OnFlightPath (Position (7, 7)) << '\n';

	cout << '\n' << f.OnFlightPath (Position (16,16)) << '\n';

	cout << '\n' << f.OnFlightPath (Position (7, 8)) << '\n';


	return 0;
}

