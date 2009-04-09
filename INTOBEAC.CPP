/*
Function definitions for InToBeacn

*/
# include "intobeac.h"

/**********************************************************************/
	void InToBeacon::ProcessInput (char KeyHit_i)	{
		char Msg[5];
		int BeaconId;
		Beacon *ToBeacon;

		if (isdigit (KeyHit_i))	{
			BeaconId = int (KeyHit_i) - '0';
			Landmarks_c->Beacons.Search (BeaconId);
			if (Landmarks_c->Beacons.Found())	{

				EchoChar (KeyHit_i);
				EchoChar (' ');
				ToBeacon = Landmarks_c->Beacons.FoundItem();

				NewCmnd_c = new TurnTowardsCmnd (Plane_c, ToBeacon);

				Next_c = new DelayOrCompleteInput (*this);
				IsCompleted_c = True;
			}
		}
	}


/**********************************************************************/
	void InToBeacon::PromptMsg ()	{
		char Msg[3] = "  ";
		EifIterator BeaconIt = Landmarks_c->Beacons.Iterator();

		Out_c->Prompt ("Select beacon number from :");
		while (!BeaconIt.Finished())	{
			Msg[0] =  '0' + Landmarks_c->Beacons.Item (BeaconIt)->ID();
			Out_c->AddToPrompt (Msg);

			BeaconIt.Forth();
		}
	}


/**********************************************************************/
	void InToBeacon::Undo()	{
		UndoNewCmnd();
		CommonUndo();
	}
