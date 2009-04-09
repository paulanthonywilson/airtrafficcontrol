/* class to control the running of the simulator

Simon Hall
ver 0.0
28/04/96
*/

# include "radarscr.h"
# include"external.h"
# include"atc.h"
# include "radarscr.h"
# include "cmndinpu.h"
# include "airborne.h"
# include "holdingi.h"
# include "time.h"
# include "scorescr.h"
# include "timescre.h"
# include "updatess.h"
# include "crashscr.h"

class ATCrun {

public:

	ATCrun (){
		textmode (ATC_TEXT_MODE);
	}

	void Start(ExternalFileSys *FileSys);

};
