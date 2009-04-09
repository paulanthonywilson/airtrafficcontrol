/*
function definitions for InputStep
*/

# include "inputste.h"

/***************************************************************************/
	void InputStep::EchoChar (char Char_i)	{
		char Msg[2];
		Msg[0] = Char_i;
		Msg[1] = '\0';

		EchoLength_c++;
		Out_c->Echo (Msg);
	}
