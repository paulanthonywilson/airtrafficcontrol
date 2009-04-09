/* Class to describe landmarks to initilise beacons,gates and airports
 in the arena

Simon Hall

ver 1.0
03-04-96*/

#ifndef _LANDMARKS_H
#define _LANDMARKS_H

#include <assert.h>

#include "gate.h"
#include "beacon.h"
#include "airport.h"
#include "flightpa.h"
class Landmarks {

private :
	Gate *AllGates_c[9];
	Beacon *AllBeacons_c[9];
	Airport *AllAirports_c[9];
	FlightPath *AllFlightPaths_c[9];
	int NoOfGates_c, NoOfBeacons_c;
	int NoOfAirports_c, NoOfFlightPaths_c;
	LandmarkTypeId DestChoice_c;
public :
	Landmarks(){ NoOfGates_c=0; NoOfBeacons_c=0;
		 NoOfAirports_c=0; NoOfFlightPaths_c=0; }

	~Landmarks();

	int NoOfGates(void){ return NoOfGates_c; }

	int NoOfBeacons(void){ return NoOfBeacons_c; }

	int NoOfAirports(void){ return NoOfAirports_c; }

	int NoOfFlightPaths(void){ return NoOfFlightPaths_c; }

	void AddGate( Gate * );

	void AddBeacon( Beacon * );

	void AddAirport( Airport * );

	void AddFlightPath( FlightPath * );

	Gate ** AllGates(void){ return AllGates_c; }

	Beacon ** AllBeacons(void){ return AllBeacons_c; }

	Airport ** AllAirports(void){ return AllAirports_c; }

	FlightPath ** AllFlightPaths(void){ return AllFlightPaths_c; }

	Destination *PickDestination();

	LandmarkTypeId DestChoice(){ return DestChoice_c; }

	Airport *PickAirport();

	Gate *PickGate();

	void ChooseDestType();

};

# endif _LANDMARKS_H



