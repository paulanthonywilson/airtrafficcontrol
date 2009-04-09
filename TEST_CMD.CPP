

// To test commands

# include "fullturn.h"
# include "turntowa.h"
# include "defaultt.h"
# include "relturnc.h"
# include "circling.h"
# include "exitcmnd.h"
# include "plane.h"
# include "airport.h"
# include "absaltcm.h"
# include "descendc.h"
# include "ascendcm.h"
# include "stdio.h"

int main(){


	Position pos(5,5);
	Heading h(D0);
	Airport *d;

	d = new Airport(pos,0,h);
	Plane *p;
	p = new Plane('a',Vector3D(pos,h,7),Jet,d);
	h = D180;
	Cmnd *cmd;

	//cmd = new FullTurnCmnd(p,h, AntiClockwise);

	//cmd = new AbsAltCmnd(p,5);

	//cmd= new AscendCmnd(p,3);

	//cmd = new DescendCmnd(p,6);

	//cmd = new CirclingCmnd(p,AntiClockwise);

	//cmd = new RelTurnCmnd(p,h,Anticlockwise);

	cmd = new FullTurnCmnd(p,h,AntiClockwise);

//	cmd = new TurnTowardsCmnd(p,d); p->Step();

	cmd->Execute();

	int count=0;

	cout << "\n\n\n";

	while(count<6){
		printf("Pos %d %d Heading %d Altitude %d\n",
				p->CurPos().X(),p->CurPos().Y(),p->CurHead().Degrees(),
				p->CurAlt());
		p->Step();
		count++;
	}


		return 0;

}





