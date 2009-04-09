# include "atc.h"
# include "radarscr.h"


void ATC::AdvanceSys() {

	Destination *d;
	Gate *g=0;
	Airport *a=0;
	Plane *p;
	HoldingPlane *hp;
	Aircraft AType;
	LandmarkTypeId Choice;

	if (NoOfUpdates_c%2==0)
		Traf_c->StepAll();
	else
		Traf_c->StepJets();

	if (NoOfUpdates_c %
		(Enviro_c->TParameters()->CreationInterval())==0)
		if (! Traf_c->IsFull()){
			Enviro_c->Lmarks()->ChooseDestType();
			if (Enviro_c->Lmarks()->DestChoice()==TypeAirport)
				{a=Enviro_c->Lmarks()->PickAirport();
				Choice=TypeAirport;}
			else
				{g=Enviro_c->Lmarks()->PickGate();
				Choice=TypeGate;}
			do{d=Enviro_c->Lmarks()->PickDestination();}
			while(d==a || d==g);

			AType=random(2);

			if (Choice==TypeGate)
				{p=new Plane(Traf_c->NewId(),
					g->NewPlaneCoords(),
					AType,
					d);
				Traf_c->NewAirborne(p);
			}

			else
				{hp=new HoldingPlane(Traf_c->NewId(),
					a->NewPlaneCoords(),
					AType,
					d,a);
				Traf_c->NewHolding(hp);
			}

		}


	NoOfUpdates_c++;

	Score_c=Score_c+Traf_c->SafeCnt();


}


	ATC::~ATC() {

//		delete Enviro_c;
		delete Traf_c;
	}