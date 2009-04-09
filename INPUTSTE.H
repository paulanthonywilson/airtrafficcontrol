/*
Base class for navigating through input command options

Paul Wilson
28/4/96

*/

# include "atcinput.h"
# include "land2.h"
# include "string.h"
# include "atckeys.h"
# include "allcmnds.h"


# ifndef _INPUTSTE_H
# define _INPUTSTE_H

class InputStep	{

protected:

	Boolean IsCompleted_c;
	InputStep *Next_c;
	ATCInputScreen *Out_c;
	LandmarkCollection *Landmarks_c;
	Boolean IsCmndEntered_c;
	int EchoLength_c;


	Cmnd *NewCmnd_c;

	void Echo (char *Msg_i)	{
		EchoLength_c = strlen (Msg_i);
		Out_c->Echo(Msg_i);
	}

	void EchoChar (char Char_i);



	void CommonUndo ()	{
		assert (IsCompleted_c);

		IsCompleted_c = False;
		Out_c->ClearEchoBy (EchoLength_c);
		PromptMsg();
	}

	void UndoNewCmnd()	{
		if (NewCmnd_c != NULL)	{

			delete NewCmnd_c;
			NewCmnd_c = NULL;
		}
	}





	InputStep (ATCInputScreen *Out_i, LandmarkCollection *Landmarks_i) :
		Out_c (Out_i),
		Landmarks_c (Landmarks_i),
		IsCompleted_c (False),
		Next_c (NULL),
		IsCmndEntered_c (False),
		EchoLength_c (0),
		NewCmnd_c (NULL)	{}

	InputStep (InputStep const &Last_i)	:
		Out_c (Last_i.Out_c),
		Landmarks_c (Last_i.Landmarks_c),
		Next_c (Last_i.Next_c),
		NewCmnd_c (Last_i.NewCmnd_c),
		EchoLength_c (0),
		IsCmndEntered_c (False),
		IsCompleted_c (False)
		{}

public :
	Boolean IsCompleted	() {

		return IsCompleted_c;
	}

	InputStep *Next()	{
		assert (IsCompleted_c);
		return Next_c;
	}

	Boolean IsCmndEntered()	{
		return IsCmndEntered_c;
	}

	Cmnd *NewCmnd()	{
		assert (IsCmndEntered_c);

		return NewCmnd_c;
	}

	virtual void ProcessInput (char KeyHit_i)	=	DEFERRED;

	virtual void Undo() = DEFERRED;

	virtual void PromptMsg () = DEFERRED;

	virtual Boolean IsValid ()	{
		return True;
	}
};

# endif