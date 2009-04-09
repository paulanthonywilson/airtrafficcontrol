/* Class to read and create an environment from a text file,
   also to view and update top tens.

Simon Hall
ver 0.0

20/04/96 */

# ifndef _EXTERNAL_H
# define _EXTERNAL_H

# include "environm.h"
# include "scorelin.h"
#include <dir.h>

# define LIMIT 256


class ExternalFileSys {

private:
	Boolean eof;
	ErrorMsg Error_c;
	ScoreLine TopTen_c[10];
	char *games_c[20];
	char CurGame_c[12];
	char *tt_fname;
	int line_no_c;
	Environment *Enviro_c;
	void ReadLine(char lin[], FILE *e_file);
	void CreateUpdate(char lin[],Timings *);
	void CreateNewplane(char lin[],Timings *);
	void CreateWidth(char lin[]);
	void CreateHeight(char lin[]);
	void CreateExit(char lin[],Landmarks *);
	void CreateBeacon(char lin[],Landmarks *);
	void CreateAirport(char lin[],Landmarks *);
	void CreateFlightpath(char lin[],Landmarks *);
	int FindPara(char lin[],int nxt);
	int FindNum(char lin[],int &nxt);
	void FindChar(char lin[],int &nxt,int charval);
	Boolean AlreadyExists(Landmarks *l,Position p);
	void FindNxt(char lin[],int &nxt);
	Position FindPos(char lin[],int &nxt);
	Heading FindHead(char lin[],int &nxt);

public:
	ExternalFileSys();

	void CurrentGame(int g){ strcpy(CurGame_c,games_c[g-1]);
		strcpy(tt_fname,CurGame_c);
		strcpy(strstr(tt_fname,".ENV"),".TTL"); }

	void ReadEnvironment();

	void ViewTopTen();

	Boolean InTopTen(int NoSafe,int t);

	void FindPos(int NoSafe,int t,int &count);

	void UpdateTopTen(int NoSafe,int t);

	char *Games(int c){ return games_c[c]; }

	ScoreLine *TopTen(){ return TopTen_c; }

	ErrorMsg Error(){ return Error_c; }

	int line_no(){ return line_no_c; }

	Environment *Enviro(){ return Enviro_c; }

};

# endif

