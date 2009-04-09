/* Class to describe an environment that initilises a simulator name
flight paths,landmarks and timings
check landmarks of different types do not occupy the same position in the
arena.

Nick Papa

ver 0.0

01/04/96 */

# ifndef _ENVIRONMENT_H
# define _ENVIRONMENT_H

# include <assert.h>
# include "position.h"
# include "landmars.h"
# include "timings.h"

class Environment    {

private:
	Landmarks *Lmarks_c;
	Timings *TParameters_c;
	char * SimName_c;
public:
       Environment ( Landmarks *l, Timings *t, char *s ){
		Lmarks_c=l;
		TParameters_c=t;
		SimName_c=s;
	   }

	   ~Environment ()	{
			delete Lmarks_c;
			delete TParameters_c;
			delete SimName_c;
	   }

       Landmarks *Lmarks(void){ return Lmarks_c; }

       //FlightPaths *Paths(void){ return Paths_c; }

       Timings *TParameters(void){ return TParameters_c; }

       char *SimName(void){return SimName_c;}

};

# endif _ENVIRONMENT_H
