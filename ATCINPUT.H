/*
Input class for ATC

*/

# ifndef _INPUT_H
# define _INPUT_H

# include <conio.h>
# include <stdio.h>
# include <ctype.h>

# include "stdatc.h"
# include "table.h"
# include "traffic.h"
# include "landmars.h"
# include "allcmnds.h"
# include "atcscree.h"


# define INPUT_LINE 1
# define PROMPT_LINE 3

class ATCInputScreen	: public ATCScreen {

private:

	//Screen commands & data
	int CrntColumn_c;
	int PromptColumn_c;

	void Cursor();


public:

	ATCInputScreen ();

	void Refresh();

	void Select();

	void Echo (char *Msg_i);

	void ClearEchoBy (int Column_i);

	void Prompt (char *Msg);

	void AddToPrompt (char *Msg);

};

# endif