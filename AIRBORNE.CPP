/*
Function definitions for InformationScree

*/

# include "airborne.h"

/***************************************************************************/
	AirborneInformation::AirborneInformation (Traffic *Traff_i) :
		Traff_c (Traff_i),

		LabelScreen
			(
			AIR_INF_LEFT,
			AIR_INF_TOP,
			AIR_INF_RIGHT,
			AIR_INF_BOTTOM,
			ATC_TEXT_MODE,
			AIR_INF_TEXT_COLOUR,
			AIR_INF_BACK_COLOUR,


			AIR_INF_LABEL,
			-1, //label right
			AIR_INF_BOTTOM - AIR_INF_TOP
			)


		{}

/****************************************************************************/
	void AirborneInformation::Refresh()	{

		EifIterator AirIt;
		Plane *CrntPlane;
		char Id;
		int Alt;
		int Head;
		char DelayAt[3];
		DelayableCmnd *DCmnd;
		int Fuel;
		char Dest[3];

		Label();

		SelectScreen();
		clrscr();

		cprintf ("   Dest Head Alt Delyd Fuel");
		//        12345678901234567890123456   print guides

		AirIt = Traff_c->AirborneIterator();
		while (!AirIt.Finished())	{
			CrntPlane = Traff_c->Airborne (AirIt);

			Id = CrntPlane->Id();
			Alt = CrntPlane->CurAlt();
			Head = CrntPlane->CurHead().Degrees();

			Traff_c->SearchDelayCmnd (CrntPlane);
			if (Traff_c->IsFoundDelayCmnd())	{
				DCmnd = Traff_c->FoundDelayCmnd();

				LandmarkDesc (DelayAt, DCmnd->At());

			} else {

				*DelayAt = '\0';
			}

			Fuel = CrntPlane->CurFuel();

			LandmarkDesc (Dest, CrntPlane->PDest());

			cprintf ("\r\n%2c%5s%5d%4d%6s%5d",
				Id, Dest, Head, Alt, DelayAt, Fuel);

			AirIt.Forth();
		}

	}
