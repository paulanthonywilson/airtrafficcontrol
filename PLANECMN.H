/* Plane command class

version 0.1

Nick Papa  22/04/96.

ver 0.2
27/4/96 PW
Plane accessor added

*/

# ifndef  _PLANECMND_H
# define  _PLANECMND_H

# include "cmnd.h"
# include "plane.h"

 class  PlaneCmnd : public Cmnd {

  protected:
	  Plane *p_c;

  public :
	  PlaneCmnd (Plane *pl) {
	  p_c = pl;
	 }

  Plane *P()	{
	return p_c;
  }

 };

# endif _PLANECMND_H
