/**
 *========================================================
 * Tanggal		: 22-05-2022
 * Program		: Cyclops Calculator
 * File			: bmi.c
 * Deskripsi	: File implementasi kalkulator BMI
 * IDE			: Dev-C++, VSCode
 * Author		: Raka Mahardika Maulana 	(RMM)				  
 *				  Mochamad Ferdy Fauzan  	(MFF)
 *				  Muhammad Daffa Raihandika (MDR)
 *========================================================
 */

#include "bmi.h"

/**
 * Tanggal		: 22-05-2022
 * Author 		: RMM
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan perhitungan BMI. Fungsi ini akan mengembalikan nilai hasil perhitungan tersebut
 */
float calculateBMI(dataBMI data) {
	data.height = convertHeight(data);
   	data.bmi = data.weight / (data.height * data.height);
   
   	return data.bmi;
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: RMM
 * Deskripsi 	: Fungsi ini bertujuan untuk mengkonversi tinggi dari cm ke m
 */
float convertHeight(dataBMI data){
	return data.height/100;
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan hasil BMI
 * IS			: Hasil result BMI belum ditampilkan
 * FS			: Hasil result BMI ditampilkan
 */
void resultBMI(dataBMI data){
	gotoxy(6,10);
	printf("Your BMI\t\t:  %.2f\n", data.bmi); 
	gotoxy(6,12);
	 if(data.bmi <= 18.5)  
    {  
        printf("Your BMI is considered Underweight\n");  
    }  
    else if(data.bmi > 18.5 && data.bmi <= 24.9)  
    {  
        printf("Your BMI is considered Healthy\n");  
    }  
    else if(data.bmi >= 25 && data.bmi <= 29.9)  
    {  
        printf("Your BMI is considered Overweight\n");  
    }  
     
    else if(data.bmi >= 30)  
    {  
        printf("Your BMI is considered Obese\n");  
    }  
    else  
    {  
        printf("Wrong entry!\n");  
    }  
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk user melakukan input pada kalkulator BMI
 * IS			: User belum dapat menginputkan tinggi dan berat badan dalam kalkulator BMI
 * FS			: User dapat menginputkan tinggi dan berat badan dalam kalkulator BMI
 */
void inputBMI(dataBMI data){	
	gotoxy(6,6);
	printf ("Your Weight\t: ");
	gotoxy(31,6);
	printf("kg");
	gotoxy(27,6);
	scanf("%f",&data.weight);
	
	gotoxy(6,8);
	printf("Your Height\t: ");
	gotoxy(31,8);
	printf("cm");
	gotoxy(27,8);
	scanf("%f",&data.height);
	data.bmi = calculateBMI(data);
	if(data.height > 0 && data.weight > 0){	
		resultBMI(data);
		saveBmiHistory(&data.height, &data.weight, &data.bmi);
	}else{
		gotoxy(6,12);
		printf("Invalid Input!!\n");
	}
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan keterangan kateogori BMI
 * IS			: Keterangan kategori BMI belum ditampilkan
 * FS			: Keterangan kategori BMI ditampilkan
 */
void printCategories(){
	gotoxy(63,6);
	printf("BMI Categories\n");
	gotoxy(50,8);
	printf("Underweight : < 18.5\n");
	gotoxy(50,10);
	printf("Normal weight : 18.5 - 24.9\n");
	gotoxy(50,12);
	printf("Overweight : 25 - 29.9\n");
	gotoxy(50,14);
	printf("Obesity : BMI of 30 or greater\n");
}