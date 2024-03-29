/**
 *========================================================
 * Tanggal		: 21-05-2022
 * Program		: Cyclops Calculator
 * File			: tree.h
 * Deskripsi	: header file ADT Binary Tree
 * IDE			: Dev-C++, VSCode
 * Author		: Raka Mahardika Maulana 	(RMM)				  
 *				  Mochamad Ferdy Fauzan  	(MFF)
 *				  Muhammad Daffa Raihandika (MDR)
 *========================================================
 */
 
#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Untuk menggunakan fungsi isdigit()
#include <stdio.h>
#include <math.h> // Untuk menggunakan fungsi matematika
#include "boolean.h"

#define PI 3.14159265359
#define MAX 0x3f3f3f3f

typedef struct tElmtNode *address; // Memberi nama alias alamat dari struct tElmtNode dengan nama address
typedef struct tElmtNode {
	boolean isOperator; // Untuk mengecek operator atau bukan
	double digit; 		// Untuk menyimpan angka
	char opr; 			// Untuk menyimpan operator
	address leftChild; 	// Pointer yang digunakan untuk menunjuk left child
	address rightChild;	// Pointer yang digunakan untuk menunjuk ke right child
}ElmtNode;

double calculate(address root, boolean *isSuccess);
/**
 * Modified from https://www.programmersought.com/article/95294413292/
 * Tanggal		: 21-05-2022
 * Author		: MDR
 * Deskripsi	: Modul ini bertujuan untuk menentukan operand yang akan menjadi root dan melakukan perhitungan di dalam tree.
 * 			   	  Modul ini mengembalikan nilai perhitungan ke root dan mengembalikan nilai angka jika tidak terdapat operator 
 * 			   	  dengan tipe data double
 */
 
double checkExpression(char str[],int start,int end);
 /**
 * Tanggal		: 22-05-2022
 * Author 		: MFF
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan cek karakter pertama yang ada pada expression dan mengembalikan nilai kode ASCII operand yang paling awal
 */
 
int searchOperator(char str[], int start, int end);
/**
 * Modified from https://www.programmersought.com/article/95294413292/
 * Tanggal		: 21-05-2022
 * Author		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menemukan operator berdasarkan prioritasnya
 *				  Mengembalikan nilai posisi operator ke dalam string	
 */	

address buildTree(char str[], int start, int end);
/**
 * Modified From https://www.programmersought.com/article/95294413292/
 * Tanggal		: 21-05-2022
 * Author		: MFF
 * Deskripsi	: Modul ini bertujuan untuk mengembalikan alamat dari tree yang berisi ekspresi matematika
 */
void postOrder(address root);
/**
 * Modified From https://www.programmersought.com/article/95294413292/
 * Tanggal		: 27-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan ekspresi matematika secara postfix
 * IS 			: Ekspresi matematika belum ditampilkan secara postfix
 * FS 			: Ekspresi matematika ditampilkan dengan menggunakan transversal post-order
 */

 void preOrder(address root);
/**
 * Tanggal 		: 27-05-2022
 * Author 		: MDR
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan ekspresi matematika secara prefix
 * IS 			: Ekspresi matematika belum ditampilkan secara prefix
 * FS 			: Ekspresi matematika ditampilkan dengan menggunakan transversal pre-order
 */
 
void inOrder(address root);
/**
 * Tanggal 		: 27-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan ekspresi matematika secara infix
 * IS 			: Ekspresi matematika belum ditampilkan secara infix
 * FS 			: Ekspresi matematika ditampilkan dengan menggunakan transversal in-order
 */
void deleteTree(address root);
/**
 * Tanggal 		: 21-05-2022
 * Author		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menghapus tree
 * IS 			: Tree belum dihapus
 * FS 			: Tree sudah dihapus
 */

#endif