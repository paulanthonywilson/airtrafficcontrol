/* Class to describe a beacon that exists in the field and can be used as
a reference in a delayed command

Nick Papa

ver 0.0
03-04-96*/

#ifndef _BEACON_H
#define _BEACON_H

#include "atlandma.h"

class Beacon : public AtLandmark {

public :
	Beacon(const Position &pos, int id)
		:
		AtLandmark (pos,id),
		Landmark (pos, id) {}

	virtual LandmarkTypeId LandmarkType() {
		return TypeBeacon;
	}


};

# endif _BEACON_H
