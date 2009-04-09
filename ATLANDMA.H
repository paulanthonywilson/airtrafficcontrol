/* Class to describe a landmark that can be used in a delayed command

Simon Hall

ver 0.0
01/04/96

ver 0.1
ID changed from char * to int
19/4/96
PW
*/

# ifndef _ATLANDMARK_H
# define _ATLANDMARK_H

# include <assert.h>
# include "position.h"
# include "stdatc.h"
# include "landmark.h"

class AtLandmark : virtual public Landmark {

public:

	AtLandmark (Position pos, int id)
		: Landmark(pos,id) {
		assert(pos.inField());
	}

	virtual LandmarkTypeId LandmarkType() = DEFERRED;


};

# endif _ATLANDMARK_H





