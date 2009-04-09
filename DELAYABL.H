/* Delayable command class

version 0.1

Nick Papa  22/04/96.

ver 0.1
27/4/96 PW
IsDelayed() and Type() added

*/

# ifndef  _DELAYABLECMND_H
# define  _DELAYABLECMND_H

# include "planecmn.h"
# include "atlandma.h"

 class  DelayableCmnd : public PlaneCmnd {

  private :
	Boolean IsDelayed_c;

  protected:
	  AtLandmark *At_c;


  public :
	  DelayableCmnd (Plane *pl)
	  :PlaneCmnd (pl),
	  IsDelayed_c (False),
	  At_c (NULL) {}

	 AtLandmark *At() { return At_c;}

	 void DelayAt (AtLandmark *Atl)  {
		At_c = Atl;
		IsDelayed_c = True;
	 }

	 CmndType Type()	{
		return Delayable;
	 }

	 Boolean IsDelayed()	{
		return IsDelayed_c;
	 }

   };

# endif _DELAYABLECMND_H
