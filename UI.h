/**
 *========================================================
 * Tanggal		: 22-05-2022
 * Program		: Cyclops Calculator
 * File			: UI.h
 * Deskripsi	: File header User Interface Program
 * IDE			: Dev-C++, VSCode
 * Author		: Raka Mahardika Maulana 	(RMM)				  
 *				  Mochamad Ferdy Fauzan  	(MFF)
 *				  Muhammad Daffa Raihandika (MDR)
 *========================================================
 */

#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <windows.h>
#include <MMsystem.h>
#include <ctype.h>
#include <conio.h>
#include <unistd.h>


/**
 * Tanggal		: 23-05-2022
 * Author 		: Cprogramming.com
 * Deskripsi 	: Kursor untuk menunjuk pada titik (x,y) tertentu
 * IS 			: Kursor masih menunjuk titik awal.
 * FS 			: kursor menunjuk titik yang didefinisikan.
 */	
void gotoxy(int x, int y);

/**
 * Tanggal		: 25-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk mengubah karakter tertentu menjadi ASCII.
 * IS 			: Karakter belum diubah menjadi ASCII.
 * FS 			: Karakter telah diubah menjadi ASCII.
 */	
void charToASCII(char c);

/**
 * Tanggal		: 25-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan isi tampilan menu
 * IS 			: Tampilan menu belum ditampilkan
 * FS 			: Tampilan menu ditampilkan
 */	
void showMenu();

/**
 * Tanggal		: 25-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan isi help yang di ambil dari file
 * IS 			: Tampilan help belum ditampilkan
 * FS 			: Tampilan help ditampilkan
 */	
void showHelp();

/**
 * Tanggal		: 25-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan isi credit yang di ambil dari file
 * IS 			: Tampilan credit belum ditampilkan
 * FS 			: Tampilan credit ditampilkan
 */	
void showCredit();

/**
 * Tanggal		: 25-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan menu awal yang telah diubah menjadi ASCII.
 * IS 			: Karakter belum ditampilkan.
 * FS 			: karakter ditampilkan.
 */	
void splashScreen();

/**
 * Tanggal		: 25-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan tampilan kalkulator yang ada pada standard calculator
 * IS 			: Tampilan kalkulator yang ada pada standard calculator belum ditampilkan
 * FS 			: Tampilan kalkulator yang ada pada standard calculator ditampilkan
 */
void showStdCalc();

/**
 * Tanggal		: 25-05-2022
 * Author 		: MDR
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan tampilan kalkulator yang ada pada standard calculator
 * IS 			: Tampilan kalkulator BMI yang ada pada BMI calculator belum ditampilkan
 * FS 			: Tampilan kalkulator BMI yang ada pada BMI calculator ditampilkan
 */
void showBMICalc();

#endif