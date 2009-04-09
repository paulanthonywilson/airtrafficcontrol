/* structure to store info about scores

Simon Hall
29/04/96
*/

# ifndef _SCORELIN_H
# define _SCORELIN_H


struct ScoreLine{

	ScoreLine(){}

	ScoreLine(char name_i[], int score_i, int time_i, ScoreLine *next_i):

		score(score_i),
		time(time_i) {strcpy(name,name_i);}

	char name[15];

	int score;

	int time;

};

# endif