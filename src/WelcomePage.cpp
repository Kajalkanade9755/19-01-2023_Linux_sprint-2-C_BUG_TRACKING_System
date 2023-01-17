#include "WelcomePage.h"

WelcomePage::WelcomePage()
{
    //ctor
}
#include<stdio.h>
#include<windows.foundation.h>
#include<stdlib.h>
#include<time.h>
using namespace std;




void WelcomePage:: ClearConsoleToColors(int ForgC, int BackC)
 {
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                     //This is used to reset the carat/cursor to the top left.
 COORD coord = {0, 0};
                  //A return value... indicating how many chars were written
                    //   not used but we need to capture this since it will be
                      //   written anyway (passing NULL causes an access violation).
  DWORD count;

                               //This is a structure containing all of the console info
                      // it is used here to find the size of the console.
 CONSOLE_SCREEN_BUFFER_INFO csbi;
                 //Here we will set the current color
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                          //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
}



 void WelcomePage:: SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}




void WelcomePage:: Welcome_screen() {
//system("clear");
ClearConsoleToColors(0,11);
//SetColor(1);
printf("\n\n\n\n");
printf("\t\t\t\t\t\t\t\t LOADING.... \t\n   ");
 printf("\n\n\n\n");
printf("\n\t\t\t\t\t\t\t\t\t*");
int str1;
for(str1=1;str1<70; str1++) {
                printf("*");
        }
        printf("\n");
        Sleep(1000);
	char prjct[] = {"  BUG TRACKER PROJECT  "};

	for (int i = 0; prjct[i] != '\0'; i++) {
		printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
		Sleep(100);
		printf("%c\n",prjct[i]);
	}

	printf("\n");
	printf("\n\t\t\t\t\t\t\t\t\t*");

	for (int str = 1; str < 70; str++) {
//	sleep(1);
		printf("*");
	}
	printf("\n");

	for (int i = 0; i < 120; i++)
		printf("_");

	printf("\n\n\n\n\t\t\t\t\t M");
	printf("a");
	printf("d");
	printf("e ");
	printf("- b");
	printf("y");
	char name[200][200] = {" 1.kajal\n\t\t\t\t\t\t2.sayani\n\t\t\t\t\t\t3.parveen\n\t\t\t\t\t\t4.divya\n\t\t\t\t\t\t5.bidipta\n\t\t\t\t\t\t6.shikha"};

	for (int i = 0; i < 6; i++) {
		printf("\n\t\t\t\t\t       ");
		for (int j = 0; name[i][j] != '\0'; j++) {
			printf("%c", name[i][j]);
		}
	}
printf("\n\n");
Sleep(1000);
getchar();
system("cls");
}


