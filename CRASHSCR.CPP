/*
Function definitions for crash screen
*/

# include "crashscr.h"

/***************************************************************************/
	CrashInformation::CrashInformation () :
		LabelScreen
			(
			CRASH_INF_LEFT,
			CRASH_INF_TOP,
			CRASH_INF_RIGHT,
			CRASH_INF_BOTTOM,
			ATC_TEXT_MODE,
			CRASH_INF_TEXT_COLOUR,
			CRASH_INF_BACK_COLOUR,


			CRASH_INF_LABEL,
			CRASH_INF_RIGHT - CRASH_INF_LEFT, //Label Y offset
			-2,								//   "  X  "

			LIGHTRED + BLINK, //label text colour
			BLACK	// label back colour
			)


		{}

/****************************************************************************/
	void CrashInformation::Refresh()	{


		Label();

		SelectScreen();
		clrscr();


	}

/****************************************************************************/
	void CrashInformation::Display(Traffic *Traff_i)	{
		EifIterator AirIt = Traff_i->AirborneIterator();
		EifIterator HoldIt = Traff_i->HoldingIterator();
		Plane *CrntPlane;
		char c;

		Refresh();

		cprintf ("\n\n");

		while (!AirIt.Finished())	{
			CrntPlane = Traff_i->Airborne (AirIt);

			if (CrntPlane->Status() != NotCrashed)	{
				cprintf ("\n\rPlane %c has ", CrntPlane->Id());

				switch (CrntPlane->Status())	{
					case Collided:
						cprintf ("been in a collision.");
						break;

					case CrashLanded:
						cprintf ("crash landed.");
						break;

					case LeftArena:
						cprintf ("incorrectly left the arena.");
						break;

					case OutOfFuel:
						cprintf ("run out of fuel.");
						break;

					default:
						assert (False);
						break;
				}
			}

			AirIt.Forth();
		}

		while (!HoldIt.Finished())	{
			CrntPlane = Traff_i->Holding (HoldIt)->P();

			if (CrntPlane->Status() == WaitedTooLong)	{
			  cprintf ("\n\rPlane %c has waited at airport too long;",
					CrntPlane->Id());
			  cprintf ("\n\rThe passengers have rioted and wrecked it");
			} else {
				TRAP (CrntPlane->Status() == NotCrashed);
			}
			HoldIt.Forth();
		}
		do {
			c = getch();
		} while (c != ' ');
	}
