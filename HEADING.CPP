/*
Function definitions for class Heading ver 0.3
Paul Wilson
1/5/96
*/


# include "heading.h"

	int Heading::HeadVal (int IntVal_i)	{

		return  (MAX_HEAD_P_1 + (IntVal_i % MAX_HEAD_P_1)) % MAX_HEAD_P_1;
	}

	Heading::Heading ( const int NewHead_i)	{

		//Multiple mod division to deal with negative integers
		Value_c = HeadVal (NewHead_i);

	}

	Heading::Heading ( const Heading &NewHead_i)	{

		Value_c = NewHead_i.Value_c;
	}

	Heading &Heading::operator = (const Heading &NewHead_i)	{

		Value_c = NewHead_i.Value_c;
		return *this;
	}

	Heading &Heading::operator += (const Heading &Right_i)	{

		Value_c = HeadVal (Value_c + Right_i.Value_c);
		return *this;
	}

	Heading &Heading::operator -= (const Heading &Right_i)	{

		Value_c = HeadVal (Value_c - Right_i.Value_c);
		return *this;
	}

	Heading &Heading::operator - ()	{

		Value_c = HeadVal (- Value_c);
		return *this;
	}

	Heading &Heading::operator + ()	{

		return *this;
	}

	Heading &Heading::operator ++ ()	{ //prefix

		Value_c = HeadVal (Value_c + 1);
		return *this;
	}

	Heading Heading::operator ++(int)	{ //postfix

		Heading OldHead = Value_c;
		Value_c = HeadVal (Value_c + 1);
		return OldHead;
	}

	Heading &Heading::operator --()		{//prefix

		Value_c = HeadVal (Value_c - 1);
		return *this;
	}


	Heading Heading::operator --(int)	{//postfix

		Heading OldHead = Value_c;
		Value_c = HeadVal (Value_c - 1);
		return OldHead;
	}

	int Heading::Degrees()	{
	// returns the heading value in degrees

		switch (Value_c)	{
			case 0:
				return 0;
			case 1:
				return 45;
			case 2:
				return 90;
			case 3:
				return 135;
			case 4:
				return 180;
			case 5:
				return 225;
			case 6:
				return 270;
			case 7:
				return 315;
			default:
				assert (False);
				return 0;
		}
	}


	Heading Heading::DegToHeading(int Degrees)	{

		int HeadingValue_c; // the integer value of the heading to the position

		// round to nearest HeadingValue_c
		HeadingValue_c = (Degrees + DEG_HALF_STEP) / DEG_STEP;

		//ensure no heading overflow
		HeadingValue_c = HeadingValue_c % 8;

		return HeadingValue_c;
	}

	Heading operator +
		(
		const Heading &Left_i,
		const Heading &Right_i
		)	{

		return Heading (Left_i.Value_c + Right_i.Value_c);
	}


	Heading operator -
		(
		const Heading &Left_i,
		const Heading &Right_i
		)	{

		return Heading (Left_i.Value_c - Right_i.Value_c);
	}

	Boolean operator ==
		(
		const Heading &Left_i,
		const Heading &Right_i
		)	{

		return (Left_i.Value_c == Right_i.Value_c);
	}

	Boolean operator !=
		(
		const Heading &Left_i,
		const Heading &Right_i
		)	{

		return (Left_i.Value_c != Right_i.Value_c);
	}


	Boolean operator >
		(
		const Heading &Left_i,
		const Heading &Right_i
		)	{

		return (Left_i.Value_c > Right_i.Value_c);
	}

	Boolean operator >=
		(const Heading &Left_i,
		const Heading &Right_i
		)	{

		return (Left_i.Value_c >= Right_i.Value_c);
	}


	Boolean operator <
		(
		const Heading &Left_i,
		const Heading &Right_i
		)	{

		return (Left_i.Value_c < Right_i.Value_c);
	}

	Boolean operator <=
		(
		const Heading &Left_i,
		const Heading &Right_i
		)	{

		return (Left_i.Value_c <= Right_i.Value_c);
	}


