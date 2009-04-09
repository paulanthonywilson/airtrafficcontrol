/*Structure containing ground position, altitude, and heading

Paul Wilson
7/4/96

*/

# ifndef _VECTOR3D_H
# define _VECTOR3D_H

struct	Vector3D	{

	Vector3D(){}

	Vector3D (Position GrndPos_i, Heading Head_i, int Altitude_i) :
		GrndPos (GrndPos_i),
		Head (Head_i),
		Altitude (Altitude_i)	{}

	Position GrndPos;

	Heading Head;

	int Altitude;
};

# endif
