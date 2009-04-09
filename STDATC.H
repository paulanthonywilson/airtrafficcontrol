/* My headings

ver 0.3

8/4/96
*/

#ifndef _STDATC_H
#define _STDATC_H

# include <assert.h>
# include <iostream.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define DEFERRED 0

# define TRAP_ON

#ifdef TRAP_ON

# define TRAP(p) { \
if (!(p))	{\
	cout << "Error trapped";\
	getchar();\
	cout << "Trying to resume normal service";\
}}
# else
#  define TRAP(p)   (assert (p));

# endif

/* Boolean not defined as
	enum Boolean {... to avoid compiler warnings for eg
	Boolean b = (x==y);
*/

enum {False, True};
typedef int Boolean;

enum PlaneState {PlaneAirborne, PlaneHolding};
enum LandmarkTypeId {TypeGate, TypeAirport, TypeBeacon};

typedef int Time;
typedef int Fuel;
typedef int Altitude;



enum AngDir {AntiClockwise=-1, Clockwise=1};


enum  {Prop, Jet};

typedef int Aircraft;

enum CmndType {Exit, Delayable, Alt};

enum ErrorMsg {OK, ExpressionTooLong,IncorrectType,
		SyntaxError, MoreThanTenLmarks,PosError,
		PosAlreadyExists, HeadError, IncorrectDimension,
		NotEnoughDests, ParametersNotSet};

enum PlaneStatus {NotCrashed, Collided, CrashLanded, LeftArena,
	OutOfFuel, WaitedTooLong};

void ClearInputBuffer();

# endif