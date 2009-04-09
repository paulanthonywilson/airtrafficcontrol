/*
Class to input commands
ver 0.0
28/4/96
PW
*/

# include <ctype.h>


# include "stdatc.h"
# include "table.h"
# include "traffic.h"
# include "landmars.h"
# include "allcmnds.h"
# include "atcinput.h"
# include "inputste.h"
# include "eifstack.h"
# include "land2.h"
# include "inplanes.h"




class CmndInput	{

private:
	ATCInputScreen Out_c;

	Traffic *Traff_c;
	LandmarkCollection Landmarks_c;

	Boolean IsCmndToCollect_c;
	Cmnd *LastCmnd_c;

	EifStack <InputStep *>	Step_c;

	void ProcessNormalKeyHit (char KeyHit_i);

public :
	CmndInput
		(
		Landmarks *Lmarks_i,
		Traffic *Traff_i
		);

/*	Boolean IsCmndToCollect()	{
		return IsCmndToCollect_c;
	}

	Cmnd *LastCmnd()	{
		return LastCmnd_c;
	}
*/

	void ProcessInput ();

	void Update();


	void SetForNewCmnd();
};

