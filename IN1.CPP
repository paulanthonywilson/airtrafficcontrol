/*
function definitions for input.h
*/


# include "atcinput.h"

/****************************************************************************/
	ATCInput::ATCInput (Traffic *Traff_i, Landmarks *Lmarks_i) :

		//Screen initialisations
		ATCScreen
			(
			1,
			46,
			60,
			50,
			ATC_TEXT_MODE,
			BLACK,
			WHITE
			),
		CrntColumn_c (1),

		Traff_c (Traff_i),
		Gates_c (True),
		Airports_c (True),
		Beacons_c (True),
		NextProcess_c (&GetPlane),
		IsCmndToCollect_c (False),
		LastCmnd_c (NULL)
			{
		int GateIx, AirportIx, BeaconIx;
		Gate *CrntGate;
		Airport *CrntAirport;
		Beacon *CrntBeacon;


		for (GateIx = 0; GateIx < Lmarks_i->NoOfGates(); GateIx++)	{
			CrntGate = Lmarks_i->AllGates() [GateIx];

			Gates_c.Add (CrntGate, CrntGate->ID());
		}

		for (AirportIx = 0; AirportIx < Lmarks_i->NoOfAirports(); AirportIx++)	{
			CrntAirport = Lmarks_i->AllAirports() [AirportIx];

			Airports_c.Add (CrntAirport, CrntAirport->ID());
		}

		for (BeaconIx = 0; BeaconIx < Lmarks_i->NoOfBeacons(); BeaconIx++)	{
			CrntBeacon = Lmarks_i->AllBeacons() [BeaconIx];

			Beacons_c.Add (CrntBeacon, CrntBeacon->ID());
		}
	}
/****************************************************************************/
	void ATCInput::Refresh ()	{
		SelectScreen();
		clrscr();

	}

/****************************************************************************/
	void ATCInput::Echo (char *Msg)	{
		SelectScreen();
		gotoxy (CrntColumn_c, INPUT_LINE);

		cprintf(Msg);
		CrntColumn_c = wherex();
	}

/****************************************************************************
	void ATCInput::ReadyForNewCmnd()	{


/****************************************************************************/
	void ATCInput::ProcessInput()	{

		char KeyHit;

		while (kbhit())	{
			KeyHit = getch();
			(*NextProcess_c )(*this, tolower (KeyHit));
		}
	}
/****************************************************************************/
	void ATCInput::NextProcess (void (*Next_i) (ATCInput &, char))	{
		NextProcess_c = Next_i;
	}

/****************************************************************************/
	Boolean ATCInput::IsCmndToCollect()	{
		return IsCmndToCollect_c;
	}

/****************************************************************************
	Cmnd *LastCmnd();

/****************************************************************************/
	void ATCInput::GetPlane (ATCInput &c, char KeyHit_i)	{
		char Msg[10];
		c.Traff_c->SearchKnown (KeyHit_i);
		if (c.Traff_c->IsFoundKnown())	{
			sprintf (Msg, "Plane %c ", KeyHit_i);
			c.Echo (Msg);

			c.CrntPlane_c = c.Traff_c->FoundKnown();
			c.NextProcess (&GetCmndType);
		}
	}

/****************************************************************************/
	void ATCInput::GetCmndType (ATCInput &c, char KeyHit_i)	{
		switch (KeyHit_i)	{
			case 'a':
				c.TurnDir_c = Clockwise;
				//c.NextProcess (&GetAltCmnd);
				c.Echo ("change altitude ");
				break;
			case 'c':
				c.Echo ("circle ");
				c.NextProcess (&GetCircleCmnd);
				break;
			case 't' :
				c.Echo ("turn ");
				//c.NextProcess_c  (&GetTurnCmnd);
				break;
			default:
				;//do nothing
		}
	}


/****************************************************************************/
	void ATCInput::GetCircleCmnd (ATCInput &c, char KeyHit_i)	{
		switch (KeyHit_i)	{
			case '\r':
			case 'a':
				c.LastCmnd_c = new CirclingCmnd (c.CrntPlane_c, Clockwise);
				c.DelayOrExecute(KeyHit_i);
				break;
			case 'r':
				c.TurnDir_c = Clockwise;
				c.Echo ("right (clockwise) ");
				c.NextProcess (&GetDirCircleCmnd);
				break;
			case 'l':
				c.TurnDir_c = AntiClockwise;
				c.Echo (" left (anticlockwise) ");
				c.NextProcess (&GetDirCircleCmnd);
				break;
			default:
				;//do nothing
		}
	}

/****************************************************************************/
	void ATCInput::GetDirCircleCmnd (ATCInput &c, char KeyHit_i)	{
		switch (KeyHit_i)	{
			case '\r':
			case 'a':
				c.LastCmnd_c = new CirclingCmnd (c.CrntPlane_c, c.TurnDir_c);
				c.DelayOrExecute (KeyHit_i);
				break;
			default:
				;//do nothing
		}
	}


/****************************************************************************/
	void ATCInput::DelayOrExecute (char KeyHit_i)	{
		switch (KeyHit_i)	{
			case '\r':
				CmndComplete();
				break;
			case 'a' :
				if (!(Airports_c.Empty() && Beacons_c.Empty()))	{
					Echo ("delay until ");
					NextProcess (&DelayAt);
					break;
				}
			default:
				assert (False);
		}
	}
/****************************************************************************/
	void ATCInput::DelayAt (ATCInput &c, char KeyHit_i)	{
		switch (KeyHit_i)	{
			case ('b')	:
				if (!c.Beacons_c.Empty())	{
					c.Echo ("beacon ");
					c.NextProcess (&DelayAtBeacon);
				}
				break;
			case ('a')	:
				if (!c.Airports_c.Empty())	{
					c.Echo ("airport ");
					c.NextProcess (&DelayAtAirport);
				}
				break;
			default:
				;//do nothing
		}
	}


/****************************************************************************/
	void ATCInput::CmndComplete()	{
		Refresh();
		IsCmndToCollect_c = True;
	}

/****************************************************************************/
	void ATCInput::DelayAtBeacon (ATCInput &c, char KeyHit_i)	{
		c.Beacons_c.Search (KeyHit_i);
		if (c.Beacons_c.Found())	{
			c.DelayAt_c = c.Beacons_c.FoundItem();

	}

/****************************************************************************/
	void ATCInput::DelayAtAirport (ATCInput &c, char KeyHit_i)	{
	}


/**/