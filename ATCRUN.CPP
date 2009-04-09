# include "atcrun.h"

void ATCrun::Start (ExternalFileSys *FileSys){

	clock_t start_t;

	ATC *atc;

	RadarScreen *Radar;
	CmndInput *Input;
	AirborneInformation *AirInfo;
	HoldingInformation *HoldingInfo;
	CrashInformation *CrashInfo;
	UpdatesScreen *UpdatesScr;
	TimeScreen *TimeScr;
	ScoreScreen *ScoreScr;
	char c;


	textmode (ATC_TEXT_MODE);
	textbackground (BLUE);
	clrscr ();


	atc = new ATC(FileSys->Enviro());

	//Create Screens (must have THREE areas!)


	Radar = new RadarScreen (atc->Enviro()->Lmarks());
	Input = new CmndInput (atc->Enviro()->Lmarks(), atc->Traf());
	AirInfo = new AirborneInformation (atc->Traf());
	HoldingInfo = new HoldingInformation (atc->Traf());
	ScoreScr = new ScoreScreen();
	TimeScr = new TimeScreen();
	UpdatesScr = new UpdatesScreen();
	CrashInfo = new CrashInformation();

	Radar->Refresh();


	start_t=clock();

	do {
		assert (!atc->Traf()->Crashed());

		Input->Update();
		HoldingInfo->Refresh();
		AirInfo->Refresh();
		ScoreScr->Refresh (atc->Score());
		UpdatesScr->Refresh (atc->NoOfUpdates());

		while ((clock()-start_t)/CLK_TCK
				<
			(atc->Enviro()->TParameters()->UpdateInterval() *
				atc->NoOfUpdates())  &&

			!atc->Termination()){

			//enter commands
			Input->ProcessInput();
			TimeScr->Refresh  ((clock() - start_t)/CLK_TCK);


		}

		Radar->UnDisplayPlanes (atc->Traf());

		atc->AdvanceSys();


		//redraw screens
		Radar->DisplayPlanes (atc->Traf());

	}while ( ! atc->Termination() );

	//Crash message here
	if (ATCStatus::Finished == False)	{
		CrashInfo->Display (atc->Traf());
	}

	textmode (C80);
	_setcursortype (_NORMALCURSOR);
	clrscr();

//	FileSys->UpdateTopTen(atc->Score(),(clock()-start_t)/CLK_TCK);

	delete atc;
	delete Radar;
	delete Input;
	delete AirInfo;
	delete HoldingInfo;


}
