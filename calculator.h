/**
 *========================================================
 * Program		: Cyclops Calculator
 * File			: calculator.h
 * Deskripsi	: File header binary tree
 * IDE			: Dev-C++, VSCode
 * Author		: Raka Mahardika Maulana 	(RMM)				  
 *				  Mochamad Ferdy Fauzan  	(MFF)
 *				  Muhammad Daffa Raihandika (MDR)
 *========================================================
 */
 
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "tree.h"
#include <math.h>

typedef struct {
	char expression[100];
	double result;
	address expressionTree;	
}Calculator;

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR
 * Deskripsi 	: Modul ini bertujuan untuk membuat list kosong yang akan digunakan untuk menampung ekspresi matematika
 * IS 			: List belum terbuat
 * FS 			: List kosong dibuat dan isi dari struct Calculator telah di set
 */
void createCalculator(Calculator *calculator);

 /**
 * Tanggal		: 22-05-2022
 * Author 		: MFF
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan cek karakter pertama yang ada pada string.
 * 				  Jika karakter pertama merupakan '-', maka akan dikalikan oleh -1
 */
int checkExpression(char str[],int start,int end);

/**
 * Tanggal		: 22-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk user menginputkan ekspresi matematika di dalam kalkulator
 * IS 			: User belum dapat melakukan input pada kalkulator
 * FS 			: User dapat melakukan input operand dan operator pada kalkulator
 */
void insertExpression(Calculator *calculator);

/**
 * Tanggal		: 22-05-2022
 * Author 		: RMM
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan perhitungan dari ekspresi matematika yang diinputkan oleh user pada tree. 
 * 				  Fungsi ini akan mengembalikan nilai true jika perhitungan pada tree berhasil dilakukan
 */
boolean isCalculateSuccess(Calculator *calculator, address root);

/**
 * Tanggal		: 22-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan hasil ekspresi matematika yang diinputkan oleh user pada kalkulator
 * IS 			: Hasil ekspresi matematika belum ditampilkan pada kalkulator
 * FS 			: Hasil ekspresi matematika ditampilkan pada kalkulator
 */
void printResult(Calculator calculator, boolean isSuccess, address root);

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR
 * Deskripsi 	: Fungsi ini bertujuan untuk menanyakan kepada user apakah akan mencoba kalkulator kembali atau tidak. 
 * 				  Fungsi ini akan mengembalikan nilai true apabila user menginputkan huruf 'y' atau 'Y' 
 * 				  dan akan mengembalikan nilai false apabila user menginputkan huruf 'n' atau 'N'
 */
boolean isContinueCalculator();

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR
 * Deskripsi 	: Fungsi ini bertujuan untuk mengecek apakah terdapat karakter yang bukan operator atau tidak valid pada ekspresi yang diinputkan oleh user.
 *                Fungsi ini akan mengembalikan nilai false apabila terdapat karakter yang bukan operator atau tidak valid 
 */
boolean isValidExpression(char *expression);

#endif