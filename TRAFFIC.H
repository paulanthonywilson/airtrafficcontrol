/*
Traffic class deals with planes and plane interactions

Paul Wilson
ver 0.0

8/4/96
13/4/96

*/

# ifndef _TRAFFIC_H
# define _TRAFFIC_H

# define MAX_PLANES 13
# define MIN_PLANE_ID 'a'
# define MAX_PLANE_ID 'z'

# include "table.h"
# include "eiflist.h"


# include "stdatc.h"
# include "plane.h"
# include "holdingp.h"
# include "destinat.h"
# include "allcmnds.h"

class Traffic {

private:
	enum PlanesToStep	{OnlyJets = Jet, AllPlanes};

	Table<Plane *, char>            Airborne_c; //pointers to airborne planes
	Table<HoldingPlane *, char>	    Holding_c;  //pointers to holding planes
	Table<DelayableCmnd *, Plane *> DCmnds_c;  // pointers to delayed cmnds

	int SafeCnt_c;
	PlanesToStep Scheduled_c;
	Boolean Crashed_c;
	Boolean  IsFoundAirborne_c;
	Boolean  IsFoundHolding_c;
	Boolean  IsFoundKnown_c;
	Boolean  IsFoundDelayCmnd_c;

	DelayableCmnd *FoundDelayCmnd_c;
	Plane		 *FoundAirborne_c;
	HoldingPlane *FoundHolding_c;
	Plane		 *FoundKnown_c;

	char LastId_c;

	void FreeSafePlanes();
	// records the number of safe planes and deletes them

	void UpdateHolding();
	// take off or step holding planes

	Boolean IsStepScheduled (Plane *Plane_i);

	void UpdateAirborne();
	// Step all airborne planes that are scheduled to move

	void CrashCheck();
	// check for any planes which have crashed

	void StepScheduledPlanes();
	// Step planes that are scheduled to move


public:
	Traffic ();

	~Traffic();

	Boolean IsFull();
	// No room for any more new planes

	void SearchAirborne (char PlaneId_i);
	// Search for PlaneId_i amongst airborne planes and set IsFoundAirborne
	// and FoundAirborne accordingly

	void SearchHolding (char PlaneId_i);
	// Search for PlaneId_i amongst holding planes and set IsFoundHolding
	// and FoundHolding accordingly

	void SearchKnown (char PlaneId_i);
	// Search for PlaneId_i amongst known planes and set IsFoundKnown
	// and FoundKnown accordingly

	void SearchDelayCmnd (Plane *Plane_i);
	// look for delayed cmnd

	Boolean IsFoundDelayCmnd();

	DelayableCmnd *FoundDelayCmnd();

	Boolean IsFoundAirborne();
	// Last call to SearchAirborne successful

	Boolean IsFoundHolding();
	// Last call to SearchHolding successful

	Boolean IsFoundKnown();
	// Last call to SearchKnown successful

	Plane *FoundAirborne();
	// Plane found in last successful call to SearchAirborne

	HoldingPlane *FoundHolding();
	// Plane found in last successful call to SearchHolding

	Plane  *FoundKnown();
	// Plane found in last successful call to SearchKnown

	void NewAirborne (Plane *NewPlane_i);
	// record a new airborne plane

	void NewHolding (HoldingPlane *NewPlane_i);
	// record a new holding plane

	char NewId ();
	// the next plane id

	void ExecuteCmnd (DelayableCmnd *ExCmnd_i);
	// require that command's plane is airborne

	void ExecuteCmnd (AltCmnd *ExCmnd_i);
	// require that command's plane is known

	void  DelayCmnd (DelayableCmnd *DCmnd);
	// require that command's plane is airborne

	void StepAll();	// advance all planes

	void StepJets(); // only advance jets

	int SafeCnt();	// the number of safe planes this step

	Boolean Crashed();	// returns true if a plane has crashed, collided etc..

	Boolean Guarded();

	EifIterator AirborneIterator();
	// return an iterator prepared to traverse all the airborne planes

	EifIterator HoldingIterator();
	// return an iterator prepared to traverse all the holding planes

	Plane *Airborne (EifIterator PlaneIt_i);
	// return plane at PlaneIt_i

	HoldingPlane *Holding (EifIterator HoldingIt_i);
	// return holding plane at HoldingIt_i

};

# endif