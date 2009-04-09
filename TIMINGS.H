/* Class to describe a creation of timing and its interval

Nick Papa

ver 0.1

01/04/96 */

# ifndef _TIMINGS_H
# define _TIMINGS_H



class Timings   {

private:
	int UpdateInterval_c, CreationInterval_c;
public:
	Timings (  ){
		UpdateInterval_c = 0;
		CreationInterval_c = 0;
	}

	int UpdateInterval (void) { return UpdateInterval_c; }
	int CreationInterval (void) { return CreationInterval_c; }
	void ChangeUInterval(int U) { UpdateInterval_c=U; }
	void ChangeCInterval(int C) { CreationInterval_c=C; }

};


# endif _TIMINGS_H
