/* Class to describe a plane and how it moves

Simon Hall

ver 0.0
8/4/96

ver 0.01
14/4/96	PW

Hacked about to be usable in Traffic
changes:
	Id changed from char * to char
	all DelayableCmnd transactions removed
	IsSafe () added
	TargAlt() added

ver 0.02
16/4/96 PW
Changed to conform to Heading 0.3: no equivalence between headings and
integers

ver 0.3
29/4/96 PW
Class tracks live planes

ver 0.4
3/5/96
Status added


*/

# ifndef _PLANE_H
# define _PLANE_H



# include "stdatc.h"
# include "position.h"
# include "heading.h"
# include "destinat.h"
# include "vector3d.h"
# include "eiflist.h"

# define MAXFUEL 50
const Heading MaxTurn = D90;


class Plane	{

private :

	static int NextUniqueIx;
	static EifList<int> LiveIx;

	char Id_c;
	int UniqueIx_c;


	PlaneStatus Status_c;
	Position CurPos_c;
	Heading CurHead_c;
	Heading TargHead_c;
	Boolean Circling_c;
	AngDir TurnDir_c;
	int CurAlt_c;
	int TargAlt_c;
	int CurFuel_c;
	const Aircraft PType_c;
	Destination * PDest_c;

public :

	Plane (char, Vector3D &, const Aircraft,
		   Destination *);

	~Plane ();

	char Id(void){ return Id_c; }

	Position CurPos(void){
		TRAP (CurPos_c.inArena());
		return CurPos_c; }

	Heading CurHead(void){ return CurHead_c; }

	int CurAlt(void){ return CurAlt_c; }

	int CurFuel(void){ return CurFuel_c; }

	Aircraft PType(void){ return PType_c; }

	Destination *PDest(void){ return PDest_c; }

	Boolean InAirspace(Plane *);

	Boolean IsSafe () 	{
		return PDest_c->IsSafeCoords (Vector3D (CurPos_c, CurHead_c, CurAlt_c));
	}
	void Step(void);

	void AlterTargHeading( Heading h, AngDir td){
		TargHead_c=h;
		TurnDir_c=td;
		Circling_c=False;
	}

	void AlterTargAlt( int a ){
		TargAlt_c=a;
	}

	void MakeCircle( AngDir td ){
		Circling_c=True;
		TargHead_c=CurHead_c;
		TurnDir_c=td;
	}

	int TargAlt()	{
		return TargAlt_c;
	}

	int UniqueIx()	{
		return UniqueIx_c;
	}

	PlaneStatus Status()	{
		return Status_c;
	}

	void SetStatus(PlaneStatus NewStatus_i)	{
		Status_c = NewStatus_i;
	}


	static Boolean IsLive (int PlaneIx_i)	{

		LiveIx.Search (PlaneIx_i);
		return LiveIx.Found();
	}


};



# endif _PLANE_H
