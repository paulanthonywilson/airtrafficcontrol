#include <conio.h>
# include <stdio.h>
# include <iostream.h>

void ScreenInfOut ();

int main(void)
{
   textmode (C80);
   textcolor (WHITE);
   textbackground (BLACK);
   clrscr();

   getch();

   textmode (C4350);
   window (5, 5, 35, 20);
	textcolor (BLACK);
	textbackground (WHITE);
   clrscr();


   ScreenInfOut();

   getch();
   textmode (C80);
   getch();
   window (5, 5, 40, 24);
	textcolor (GREEN);
	textbackground (BLUE);
	clrscr();


	getch();

   ScreenInfOut();
	getch();
   return 0;
}



void ScreenInfOut ()	{

	struct text_info ti;
	gettextinfo(&ti);
	cprintf("window left      %2d\r\n",ti.winleft);
	cprintf("window top       %2d\r\n",ti.wintop);
	cprintf("window right     %2d\r\n",ti.winright);
	cprintf("window bottom    %2d\r\n",ti.winbottom);
	cprintf("attribute        %2d\r\n",ti.attribute);
	cprintf("normal attribute %2d\r\n",ti.normattr);
	cprintf("current mode     %2d\r\n",ti.currmode);
	cprintf("screen height    %2d\r\n",ti.screenheight);
	cprintf("screen width     %2d\r\n",ti.screenwidth);
	cprintf("current x        %2d\r\n",ti.curx);
	cprintf("current y        %2d\r\n",ti.cury);

   return ;



}