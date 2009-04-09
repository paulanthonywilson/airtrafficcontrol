/*
Function definitions for InToGate

*/
# include "intogate.h"

/**********************************************************************/
	void InToGate::ProcessInput (char KeyHit_i)	{
		char Msg[5];
		int GateId;
		Gate *ToGate;

		if (isdigit (KeyHit_i))	{
			GateId = int (KeyHit_i) - '0';
			Landmarks_c->Gates.Search (GateId);
			if (Landmarks_c->Gates.Found())	{

				sprintf (Msg, "%c ", KeyHit_i);
				Echo (Msg);
				ToGate = Landmarks_c->Gates.FoundItem();

				NewCmnd_c = new TurnTowardsCmnd (Plane_c, ToGate);

				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
			}
		}
	}


/**********************************************************************/
	void InToGate::PromptMsg ()	{
		char Msg[3] = "  ";
		EifIterator GateIt = Landmarks_c->Gates.Iterator();

		Out_c->Prompt ("Select exit number from :");
		while (!GateIt.Finished())	{
			Msg[0] =  '0' + Landmarks_c->Gates.Item (GateIt)->ID();
			Out_c->AddToPrompt (Msg);

			GateIt.Forth();
		}
	}

/**********************************************************************/
	void InToGate::Undo() 	{
		UndoNewCmnd();
		CommonUndo();
	}