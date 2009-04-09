/*
Function definitions for DelayATBeacon

*/
# include "atbeacon.h"

/**********************************************************************/
	void DelayAtBeacon::ProcessInput (char KeyHit_i)	{
		int BeaconId;
		Beacon *AtBeacon;

		if (isdigit (KeyHit_i))	{
			BeaconId = int (KeyHit_i) - '0';
			Landmarks_c->Beacons.Search (BeaconId);
			if (Landmarks_c->Beacons.Found())	{

				EchoChar (KeyHit_i);
				EchoChar (' ');
				AtBeacon = Landmarks_c->Beacons.FoundItem();

				Next_c = new CompleteDelay (*this, AtBeacon);
				IsCompleted_c = True;
			}
		}
	}


/**********************************************************************/
	void DelayAtBeacon::PromptMsg ()	{
		char Msg[3] = "  ";
		EifIterator BeaconIt = Landmarks_c->Beacons.Iterator();

		Out_c->Prompt ("Select beacon number from :");
		while (!BeaconIt.Finished())	{
			Msg[0] = '0' + Landmarks_c->Beacons.Item (BeaconIt)->ID();
			Out_c->AddToPrompt (Msg);

			BeaconIt.Forth();
		}
	}


/**********************************************************************/
	void DelayAtBeacon::Undo (){
		CommonUndo();
	}
