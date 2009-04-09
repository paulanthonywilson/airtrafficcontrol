# include "landmars.h"

void Landmarks::AddGate ( Gate *g ){
	if ( NoOfGates_c<10 ) {
		AllGates_c[ NoOfGates_c ] = g;
		NoOfGates_c++;
	}
}

Landmarks::~Landmarks () {
	int GateIx, BeaconIx, AirportIx, FlightPathIx;

	for (GateIx = 0; GateIx < NoOfGates_c; GateIx ++)	{
		delete AllGates_c [GateIx];
	}

	for (BeaconIx = 0; BeaconIx < NoOfBeacons_c; BeaconIx ++)	{
		delete AllBeacons_c [BeaconIx];
	}

	for (AirportIx = 0; AirportIx < NoOfAirports_c; AirportIx ++)	{
		delete AllAirports_c [AirportIx];
	}

	for (FlightPathIx = 0; FlightPathIx < NoOfFlightPaths_c; FlightPathIx ++)	{
		delete AllFlightPaths_c [FlightPathIx];
	}
}


void Landmarks::AddBeacon ( Beacon *b ){
	if ( NoOfBeacons_c<10 ) {
		AllBeacons_c[ NoOfBeacons_c ] = b;
		NoOfBeacons_c++;
	}
}

void Landmarks::AddAirport ( Airport *a ){
	if ( NoOfAirports_c<10 ) {
		AllAirports_c[ NoOfAirports_c ] = a;
		NoOfAirports_c++;
	}
}

void Landmarks::AddFlightPath ( FlightPath *f ){
	if ( NoOfFlightPaths_c<10 ) {
		AllFlightPaths_c[ NoOfFlightPaths_c ] = f;
		NoOfFlightPaths_c++;
	}

}

Destination * Landmarks::PickDestination(){
	ChooseDestType();
	if (DestChoice_c==TypeGate) return PickGate();
	return PickAirport();
}

void Landmarks::ChooseDestType(){
	int Total,pick;
	Total=NoOfGates_c + NoOfAirports_c;
	pick=random(Total);
	if (pick<NoOfGates_c) DestChoice_c=TypeGate;
	else
		DestChoice_c=TypeAirport;
}

Airport *Landmarks::PickAirport(){
	int pick;
	pick=random(NoOfAirports_c);
	return AllAirports_c[pick];
}

Gate *Landmarks::PickGate(){
	int pick;
	pick=random(NoOfGates_c);
	return AllGates_c[pick];
}
