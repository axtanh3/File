#include <dos.h>
#include <conio.h>
#include <stdio.h>

void f(char *menu[]);
void f1(char *menu[], int curPos, int x, int y);
int main(void)
{
  int curPos;
	char c, c1;
	char *menu[] =
	{
		"This is a menu",
		"Menu 1        ",
		"Menu 2        ",
		"Menu 3        ",
		"Menu 4        ",
		"Exit          "
	};
	f(menu);
	curPos = 1;
	f1(menu, curPos, 1, curPos);
	
	do
	{
		Start:
		c = getch();
		switch (c)
		{
			case 80:
			{
				if (curPos != 5)
					curPos++;
				else 
					curPos = 1;
				f(menu);
				f1(menu, curPos, 1, curPos);
			}
				break;	
			
			case 72:
			{
				if (curPos != 1)
					curPos--;
				else
					curPos = 5;
				f(menu);
				f1(menu, curPos, 1, curPos);			
			} 
				break;
			case 13:
			{
				gotoxy(1, 10);
				cprintf("You are selecting [%s], continue? (Y|N)\r\n", menu[curPos]);
				c1 = getch();
				if (c1 == 'Y' || c1 == 'y')
					goto Start;
				else
					goto Stop;
			}
			break;
		}
	}
	while (1);
	Stop:
	return 0;
}

void f(char *menu[])
{
	int i;
	textmode(2);
	clrscr();
	textbackground(BLUE);
	textcolor(WHITE);
	for (i = 0; i < 6; i++)
		cprintf("%s\r\n", menu[i]);
}
void f1(char *menu[], int curPos, int x, int y)
{
	gotoxy(x, y+1);
	textbackground(GREEN);
	cprintf("%s\r\n", menu[curPos]);
}
