/*
Base for input steps that already have a stored plane

*/
# ifndef _WITHPLAN_H
# define _WITHPLAN_H

# include "inputstep.h"

class WithPlaneStep :public InputStep	{

protected:

	Plane *Plane_c;
	int PlaneIx_c;

public:
	WithPlaneStep
		(
		const InputStep &Last_i,
		Plane *Plane_i
		) :
		InputStep (Last_i),
		Plane_c (Plane_i),
		PlaneIx_c (Plane_i->UniqueIx())
			{}

	WithPlaneStep (const WithPlaneStep &Other_i)	:
		InputStep (Other_i),
		Plane_c (Other_i.Plane_c),
		PlaneIx_c (Other_i.PlaneIx_c)
		{}

	Boolean IsValid ()	{
		return Plane::IsLive (PlaneIx_c);
	}
};


# endif