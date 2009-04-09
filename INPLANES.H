/*
Enter Plane step
*/

# ifndef _INPLANE_H
# define _INPLANE_H

# include "inputste.h"
# include "incmndty.h"

class InPlaneStep : public InputStep	{

private :

	Traffic *Traff_c;
	LandmarkCollection *Landmarks_c;

public:

	InPlaneStep
		(
		ATCInputScreen *Out_i,
		LandmarkCollection *Landmarks_i,
		Traffic *Traff_i
		) :
		InputStep (Out_i, Landmarks_i),
		Traff_c (Traff_i)
		{
		PromptMsg();
	}

	void ProcessInput(char KeyHit_i);

	void Undo();

	virtual void PromptMsg ();

};

# endif