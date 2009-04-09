/*
function definitions for CmndInput
*/

# include "cmndinpu.h"

/*************************************************************************/
	CmndInput::CmndInput
		(
		Landmarks *Lmarks_i,
		Traffic *Traff_i
		) :

		Traff_c (Traff_i),
		IsCmndToCollect_c (False),
		LastCmnd_c (NULL)

			{
		int GateIx, AirportIx, BeaconIx;
		Gate *CrntGate;
		Airport *CrntAirport;
		Beacon *CrntBeacon;


		Out_c.Refresh();

		for (GateIx = 0; GateIx < Lmarks_i->NoOfGates(); GateIx++)	{
			CrntGate = Lmarks_i->AllGates() [GateIx];

			Landmarks_c.Gates.Add (CrntGate, CrntGate->ID());
		}

		for (AirportIx = 0; AirportIx < Lmarks_i->NoOfAirports(); AirportIx++)	{
			CrntAirport = Lmarks_i->AllAirports() [AirportIx];

			Landmarks_c.Airports.Add (CrntAirport, CrntAirport->ID());
		}

		for (BeaconIx = 0; BeaconIx < Lmarks_i->NoOfBeacons(); BeaconIx++)	{
			CrntBeacon = Lmarks_i->AllBeacons() [BeaconIx];

			Landmarks_c.Beacons.Add (CrntBeacon, CrntBeacon->ID());
		}
		SetForNewCmnd();

	}

/****************************************************************************/
	void CmndInput::SetForNewCmnd()	{
		InPlaneStep *FirstStep =
			new InPlaneStep (&Out_c, &Landmarks_c, Traff_c);
		while (!Step_c.Empty())	{
			delete Step_c.Item();
			Step_c.Remove();
		}
		Step_c.Add (FirstStep);
		LastCmnd_c = NULL;
		IsCmndToCollect_c = False;

		Out_c.Refresh();
		FirstStep->PromptMsg();

	}

/****************************************************************************/
	void CmndInput::ProcessInput()	{

		char KeyHit;
		InputStep *CrntStep = Step_c.Item();


		// cancel current entry if selected plane has been deleted
		if (!CrntStep->IsValid())	{
			SetForNewCmnd();
			CrntStep = Step_c.Item();
		}

		//progress input
		while (kbhit())	{
			KeyHit = getch();

			switch (KeyHit)	{
				case BACKSPACE :
				// go back one (if possible)
					if (Step_c.Count() > 1)	{
						Step_c.Remove();
						delete CrntStep;
						Step_c.Item()->Undo();
					}
					break;

				case ESC :
				// cancel current
					SetForNewCmnd();
					break;

				//special Keys

				case 0 :
					KeyHit = getch();

					switch (KeyHit)	{
						case F10:
						//Quit command
							LastCmnd_c = new ExitCmnd();
							IsCmndToCollect_c = True;
							break;

						// Translate direction keys to ATC Heading keys
						case HOME:
							ProcessNormalKeyHit (K_315);
							break;
						case UP_ARROW:
							ProcessNormalKeyHit (K_0);
							break;
						case PG_UP:
							ProcessNormalKeyHit (K_45);
							break;
						case LEFT_ARROW:
							ProcessNormalKeyHit (K_270);
							break;
						case RIGHT_ARROW:
							ProcessNormalKeyHit (K_90);
							break;
						case END:
							ProcessNormalKeyHit (K_225);
							break;
						case DOWN_ARROW:
							ProcessNormalKeyHit (K_180);
							break;
						case PG_DN:
							ProcessNormalKeyHit (K_135);
							break;
						default :
							;//do nothing
					}
					break;

				default :
					ProcessNormalKeyHit (KeyHit);
			}

			//Deal with any new commands
			if (IsCmndToCollect_c)	{
				if (LastCmnd_c->IsDelayed())	{
					Traff_c->DelayCmnd (((DelayableCmnd *) (LastCmnd_c)));
				} else {
					LastCmnd_c->Execute();
				}
				SetForNewCmnd();
			}
		}
	}

/****************************************************************************/
		void CmndInput::ProcessNormalKeyHit (char KeyHit_i)	{
		// process input to the input area

			InputStep *CrntStep = Step_c.Item();

			CrntStep->ProcessInput(tolower (KeyHit_i));

			if (CrntStep->IsCmndEntered())	{
				LastCmnd_c = CrntStep->NewCmnd();
				IsCmndToCollect_c = True;

			} else if (CrntStep->IsCompleted())	{
				Step_c.Add (CrntStep->Next());
			}

		}

/**********************************************************************/
	void CmndInput::Update()	{
		assert (!Step_c.Empty());

		Step_c.Item()->PromptMsg();
	}
