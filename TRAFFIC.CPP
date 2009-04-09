/*

Function definitions for class Traffic ver 0.0
11/4/96
*/

# include "traffic.h"


/****************************************************************************/
	Traffic::Traffic ()	:
		Airborne_c (True),
		Holding_c (True),
		DCmnds_c (True),
		SafeCnt_c (0),
		Crashed_c (False),
		IsFoundAirborne_c (False),
		IsFoundHolding_c (False),
		IsFoundKnown_c (False),
		IsFoundDelayCmnd_c (False),
		FoundDelayCmnd_c (NULL),
		FoundAirborne_c (NULL),
		FoundHolding_c (NULL),
		FoundKnown_c (NULL),
		LastId_c (MAX_PLANE_ID) //check this
		{}

/****************************************************************************/
	Traffic::~Traffic()	{
		EifIterator HoldIt, AirIt, DCmndIt;

		HoldIt = Holding_c.Iterator();
		while (!HoldIt.Finished())	{
			delete Holding_c.Item (HoldIt)->P();
			delete Holding_c.Item (HoldIt);
			HoldIt.Forth();
		}

		AirIt = Airborne_c.Iterator();
		while (!AirIt.Finished())	{
			delete Airborne_c.Item (AirIt);
			AirIt.Forth();
		}

		DCmndIt = DCmnds_c.Iterator();
		while (!DCmndIt.Finished())	{
			delete DCmnds_c.Item (DCmndIt);
			DCmndIt.Forth();
		}
	}


/****************************************************************************/
	Boolean Traffic::Crashed()	{
		return Crashed_c;
	}

/****************************************************************************/
	Boolean Traffic::Guarded()	{
		return (Airborne_c.Guarded() || Holding_c.Guarded());
}

/****************************************************************************/
	Boolean Traffic::IsFoundDelayCmnd()	{
		return IsFoundDelayCmnd_c;
	}
/****************************************************************************/
	DelayableCmnd *Traffic::FoundDelayCmnd()	{
		return FoundDelayCmnd_c;
	}
/****************************************************************************/
	void Traffic::SearchDelayCmnd (Plane *Plane_i)	{
		DCmnds_c.Search (Plane_i);

		if (DCmnds_c.Found())	{
			FoundDelayCmnd_c = DCmnds_c.FoundItem();
		}
		IsFoundDelayCmnd_c = DCmnds_c.Found();
	}
/****************************************************************************/
	Boolean Traffic::IsFoundAirborne()
	// Last call to SearchAirborne successful
		{
		return IsFoundAirborne_c;
	}

/****************************************************************************/
	Boolean Traffic::IsFoundHolding()
	// Last call to SearchHolding successful
		{
		return IsFoundHolding_c;
	}

/****************************************************************************/
	Boolean Traffic::IsFoundKnown()
	// Last call to SearchKnown successful
		{
		return IsFoundKnown_c;
	}

/****************************************************************************/
	Boolean Traffic::IsFull()
	// No room for any more new planes
		{
		return ((Airborne_c.Count() + Holding_c.Count() > MAX_PLANES));
	}


/****************************************************************************/
	Boolean Traffic::IsStepScheduled (Plane *Plane_i)	{

		return Scheduled_c == AllPlanes	||
			Plane_i->PType() == Scheduled_c;
	}

/****************************************************************************/
	char Traffic::NewId ()
	// the next plane id
		{
		TRAP (!IsFull());

		char Result = LastId_c;
		TRAP (Result >= MIN_PLANE_ID && Result <= MAX_PLANE_ID);

		do	{
			if (Result < MAX_PLANE_ID)	{
				Result++;
			} else	{
				Result = MIN_PLANE_ID;
			}
			//TRAP (Result != LastId_c);

			Airborne_c.Search (Result);
			Holding_c.Search (Result);
		}while (Airborne_c.Found() || Holding_c.Found());

		return Result;
	}

/****************************************************************************/
	HoldingPlane *Traffic::FoundHolding()
	// Plane found in last successful call to SearchHolding
		{
		return FoundHolding_c;
	}

/****************************************************************************/
	HoldingPlane *Traffic::Holding (EifIterator HoldingIt_i)
	// return holding plane at HoldingIt_i
		{
		return Holding_c.Item (HoldingIt_i);
	}

/****************************************************************************/
	EifIterator Traffic::HoldingIterator()
	// return an iterator prepared to traverse all the holding planes
		{
		return Holding_c.Iterator();
	}

/****************************************************************************/
	int Traffic::SafeCnt()
	// number of safe planes this step
		{
		return SafeCnt_c;
	}

/****************************************************************************/
	Plane  *Traffic::FoundKnown()
	// Plane found in last successful call to SearchKnown
		{
		return FoundKnown_c;
	}


/****************************************************************************/
	Plane *Traffic::Airborne (EifIterator PlaneIt_i)
	// return plane at PlaneIt_i
		{
		return Airborne_c.Item (PlaneIt_i);
	}

/****************************************************************************/
	Plane *Traffic::FoundAirborne()
	// Plane found in last successful call to SearchAirborne
		{
		return FoundAirborne_c;
	}

/****************************************************************************/
	EifIterator Traffic::AirborneIterator()
	// return an iterator prepared to traverse all the airborne planes
		{
		return Airborne_c.Iterator();
	}

/****************************************************************************/
	void  Traffic::DelayCmnd (DelayableCmnd *NewCmnd_i)
	// require that command's plane is airborne

		{
		# ifndef NDEBUG

		// check plane is airborne
		Airborne_c.Search (NewCmnd_i->P()->Id());
		TRAP (Airborne_c.Found());
		TRAP (Airborne_c.FoundItem() == NewCmnd_i->P());
		# endif


		// If the plane already has a delayed cmnd get rid of it
		DCmnds_c.Search (NewCmnd_i->P());
		if (DCmnds_c.Found())	{
			delete DCmnds_c.FoundItem();
			DCmnds_c.Remove (NewCmnd_i->P());
		}
		//Add the new command
		DCmnds_c.Add (NewCmnd_i, NewCmnd_i->P());
	}


/****************************************************************************
	void ExecuteCmnd (AltitudeCmnd *ExCmnd_i)
	// require that command's plane is known




/****************************************************************************/
	void Traffic::CrashCheck()
	// check for any planes which have crashed

		{
		TRAP (!Guarded());
		TRAP (!Crashed_c);

		EifIterator AirborneIt;
		EifIterator HoldingIt;
		EifList     <Plane *> Checked (True);
		EifIterator  CheckedIt;
		Plane *CrntPlane, *CheckedPlane;
		HoldingPlane *CrntHolding;

		// go through all airborne planes
		AirborneIt = Airborne_c.Iterator();
		while (!AirborneIt.Finished())	{
			CrntPlane = Airborne_c.Item (AirborneIt);
			TRAP (!CrntPlane->IsSafe());
			TRAP (CrntPlane->CurFuel() >= 0);
			TRAP (CrntPlane->CurAlt()  >= 0);

			// has plane hit the ground, wandered off the field, or ran out
			// of fuel
			if (!CrntPlane->CurPos().inField())  {
				CrntPlane->SetStatus (LeftArena);

			} else if (CrntPlane->CurFuel() == 0) {
				CrntPlane->SetStatus (OutOfFuel);

			} else if ( CrntPlane->CurAlt() == 0)	{
				CrntPlane->SetStatus (CrashLanded);
			}

			// check plane has not collided with another plane
			CheckedIt = Checked.Iterator();
			while (!CheckedIt.Finished())	{
				CheckedPlane = Checked.Item (CheckedIt);

				if (CrntPlane->InAirspace (CheckedPlane))	{
					CrntPlane->SetStatus (Collided);
					CheckedPlane->SetStatus (Collided);
					CheckedIt.Stop();
				}
				CheckedIt.Forth();
			}

			if (CrntPlane->Status() != NotCrashed)	{
				Crashed_c = True;
			}

			Checked.Add (CrntPlane);
			AirborneIt.Forth();
		}
		TRAP (!Airborne_c.Guarded());
		TRAP (!Crashed_c ?Checked.Count() == Airborne_c.Count() : True);

		// go through all holding planes
		HoldingIt = Holding_c.Iterator();
		while (!HoldingIt.Finished())	{
			CrntHolding = Holding_c.Item (HoldingIt);

			// check plane has not waited too long
			if (CrntHolding->UpdatesLeft() == 0)	{
				CrntHolding->P()->SetStatus(WaitedTooLong);
				Crashed_c = True;
			}
			HoldingIt.Forth();
			TRAP (CrntHolding->UpdatesLeft() >= 0);
		}

		TRAP (!Airborne_c.Guarded());
		TRAP (!Guarded());


	}


/****************************************************************************/
	void Traffic::FreeSafePlanes()	{
		TRAP (!Guarded());

		Plane 			         *CrntPlane, *PlaneToFree;
		EifList<Plane *>             SafePlanes (True);
		EifIterator	  SafePlanesIt;
		EifIterator AirborneIt = Airborne_c.Iterator();

		// Record all the safe planes
		while (!AirborneIt.Finished())	{
			CrntPlane = Airborne_c.Item (AirborneIt);
			if (CrntPlane->IsSafe())	{
				SafePlanes.Add (CrntPlane);
			}
			AirborneIt.Forth();
		}

		// remove safeplanes and all record of them
		SafePlanesIt = SafePlanes.Iterator();
		while (!SafePlanesIt.Finished())	{
			PlaneToFree = SafePlanes.Item (SafePlanesIt);
			Airborne_c.Remove (PlaneToFree->Id());
			DCmnds_c.Remove (PlaneToFree);
			delete PlaneToFree;

			SafePlanesIt.Forth();
		}

		//Record the safe plane count
		SafeCnt_c = SafePlanes.Count();

		TRAP (!Guarded());

	}

/****************************************************************************/
	void Traffic::NewAirborne (Plane *NewPlane_i)
	// record a new airborne plane
		{
		TRAP (!IsFull());
		TRAP (!Guarded());

		Airborne_c.Add (NewPlane_i, NewPlane_i->Id());
		LastId_c = NewPlane_i->Id();
	}

/****************************************************************************/
	void Traffic::NewHolding (HoldingPlane *NewPlane_i)
	// record a new holding plane
		{
		TRAP (!IsFull());
		TRAP (!Guarded());

		Holding_c.Add (NewPlane_i, NewPlane_i->P()->Id());
		LastId_c = NewPlane_i->P()->Id();
	}

/****************************************************************************/
	void Traffic::SearchAirborne (char PlaneId_i)
	// Search for PlaneId_i amongst airborne planes and set IsFoundAirborne
	// and FoundAirborne accordingly
		{
		Airborne_c.Search (PlaneId_i);
		IsFoundAirborne_c = Airborne_c.Found();
		FoundAirborne_c = Airborne_c.FoundItem();
	}


/****************************************************************************/
	void Traffic::SearchHolding (char PlaneId_i)
	// Search for PlaneId_i amongst holding planes and set IsFoundHolding
	// and FoundHolding accordingly
		{
		Holding_c.Search (PlaneId_i);
		IsFoundHolding_c = Holding_c.Found();
		FoundHolding_c = Holding_c.FoundItem();
	}


/****************************************************************************/
	void Traffic::SearchKnown (char PlaneId_i)
	// Search for PlaneId_i amongst known planes and set IsFoundKnown
	// and FoundKnown accordingly
		{
		Airborne_c.Search (PlaneId_i);
		if (Airborne_c.Found())	{
			IsFoundKnown_c = True;
			FoundKnown_c = Airborne_c.FoundItem();

		} else {
			Holding_c.Search (PlaneId_i);
			if (Holding_c.Found())	{
				IsFoundKnown_c = True;
				FoundKnown_c = Holding_c.FoundItem()->P();
			} else {
				IsFoundKnown_c = False;
			}
		}
	}


/****************************************************************************/
	void Traffic::StepAll()	{
		TRAP (!Guarded());

		Scheduled_c = AllPlanes;
		StepScheduledPlanes();
	}
/****************************************************************************/
	void Traffic::StepJets()	{
		TRAP (!Guarded());

		Scheduled_c = OnlyJets;
		StepScheduledPlanes();
	}

/****************************************************************************/
	void Traffic::StepScheduledPlanes()
	// Step planes that are scheduled to move
		{
		TRAP (!Guarded());

		TRAP (!Crashed_c)

		UpdateHolding();
		UpdateAirborne();
		FreeSafePlanes();
		CrashCheck();

	}


/****************************************************************************/
	void Traffic::UpdateAirborne()
	// Step all airborne planes that are scheduled to move
		{
		TRAP (!Guarded());

		EifIterator AirborneIt;
		Plane *PlaneToUpdate;
		DelayableCmnd *DCmnd;

		// go through each airborne plane
		AirborneIt = Airborne_c.Iterator();
		while (!AirborneIt.Finished())	{
			PlaneToUpdate = Airborne_c.Item (AirborneIt);

			// if the plane is scheduled to move step it
			if (IsStepScheduled (PlaneToUpdate))	{
				PlaneToUpdate->Step();
			}

			// if the plane has a delayed command for new position, execute
			// and remove the delayed command
			DCmnds_c.Search (PlaneToUpdate);
			if (DCmnds_c.Found())	{
				DCmnd = DCmnds_c.FoundItem ();

				if (DCmnd->At()->GrndPos() == PlaneToUpdate->CurPos())	{
					DCmnd->Execute();
					DCmnds_c.Remove (PlaneToUpdate);
				}
			}

			AirborneIt.Forth();
		}

		TRAP (!Guarded());

	}

/****************************************************************************/
	void Traffic::UpdateHolding()
	// take off or step holding planes.  Note that planes which are ready to
	// take off but not scheduled to move are not stepped.

		{
		TRAP (!Guarded());

		char ToTakeOffId;
		EifList <HoldingPlane *> ToTakeOff (True);
		EifIterator ToTakeOffIt;
		HoldingPlane *HoldingToUpdate = NULL, *HoldingToTakeOff = NULL;
		EifIterator	HoldingIt;

		// go through each holding plane
		HoldingIt = Holding_c.Iterator();
		while (!HoldingIt.Finished())	{

			// if the plane is still idle, step it
			HoldingToUpdate = Holding_c.Item (HoldingIt);
			if (HoldingToUpdate->P()->TargAlt() == 0)	{
				HoldingToUpdate->Step();
			} else {

				// if the plane is not idle and scheduled to step this go,
				// select it as one to take off
				TRAP (HoldingToUpdate->P()->TargAlt() > 0);
				if (IsStepScheduled (HoldingToUpdate->P()))	{
					ToTakeOff.Add (HoldingToUpdate);
				}
			}
			HoldingIt.Forth();
		}

		TRAP (!Holding_c.Guarded());

		// make selected planes airborne
		ToTakeOffIt = ToTakeOff.Iterator();
		while (!ToTakeOffIt.Finished())	{
			HoldingToTakeOff = ToTakeOff.Item (ToTakeOffIt);
			ToTakeOffId		 = HoldingToTakeOff->P()->Id();

			Airborne_c.Add (HoldingToTakeOff->P(), ToTakeOffId);
			Holding_c.Remove (ToTakeOffId);
			delete HoldingToTakeOff;

			ToTakeOffIt.Forth();
		}

		TRAP (!Holding_c.Guarded());
		TRAP (!Guarded());
	}


/****************************************************************************/

/**/