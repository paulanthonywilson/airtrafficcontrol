/*
Input class for ATC

*/

# ifndef _INPUT_H
# define _INPUT_H

# include <conio.h>
# include <stdio.h>
# include <ctype.h>


# include "stdatc.h"
# include "table.h"
# include "traffic.h"
# include "landmars.h"
# include "allcmnds.h"
# include "atcscree.h"


# define INPUT_LINE 1
# define PROMPT_LINE 3

class ATCInput	: public ATCScreen {

private:
	Traffic *Traff_c;

	//Landmark tables keyed by Id
	Table <Gate *, int>	Gates_c;
	Table <Airport *, int> Airports_c;
	Table <Beacon *, int> Beacons_c;

	//Screen commands & data
	int CrntColumn_c;
	void Echo (char *Msg_i);


	//	void *ATCInput::NextProcess_c;
	void (*NextProcess_c)(ATCInput &, char);
	void NextProcess (void (*Next_i) (ATCInput &, char));
	Boolean IsCmndToCollect_c;
	Cmnd *LastCmnd_c;

	Plane *CrntPlane_c;
	AngDir TurnDir_c;
	Table <AtLandmark *, int> *CrntAtLandmark_c;

	void DelayOrExecute (char KeyHit_i);
	void CmndComplete();

	static void GetPlane (ATCInput &c, char KeyHit_i);

	static void GetCmndType (ATCInput &c, char KeyHit_i);

	static void GetCircleCmnd (ATCInput &c, char KeyHit_i);

	static void GetDirCircleCmnd (ATCInput &c, char KeyHit_i);

	static void DelayAt (ATCInput &c, char KeyHit_i);

	static void DelayAtBeacon (ATCInput &c, char KeyHit_i);

	static void DelayAtAirport (ATCInput &c, char KeyHit_i);


public:

	ATCInput (Traffic *Traff_i, Landmarks *Lmarks_i);

	void Refresh();

	void ReadyForNewCmnd();

	void ProcessInput();

	Boolean IsCmndToCollect();

	Cmnd *LastCmnd();

};

# endif