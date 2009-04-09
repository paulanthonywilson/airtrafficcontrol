# include "external.h"



ExternalFileSys::ExternalFileSys () {
	Enviro_c= new Environment( 0, 0, 0 );
	Error_c=OK;
	int count=0;
	struct ffblk ffblk;
	int done;
	done = findfirst("*.ENV",&ffblk,0);
	while (!done)
	{
	 games_c[count]=new char[12];
	 strcpy(games_c[count],ffblk.ff_name);
	 done = findnext(&ffblk);
	 count++;
	}
	games_c[count]='\0';
}

void ExternalFileSys::ReadEnvironment() {
	Error_c=OK;
	char line[LIMIT];
	FILE *env_file;
	line_no_c=1;
	eof=False;
	Timings *TParameters;
	Landmarks *Lmarks;

	TParameters=new Timings();
	Lmarks=new Landmarks();

	env_file= fopen(CurGame_c, "r");

	ReadLine ( line,env_file );
	while ( ! eof && ! Error_c ){
		if ( line==strstr(line,"update"))
			CreateUpdate( line,TParameters );
		else if (line==strstr(line,"newplane"))
			CreateNewplane( line,TParameters );
		else if (line==strstr(line,"width")) CreateWidth( line );
		else if (line==strstr(line,"height")) CreateHeight( line );
		else if (line==strstr(line,"exit"))
			CreateExit( line,Lmarks );
		else if (line==strstr(line,"beacon"))
			CreateBeacon( line,Lmarks );
		else if (line==strstr(line,"airport"))
			CreateAirport( line,Lmarks );
		else if (line==strstr(line,"flightpath"))
			CreateFlightpath( line,Lmarks );
		else    Error_c=IncorrectType;

		if ( Error_c)printf("Error Type no. %d\n",Error_c);

		if ( ! Error_c ) ReadLine( line,env_file );
	}

	fclose(env_file);
	if (!Error_c && (TParameters->CreationInterval()==0 ||
			TParameters->UpdateInterval()==0 ))
		Error_c=ParametersNotSet;
	if (!Error_c && (Lmarks->NoOfGates() + Lmarks->NoOfAirports())<2)
		Error_c=NotEnoughDests;
	if ( Error_c ); //DestructEnviro();
	else Enviro_c=new Environment(Lmarks,TParameters,CurGame_c);

}

void ExternalFileSys::ReadLine( char lin[],FILE *e_file ){
	int nxt=0, c;
	Boolean found=False,remark=False;

	do { c=fgetc(e_file);
		if (c==EOF) {
			eof=True;break;
		}
		if (c=='#') remark=True;
		if (c<='z' && c>='A' &&
			 ! remark && ! found) found=True;

		if (found && ! remark) {
			if (nxt<LIMIT){
				lin[nxt]=c;
				nxt++;
				}
			else{
				Error_c=ExpressionTooLong;break;
				}
		}

		if (c=='\n'){
			 line_no_c++;
			 remark=False;

		}

	}while ( c != ';' );
	lin[nxt]='\0';

	}


void ExternalFileSys::CreateUpdate(char lin[],Timings *t){
		int UInterval;
		UInterval=FindPara(lin,6);
		if ( ! Error_c ) t->ChangeUInterval(UInterval);

}

void ExternalFileSys::CreateNewplane(char lin[],Timings *t){
		int CInterval;
		CInterval=FindPara(lin,8);
		if (! Error_c) t->ChangeCInterval(CInterval);
;}

void ExternalFileSys::CreateWidth(char lin[]){
		int width;
		width=FindPara(lin,5);
		if (! Error_c){
			if (width>=10 && width<=30)
				Position::MaxX=width;
			else
				Error_c=IncorrectDimension;
		}
}

void ExternalFileSys::CreateHeight(char lin[]){
		int height;
		height=FindPara(lin,6);
		if (! Error_c){
			if (height>=10 && height<=30)
				Position::MaxY=height;
			else
				Error_c=IncorrectDimension;
		}

}

void ExternalFileSys::CreateExit(char lin[],Landmarks *l){
		int nxt=4;
		Position p;
		Heading h;
		Gate *g;
		FindChar(lin,nxt,':');
		FindNxt(lin,nxt);
		while (lin[nxt]!=';'){
			if (l->NoOfGates()>9){Error_c=MoreThanTenLmarks;break;}
			if (Error_c)break;
			FindChar(lin,nxt,'(');
			if (Error_c)break;
			p=FindPos(lin,nxt);
			if (Error_c)break;
			h=FindHead(lin,nxt);
			if (Error_c)break;
			FindChar(lin,nxt,')');
			if (Error_c)break;
			if (! p.inBoundary()){Error_c=PosError;break;}
			if (! p.NextMove(h).inField()){Error_c=HeadError;break;}
			if (AlreadyExists(l,p)){Error_c=PosAlreadyExists;break;}
			g=new Gate(p,l->NoOfGates(),h);
			l->AddGate(g);
			FindNxt(lin,nxt);
		}

}





void ExternalFileSys::CreateBeacon(char lin[],Landmarks *l){
		int nxt=6;
		Position p;
		Beacon *b;
		FindChar(lin,nxt,':');
		FindNxt(lin,nxt);
		while (lin[nxt]!=';'){
			if (l->NoOfBeacons()>9){Error_c=MoreThanTenLmarks;break;}
			if (Error_c)break;
			FindChar(lin,nxt,'(');
			if (Error_c)break;
			p=FindPos(lin,nxt);
			if (Error_c)break;
			FindChar(lin,nxt,')');
			if (Error_c)break;
			if (! p.inField()){Error_c=PosError;break;}
			if (AlreadyExists(l,p)){Error_c=PosAlreadyExists;break;}
			b=new Beacon(p,l->NoOfBeacons());
			l->AddBeacon(b);
			FindNxt(lin,nxt);
		}


}

void ExternalFileSys::CreateAirport(char lin[],Landmarks *l){
		int nxt=7;
		Position p;
		Heading h;
		Airport *a;
		FindChar(lin,nxt,':');
		FindNxt(lin,nxt);
		while (lin[nxt]!=';'){
			if (l->NoOfAirports()>9){Error_c=MoreThanTenLmarks;break;}
			if (Error_c)break;
			FindChar(lin,nxt,'(');
			if (Error_c)break;
			p=FindPos(lin,nxt);
			if (Error_c)break;
			h=FindHead(lin,nxt);
			if (Error_c)break;
			FindChar(lin,nxt,')');
			if (Error_c)break;
			if (! p.inField()){Error_c=PosError;break;}
			if (! p.NextMove(h).inField()){Error_c=HeadError;break;}
			if (AlreadyExists(l,p)){Error_c=PosAlreadyExists;break;}
			a=new Airport(p,l->NoOfAirports(),h);
			l->AddAirport(a);
			FindNxt(lin,nxt);
		}

}

void ExternalFileSys::CreateFlightpath(char lin[],Landmarks *l){
		int nxt=10;
		Position p1,p2;
		FlightPath *f;
		FindChar(lin,nxt,':');
		FindNxt(lin,nxt);
		while (lin[nxt]!=';'){
			if (l->NoOfFlightPaths()>9){Error_c=MoreThanTenLmarks;break;}
			if (Error_c)break;
			FindChar(lin,nxt,'[');if (Error_c)break;
			FindChar(lin,nxt,'(');if (Error_c)break;
			p1=FindPos(lin,nxt);if (Error_c)break;
			FindChar(lin,nxt,')');if (Error_c)break;
			FindChar(lin,nxt,'(');if (Error_c)break;
			p2=FindPos(lin,nxt);if (Error_c)break;
			FindChar(lin,nxt,')');if (Error_c)break;
			FindChar(lin,nxt,']');if (Error_c)break;

			if (! p1.inField() ||
				! p2.inField() ||
				p1.AngleTo(p2)%45!=0)
				{Error_c=PosError;break;}
			f=new FlightPath(p1,p2);
			l->AddFlightPath(f);
			FindNxt(lin,nxt);
		}


;}

int ExternalFileSys::FindPara(char lin[],int nxt){
		int r=0;
		FindChar(lin,nxt,'=');
		if (! Error_c) r=FindNum(lin,nxt);
		if (! Error_c) FindChar(lin,nxt,';');
		return r;
}

void ExternalFileSys::FindChar(char lin[],int &nxt,int charval){
		while(lin[nxt]==' ' ||
			lin[nxt]=='\t' ||
			lin[nxt]=='\n')nxt++;

		if (lin[nxt]!=charval) Error_c=SyntaxError;
		nxt++;
}

int ExternalFileSys::FindNum(char lin[],int &nxt){
		int count=0,p,n=0;
		while(lin[nxt]==' ' ||
			lin[nxt]=='\t' ||
			lin[nxt]=='\n')nxt++;

		while(lin[nxt]>='0' && lin[nxt]<='9'){nxt++;count++;}

		if (count==0) Error_c=SyntaxError;
		for (p=0;p<count;p++)
			n=n+(lin[nxt-p-1]-'0')*pow10(p);

		return n;
}

void ExternalFileSys::FindNxt(char lin[],int &nxt){
		while(lin[nxt]==' ' ||
			lin[nxt]=='\t' ||
			lin[nxt]=='\n')nxt++;
}

Position ExternalFileSys::FindPos(char lin[],int &nxt){
		int x,y;
		Position p(0,0);
		x=FindNum(lin,nxt);
		if (Error_c) return p;
		y=FindNum(lin,nxt);
		if (Error_c) return p;
		p.Set(x,y);
		return p;
}

Heading ExternalFileSys::FindHead(char lin[],int &nxt){
		int deg;
		FindChar(lin,nxt,'D');
		if (Error_c) return Heading::DegToHeading(0);
		deg=FindNum(lin,nxt);
		if (Error_c) return Heading::DegToHeading(0);
		return Heading::DegToHeading(deg);
}

Boolean ExternalFileSys::AlreadyExists(Landmarks *l,Position p){
		int count;
		for(count=0;count<(l->NoOfGates());count++)
			if (l->AllGates()[count]->GrndPos()==p)return True;
		for(count=0;count<(l->NoOfAirports());count++)
			if (l->AllAirports()[count]->GrndPos()==p)return True;
		for(count=0;count<(l->NoOfBeacons());count++)
			if (l->AllBeacons()[count]->GrndPos()==p)return True;

		return False;
}

void ExternalFileSys::ViewTopTen(){
	eof=False;
	FILE *tt_file;
	int count=0,nxt;
	char lin[30];

	if ((tt_file= fopen(tt_fname, "r"))== NULL){
		TopTen_c[0].name[0]='\0';return ;
	}

	while(! eof && count<5){
		nxt=0;
		ReadLine(lin,tt_file);
		while(lin[nxt]!=' ')nxt++;
		lin[nxt]='\0';
		strcpy(TopTen_c[count].name,lin);
		nxt++;
		TopTen_c[count].score=FindNum(lin,nxt);
		TopTen_c[count].time=FindNum(lin,nxt);
		count++;
	}

	TopTen_c[count].name[0]='\0';

	fclose(tt_file);

}

Boolean ExternalFileSys::InTopTen(int NoSafe,int t){
	ViewTopTen();

	int count=0;

	FindPos(NoSafe,t,count);

	if (TopTen_c[count].name[0]!='\0' || count<10 ) return True;

	return False;

}

void ExternalFileSys::UpdateTopTen(int NoSafe,int t){

	if (!InTopTen(NoSafe,t)) return;
	char user[15];
	printf("\nYou have made the Top Ten!! Please enter your name-");
	scanf("%s",user);
	if (user=='\0') strcpy(user,"Unknown");

	int count=0,c=0;
	FILE *tt_file;
	tt_file= fopen(tt_fname, "w");

	FindPos(NoSafe,t,count);

	c=count;
	while(TopTen_c[c].name[0]!='\0')c++;

	while(count!=c+1){
		TopTen_c[c+1]=TopTen_c[c];
		c--;
	}

	strcpy(TopTen_c[count].name,user);
	TopTen_c[count].score=NoSafe;
	TopTen_c[count].time=t;

	count=0;
	while(TopTen_c[count].name[0]!='\0'){
		fprintf(tt_file,"%s %d %d;\n",TopTen_c[count].name,
			TopTen_c[count].score,TopTen_c[count].time);
		count++;
	}
	fclose(tt_file);
}

void ExternalFileSys::FindPos(int NoSafe, int t,int &count){
	while(TopTen_c[count].name[0]!='\0'){
		if (TopTen_c[count].score<NoSafe) break;
		if (TopTen_c[count].score==NoSafe &&
		    TopTen_c[count].time>=t )break;
		count++;
	}

}



