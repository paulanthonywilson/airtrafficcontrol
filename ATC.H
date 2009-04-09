/* class to step the simulator and that detects termination of it.

Simon Hall

ver 0.0
27/04/96*/

# include "traffic.h"
# include "environm.h"
# include "atcstatu.h"


class ATC {

private:
	Environment *Enviro_c;
	Traffic *Traf_c;
	int Score_c;
	int NoOfUpdates_c;

public:
	ATC (Environment *e){
		Enviro_c=e;
		Traf_c=new Traffic();
		Score_c=0;
		NoOfUpdates_c=0;
		randomize();
		ATCStatus::Finished = False;
	}

	~ATC ();

	Environment *Enviro(){ return Enviro_c; }

	Traffic *Traf(){ return Traf_c; }

	int Score(){ return Score_c; }

	int NoOfUpdates(){ return NoOfUpdates_c; }

	void AdvanceSys();

	Boolean Termination(){
		if ( Traf_c->Crashed() || ATCStatus::Finished ) return True;
		return False;
	}

};