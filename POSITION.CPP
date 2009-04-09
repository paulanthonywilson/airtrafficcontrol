/* function definations for Position class ver 0.1
Paul Wilson
ver 0.0

26/3/96
26/3/96

*/

# include "position.h"


	int Position::MaxX;
	int Position::MaxY;

	Position::Position (const int x_i, const y_i) :
		 X_c (x_i), Y_c (y_i)	{}

	Position::Position (const Position &Other_i)	{

		X_c = Other_i.X_c;
		Y_c = Other_i.Y_c;
	}


	Position  &Position::operator = (const Position &Other_i)	{

		X_c = Other_i.X_c;
		Y_c = Other_i.Y_c;
		return *this;
	}

	Position &Position::Set
		(
		const int x_i,
		const int y_i
		)	{

		 X_c = x_i;
		 Y_c = y_i;
		 return *this;
	}


	Boolean operator == (const Position &Left_i, const Position &Right_i)	{

		return
			Left_i.X_c == Right_i.X_c &&
			Left_i.Y_c == Right_i.Y_c;
	}


	Boolean operator != (const Position &Left_i, const Position &Right_i)	{

		return
			Left_i.X_c != Right_i.X_c ||
			Left_i.Y_c != Right_i.Y_c;
	}


	Boolean Position::inArena (void)	{
		return
			X_c >= 0 && X_c <= MaxX &&
			Y_c >= 0 && Y_c <= MaxY;
	}

	Boolean Position::inField (void)	{
		return
			X_c > 0 && X_c < MaxX &&
			Y_c > 0 && Y_c < MaxY;
	}

	Boolean Position::inBoundary (void)	{
		return
			X_c == 0 || X_c == MaxX ||
			Y_c == 0 || Y_c == MaxY;
	}

	Boolean Position::AdjacentTo(const Position &pos){
		return
			abs(X_c - pos.X_c)<=1 &&
			abs(Y_c - pos.Y_c)<=1;
	}

	Position &Position::NextMove
		(
		Heading const &Head
		)	{

		static Position Next;

		Next = *this;

		if (Head > D270 || Head < D90)
			Next.Y_c++;
		else if (Head < D270 && Head > D90)
			Next.Y_c-- ;
		else
			assert (Head == D270 || Head == D90);

		if (Head > D0 && Head < D180)
			Next.X_c++;
		else if (Head > D180)
			Next.X_c--;
		else
			assert (Head == D0 || Head == D180);

		return Next;


	}


	int Position::AngleTo (const Position &Other_i)	{
		//answer in degrees calculated using tangent

		int DiffX, DiffY;	// The diffence between the other and this position
		float Tangent;
		float Degrees, Radians; // where 370 and 10 degees equivalent
		int RoundDegrees;	// degrees rounded to nearest int between 0 & 359 inc

		assert (*this != Other_i);

		DiffX = Other_i.X_c - X_c;
		DiffY = Other_i.Y_c - Y_c;

		// Avoid division by zero
		if (DiffY == 0)	{
			if (DiffX < 0)
				RoundDegrees = 270;
			else if (DiffX > 0)
				RoundDegrees = 90;
			else // should not be reachable
				assert (False);
		} else	{

			assert (DiffY != 0);
			Tangent = float (DiffX) / float (DiffY);

			// Greater than 270 degrees or less than 90 degrees
			if (DiffY > 0)	{
					Radians = 2 * M_PI + atan (Tangent);

			// Greater than 90 degrees and less than 270 degrees
			} else if (DiffY < 0)
				Radians = M_PI + atan (Tangent);

			else // should not be reachable
				assert (False);

			Degrees = Radians / (2 * M_PI) * 360;

			RoundDegrees = int (Degrees + 0.5) % 360;

		}

		assert (RoundDegrees >= 0 && RoundDegrees <=359);
		return RoundDegrees;

	}


	Heading Position::HeadingTo (const Position &Other_i)	{

		return Heading::DegToHeading (AngleTo (Other_i));
	}

	int Position::X()	{
		return X_c;
	}

	int Position::Y()	{
		return Y_c;
	}