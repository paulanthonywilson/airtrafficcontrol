/*
Function definitions for RadarScreen

*/

# include "radarscr.h"




	RadarScreen::RadarScreen(Landmarks *Lands_i) :

		ATCScreen
			(
			RADAR_LEFT,
			RADAR_TOP,
			RADAR_LEFT + (MAX_FIELD_X  * POSITION_WIDTH),
			RADAR_TOP  + (MAX_FIELD_Y * POSITION_HEIGHT) - 1,
			ATC_TEXT_MODE,
			RADAR_TEXT_COLOUR,
			RADAR_BACK_COLOUR
			),
		AtLandmarks_c (True, 2),
		Gates_c (True, 2),
		FlightPaths_c (True, 2),
		AirportLights_c (True, 2)


		{
		int BeaconIx, AirportIx, GateIx, FltPthIx;

		AtLandmark *CrntAtLand;
		Airport *CrntAirport;
		Gate *CrntGate;
		FlightPath *CrntFltPth;

		for (BeaconIx = 0; BeaconIx < Lands_i->NoOfBeacons(); BeaconIx++)	{
			CrntAtLand = Lands_i->AllBeacons()[BeaconIx];

			AtLandmarks_c.Add (CrntAtLand, CrntAtLand->GrndPos());
		}

		for (AirportIx = 0; AirportIx < Lands_i->NoOfAirports(); AirportIx++){
			CrntAirport = Lands_i->AllAirports()[AirportIx];

			AtLandmarks_c.Add (CrntAirport, CrntAirport->GrndPos());
			AirportLights_c.Add (CrntAirport->GrndPos().NextMove
				(CrntAirport->Dir()));
		}

		for (GateIx = 0; GateIx < Lands_i->NoOfGates(); GateIx++)	{
			CrntGate = Lands_i->AllGates()[GateIx];

			Gates_c.Add (CrntGate);
		}

		for (FltPthIx = 0; FltPthIx < Lands_i->NoOfFlightPaths(); FltPthIx++){
			CrntFltPth = Lands_i->AllFlightPaths()[FltPthIx];

			FlightPaths_c.Add (CrntFltPth);
		}

	}

/****************************************************************************/
	void RadarScreen::Refresh()	{

		int x, y;
		EifIterator  GateIt;
		EifIterator FlightPathIt;
		EifIterator AtLandmarkIt;
		Gate *CrntGate;
		AtLandmark *CrntAtLndmrk;
		FlightPath *CrntFlightPath;


		//Draw Boundary
		window
			(
			winleft_c   - POSITION_WIDTH,
			wintop_c    - POSITION_HEIGHT,
			winright_c  + POSITION_WIDTH,
			winbottom_c + POSITION_HEIGHT
			);

		textcolor (BOUNDARY_TEXT_COLOUR);
		textbackground (BOUNDARY_BACK_COLOUR);

		clrscr();

		// DrawGates
		GateIt = Gates_c.Iterator();
		while (!GateIt.Finished())	{
			CrntGate = Gates_c.Item (GateIt);

			x = CrntGate->GrndPos().X() * POSITION_WIDTH + 1;
			if (CrntGate->GrndPos().X() == MAX_X)	{
				x++;
			}
			y = (MAX_Y - CrntGate->GrndPos().Y() + 1) * POSITION_HEIGHT;

			gotoxy (x, y);
			cprintf (PRINT_GATE);
			cprintf ("%d", CrntGate->ID());


			GateIt.Forth();
		}

		// Draw radar screen
		Select();
		clrscr();

		for (x = MIN_FIELD_X; x <= MAX_FIELD_X; x++)	{
			for (y = MIN_FIELD_Y; y <= MAX_FIELD_Y; y++)	{
				 PrintBackPosition (Position (x,y));

			}
			assert (True);
		}
	}

/****************************************************************************/
	void RadarScreen::UnDisplayPlanes  (Traffic *Traff_i)	{

		 EifIterator PlaneIt;
		 Plane *CrntPlane;

		 Select();

		 PlaneIt = Traff_i->AirborneIterator();
		 while (!PlaneIt.Finished())	{
			CrntPlane = Traff_i->Airborne (PlaneIt);

			PrintBackPosition (CrntPlane->CurPos());
			PlaneIt.Forth();

		 }



	}

/****************************************************************************/
	void RadarScreen::DisplayPlanes (Traffic *Traff_i)	{

		 EifIterator PlaneIt;
		 Plane *CrntPlane;

		 Select ();

		 PlaneIt = Traff_i->AirborneIterator();
		 while (!PlaneIt.Finished())	{
			CrntPlane = Traff_i->Airborne (PlaneIt);

			if (CrntPlane->CurPos().inField())	{
				GotoFieldPosition (CrntPlane->CurPos());

				if (CrntPlane->PType() == Jet)	{
					textcolor (JET_COLOUR);

				} else {
					assert (CrntPlane->PType() == Prop);
					textcolor (PROP_COLOUR);
				}

			} else {
				GotoFieldPosition (CrntPlane->CurPos().NextMove
					(CrntPlane->CurHead() + D180));
				textcolor (LAST_POS_COLOUR);
			}
			cprintf ("%c%d", CrntPlane->Id(), CrntPlane->CurAlt());

			PlaneIt.Forth();

		 }

	}

/****************************************************************************/
	void RadarScreen::GotoFieldPosition (Position Pos_i)	{

		int x, y;

		x = (Pos_i.X() - 1) * POSITION_WIDTH + 1;
		y = (MAX_Y - Pos_i.Y()) * POSITION_HEIGHT;
		gotoxy (x, y);

		if (OnFlightPath (Pos_i))	{
			textbackground (FLIGHTPATH_BACK_COLOUR);
		} else {
			textbackground (RADAR_BACK_COLOUR);
		}


	}

/****************************************************************************/
	void RadarScreen::Select()	{

		SelectScreen();
		_setcursortype(_NOCURSOR);

	}


/****************************************************************************/
	Boolean RadarScreen::OnFlightPath	(Position Pos_i)	{

		FlightPath	*CrntFlightPath;

		Boolean Result = False;

		EifIterator FlightPathIt = FlightPaths_c.Iterator();
		while (!FlightPathIt.Finished())	{
			CrntFlightPath = FlightPaths_c.Item (FlightPathIt);
			if (CrntFlightPath->OnFlightPath (Pos_i))	{
				Result = True;
				FlightPathIt.Stop();
			} else {
				FlightPathIt.Forth();
			}
		}

		return Result;
	}


/****************************************************************************/
	void RadarScreen::PrintBackPosition (Position Pos_i)	{

		AtLandmark *CrntLandmark;

		GotoFieldPosition (Pos_i);
		AtLandmarks_c.Search (Position (Pos_i));
		if (AtLandmarks_c.Found()) {
			CrntLandmark = AtLandmarks_c.FoundItem();
			textcolor (LANDMARK_TEXT_COLOUR);

			switch	(CrntLandmark->LandmarkType()) {
				case TypeAirport:
					cprintf (PRINT_AIRPORT);
					break;
				case TypeBeacon:
					cprintf (PRINT_BEACON);
					break;
				default :
					assert (False);
			}
			cprintf ("%d",CrntLandmark->ID());

		} else {
			textcolor (EMPTY_POSITION_TEXT_COLOUR);
			AirportLights_c.Search (Pos_i);
			if (AirportLights_c.Found())	{
				cprintf (PRINT_AIRPORT_LIGHT);
			} else {
				cprintf (PRINT_EMPTY_POSITION);
			}
		}
		cprintf (POSITION_FILL);
	}