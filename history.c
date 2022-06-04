/**
 *========================================================
 * Tanggal		: 22-05-2022
 * Program		: Cyclops Calculator
 * File			: history.c
 * Deskripsi	: File implementasi history
 * IDE			: Dev-C++, VSCode
 * Author		: Raka Mahardika Maulana 	(RMM)				  
 *				  Mochamad Ferdy Fauzan  	(MFF)
 *				  Muhammad Daffa Raihandika (MDR)
 *========================================================
 */

#include "history.h"

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan save ke dalam file untuk kalkulator standar.
 *				  Fungsi ini akan mengembalikan nilai 1 apabila terdapat error pada saat membuka file 
 *				  dan akan mengembalikan nilai 0 apabila tidak terdapat error
 */
int saveStdHistory(char *expression, double result){
    FILE* pFile = 0;
    struct historyStdCal Record;
    time_t _time;
    
    time (&_time);
    struct tm *tmi;
	  tmi = localtime (&_time);
    strftime (Record.time,100,"%d %b %Y %H:%M",tmi);
        
    strcpy(Record.expression, expression);
    Record.result = result;

    fopen_s(&pFile,"history.dat","ab+"); // append and update binary, can be read
    if(!pFile)
    return 1; //fopen error

    fwrite(&Record,sizeof(Record),1,pFile);
    fclose(pFile);	
    
    return 0;
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR, RMM
 * Deskripsi 	: Fungsi ini bertujuan untuk membaca file untuk history kalkulator standar.
 *				  Fungsi ini akan mengembalikan nilai 1 apabila terdapat error pada saat membuka file 
 *				  dan akan mengembalikan nilai 0 apabila tidak terdapat error
 */
int showStdHistory(){
    system("cls");
    
    FILE* pFile = 0;
    int i = 1;
    pFile = fopen("history.dat","ab+"); // append and update binary, can be read
    if(!pFile)
      return 1; //fopen error
	char StdHistory[] = 
		"\t\t\t    {=================================}\n\
		  \t    /   Standard Calculator History   |\n\
	 	    \t    @=================================~\n\
		";
		
	for(int i = 0; i < strlen(StdHistory); i++)
	{
		charToASCII(StdHistory[i]);
	}
	printf("\n");
    printf( "  \xDA\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n" );
    printf( "  \xB3 %-3s\xB3        %-12s\xB3         %-31s\xB3      %-14s\xB3\n", "No","Time", "Arithmetic Expression", "Result");
    printf( "  \xC3\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n" );

    do{
        fseek(pFile,(-i)*sizeof(Record),SEEK_END);
        fread(&Record,sizeof(Record),1,pFile);
        if(!feof(pFile) && i <= 15){
            if (ceil(Record.result) > Record.result)
                printf("  \xB3 %-3d\xB3 %-19s\xB3 %-39s\xB3 %-19f\xB3\n", i++, Record.time, Record.expression, Record.result);
            else
                printf("  \xB3 %-3d\xB3 %-19s\xB3 %-39s\xB3 %-19d\xB3\n", i++, Record.time, Record.expression, (int)Record.result);
        }
    }while(!feof(pFile) && i <= 15);
    printf( "  \xC0\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" );
        
    fclose(pFile);
    
    gotoxy(3,28);
	system("pause");
	return 0;	
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan save ke dalam file untuk kalkulator BMI.
 *				  Fungsi ini akan mengembalikan nilai 1 apabila terdapat error pada saat membuka file 
 *				  dan akan mengembalikan nilai 0 apabila tidak terdapat error
 */
int saveBmiHistory(float *height, float *weight, float *result){
    FILE* pFile = 0;
    struct historyBMICal Records;
    time_t _time;
    
    time (&_time);
    struct tm *tmi;
	  tmi = localtime (&_time);
    strftime (Records.time,100,"%d %b %Y %H:%M",tmi);
        
    Records.height = (*height);
    Records.weight = (*weight);
    Records.bmi = (*result);

    fopen_s(&pFile,"historyBMI.dat","ab+"); // append and update binary, can be read
    if(!pFile)
    return 1; //fopen error

    fwrite(&Records,sizeof(Records),1,pFile);
    fclose(pFile);	
    
    return 0;	
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR, RMM
 * Deskripsi 	: Fungsi ini bertujuan untuk membaca file untuk history kalkulator BMI.
 *				  Fungsi ini akan mengembalikan nilai 1 apabila terdapat error pada saat membuka file 
 *				  dan akan mengembalikan nilai 0 apabila tidak terdapat error
 */
int showBmiHistory(){
    system("cls");
    //screenMode();
    
    FILE* pFile = 0;
    int i = 1;
    pFile = fopen("historyBMI.dat","ab+"); // append and update binary, can be read
    if(!pFile)
      return 1; //fopen error

	char BMIHistory[] = 
		"\t\t\t    {=================================}\n\
		  \t    /      BMI Calculator History     |\n\
	 	    \t    @=================================~\n\
		";
		
	for(int i = 0; i < strlen(BMIHistory); i++)
	{
		charToASCII(BMIHistory[i]);
	}
	printf("\n");

    printf( "  \xDA\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n" );
    printf( "  \xB3 %-3s\xB3        %-12s\xB3      %-14s\xB3     %-14s\xB3      %-10s    \xB3\n", "No","Time", "Height", "Weight", "BMI");
    printf( "  \xC3\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n" );

    do{
        fseek(pFile,(-i)*sizeof(RecordBMI),SEEK_END);
        fread(&RecordBMI,sizeof(RecordBMI),1,pFile);
        if(!feof(pFile) && i <= 15){
        	printf("  \xB3 %-3d\xB3 %-19s\xB3 %-19.2f\xB3%-19.2f\xB3%-19.2f \xB3\n", i++, RecordBMI.time, RecordBMI.height, RecordBMI.weight, RecordBMI.bmi);
        }
    }while(!feof(pFile) && i <= 15);
    printf( "  \xC0\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" );
        
    fclose(pFile);
    
    gotoxy(3,28);
	system("pause");
	return 0;	
}

