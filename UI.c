/**
 *========================================================
 * Tanggal		: 22-05-2022
 * Program		: Cyclops Calculator
 * File			: UI.c
 * Deskripsi	: File implementasi User Interface Program
 * IDE			: Dev-C++, VSCode
 * Author		: Raka Mahardika Maulana 	(RMM)				  
 *				  Mochamad Ferdy Fauzan  	(MFF)
 *				  Muhammad Daffa Raihandika (MDR)
 *========================================================
 */

#include "UI.h"


int i, j, width, height, x, y;

/**
 * Tanggal		: 25-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk mengubah karakter tertentu menjadi ASCII.
 * IS 			: Karakter belum diubah menjadi ASCII.
 * FS 			: Karakter telah diubah menjadi ASCII.
 */
void charToASCII(char c) 
{
	/* Modul yang mengkonversi char ke char tertentu berdasarkan ASCII */
	switch(c)
	{
		case '=' :
			printf ("%c", 254);
			break;
		case '|' :
			printf ("%c", 222);
			break;
		case '#' :
			printf ("%c", 206);
			break;
		case '/' :
			printf ("%c", 221);
			break;
		case '&' :
			printf ("%c", 203);
			break;
		case '<' :
			printf ("%c", 204);
			break;
		case '>' :
			printf ("%c", 185);
			break;
		case 'Z' :
			printf ("%c", 075);
			break;
		case 'Q' :
			printf ("%c", 057);
			break;
		case '{' :
			printf ("%c", 201);
			break;
		case '}' :
			printf ("%c", 187);
			break;
		case '@' :
			printf ("%c", 200);
			break;
		case '~' :
			printf ("%c", 188);
			break;
		case 'X' :
			printf ("%c", 174);
			break;
		case '$' :
			printf("%c", 47);
			break;
		default :
			printf ("%c", c);		
	}
}

/**
 * Tanggal		: 25-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan isi tampilan menu
 * IS 			: Tampilan menu belum ditampilkan
 * FS 			: Tampilan menu ditampilkan
 */
void showMenu(){
	system("mode 58, 14"); system("cls");
	
	FILE *fm;
	char menu[200];
	fm = fopen("bin/menu.txt", "r");
	if(fm == NULL)
		{
			printf("\nFile not found...");
			getch();
			showMenu();
		}
	while(!feof(fm))
	{
		fgets(menu,sizeof(menu),fm);
			for(int i = 0; i < strlen(menu); i++)
			{
				charToASCII(menu[i]);
				
			}
	}
	fclose(fm);	
	printf("\n Choose menu : ");
}

/**
 * Tanggal		: 25-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan isi credit yang di ambil dari file
 * IS 			: Tampilan credit belum ditampilkan
 * FS 			: Tampilan credit ditampilkan
 */	
void showHelp(){
	system("mode 82, 100"); 
	system("cls");
	FILE *fh;
	char help[200];
	fh = fopen("bin/help.txt", "r");
	if(fh == NULL)
		{
			printf("\nFile not found...");
			getch();
			showMenu();
		}
	while(!feof(fh))
	{
		fgets(help,sizeof(help),fh);
			for(int i = 0; i < strlen(help); i++)
			{
				charToASCII(help[i]);
				
			}
	}
	fclose(fh);	
	printf("\n");
	system("pause");
	showMenu();
}

/**
 * Tanggal		: 25-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan isi help yang di ambil dari file
 * IS 			: Tampilan help belum ditampilkan
 * FS 			: Tampilan help ditampilkan
 */
void showCredit(){
	system("mode 63, 20");	system("cls");
		FILE*fc;
		char credit[200];
		fc = fopen("bin/credit.txt","r");
		if(fc == NULL)
		{
			printf("\nFile not found...");
			getch();
			showMenu();
		}
		while(!feof(fc))
		{
			fgets(credit,sizeof(credit),fc);
			for(int i = 0; i < strlen(credit) ; i++)
			{
				
				charToASCII(credit[i]);
				
			}
			
		}
		
		fclose(fc);	
		printf("\n");
		system("pause");
		showMenu();
}

/**
 * Tanggal		: 23-05-2022
 * Author 		: Cprogramming.com
 * Deskripsi 	: Kursor untuk menunjuk pada titik (x,y) tertentu
 * IS 			: Kursor masih menunjuk titik awal.
 * FS 			: kursor menunjuk titik yang didefinisikan.
 */
void gotoxy(int x, int y)
{
 HANDLE hConsoleOutput;
 COORD dwCursorPosition;
 dwCursorPosition.X = x;
 dwCursorPosition.Y = y;
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

/**
 * Tanggal		: 25-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan menu awal yang telah diubah menjadi ASCII.
 * IS 			: Karakter belum ditampilkan.
 * FS 			: karakter ditampilkan.
 */
void splashScreen(){


	char loading[] = 
"\t ======  ==      ==  ======  ==        ======   ========   ========\n\
\t\t\t==        ==    ==  ==       ==       ==    ==  ==     == ==\n\
\t\t\t==         ==  ==   ==       ==       ==    ==  ==     == ==\n\
\t\t\t==          ====    ==       ==       ==    ==  ========  =========\n\
\t\t\t==           ==     ==       ==       ==    ==  ==               ==  \n\
\t\t\t==           ==     ==       ==       ==    ==  ==               ==\n\
\t\t\t ======      ==      ======  ========  ======   ==        ========\n\
";



	char author[] =
 "\t              Created By :\n\
  \t\t\t\t\t\tRaka Mahardika Maulana\n\
  \t\t\t\t\t\tMochammad Ferdy Fauzan\n\
  \t\t\t\t\t\tMuhammad Daffa Raihandika\n\
 ";
 int i;
 gotoxy(17,8);
  
   for (int i = 0;i < strlen(loading);i++){
   		Sleep(2);
 		charToASCII(loading[i]);
 	}
  
   gotoxy(39,18);
     for (i = 0; author[i]!=0 ; i++) {
    Sleep(10);
    printf("%c", author[i]);
  }
  
}

/**
 * Tanggal		: 25-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan tampilan kalkulator yang ada pada standard calculator
 * IS 			: Tampilan kalkulator yang ada pada standard calculator belum ditampilkan
 * FS 			: Tampilan kalkulator yang ada pada standard calculator ditampilkan
 */
void showStdCalc()
{
	system("mode 100, 28");
	system("cls");
		FILE*fsc;
		char stdCal[200];
		fsc = fopen("bin/stdCalc.txt","r");
		if(fsc == NULL)
		{
			printf("\nFile not found...");
			getch();
			showMenu();
		}
		while(!feof(fsc))
		{
			fgets(stdCal,sizeof(stdCal),fsc);
			for(int i = 0; i < strlen(stdCal) ; i++)
			{
				
				charToASCII(stdCal[i]);
				
			}
			
		}
		
		fclose(fsc);	
		printf("\n");

}

/**
 * Tanggal		: 25-05-2022
 * Author 		: MDR
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan tampilan kalkulator yang ada pada standard calculator
 * IS 			: Tampilan kalkulator BMI yang ada pada BMI calculator belum ditampilkan
 * FS 			: Tampilan kalkulator BMI yang ada pada BMI calculator ditampilkan
 */
void showBMICalc()
{
	system("mode 92, 20");
	system("cls");
	char title[] = 
		"\t\t\t    {=================================}\n\
		  \t    /          BMI Calculator         |\n\
	 	    \t    @=================================~\n\
		";
		
	char outputBMI[] = 
		"\t\t\t\t\t\t{========================================}\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t<========================================>\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t@========================================~\n\
		";
		
	char inputBMI[] = 
		"  {=======================================}\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  @=======================================~\n\
		";
	
	for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");

	for(int i = 0; i < strlen(outputBMI); i++)
	{
		charToASCII(outputBMI[i]);
	}
	printf("\n");
	
	gotoxy(0,5);
	for(int i = 0; i < strlen(inputBMI); i++)
	{
		charToASCII(inputBMI[i]);
	}
}
