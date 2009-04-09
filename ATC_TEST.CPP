# include "atcrun.h"

extern void DisplayTopTen(ExternalFileSys *efs);


int main(){
	ExternalFileSys *efs;
	efs=new ExternalFileSys();
	ATCrun *atcr;
	int select;
	int no,got;

    do{
	int count=0;
	printf("\n\n\tGAMES\n");
	printf("\t=====\n\n");
	while (efs->Games(count)!='\0'){
		printf("%d\t%s\n",count+1,efs->Games(count));
		count++;
	}
	if (count==0){printf("\nNo Games To Play!!!");return 0;}
	printf("\n\n\nDo you want 1) to play a game\n");
	printf("            2) view top ten\n");
	printf("            3) quit\n");
	printf("Make selection:");
	got =scanf("%d",&select);
	if (select==3)break;
	printf("\nSelect the game number....?");
	scanf("%d",&no);

	efs->CurrentGame(no);


	if (select==2) {efs->ViewTopTen();
				DisplayTopTen(efs);}

	if (select==1) {
		efs->ReadEnvironment();
		if (! efs->Error()){
			atcr=new ATCrun();
			atcr->Start(efs);
		}
		else
			printf("This file is set up incorrectly!!\n");
//		DisplayTopTen(efs);
	}


	}while(select!=3 && got==1);

	return 0;

}

void DisplayTopTen(ExternalFileSys *efs){
	int count=0,c;
	if (efs->TopTen()[count].name[0]=='\0')
		printf("\nGame has not yet been played!\n");
	else{
	printf("\nPOS\tNAME          SCORE   TIME\n");
	printf("===\t============  =====   ====\n");
	while(efs->TopTen()[count].name[0]!='\0'){
		printf("%d\t%s\t\t%d\t%d\n",
			count+1,
			efs->TopTen()[count].name,
			efs->TopTen()[count].score,
			efs->TopTen()[count].time);
		count++;
		}
	printf("\nPress any key to continue...");

	}

}