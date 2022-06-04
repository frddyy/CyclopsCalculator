/**
 *========================================================
 * Tanggal		: 22-05-2022
 * Program		: Cyclops Calculator
 * File			: calculator.c
 * Deskripsi	: File implementasi kalkulator standar
 * IDE			: Dev-C++, VSCode
 * Author		: Raka Mahardika Maulana 	(RMM)				  
 *				  Mochamad Ferdy Fauzan  	(MFF)
 *				  Muhammad Daffa Raihandika (MDR)
 *========================================================
 */

#include "calculator.h"

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR
 * Deskripsi 	: Modul ini bertujuan untuk membuat list kosong yang akan digunakan untuk menampung ekspresi matematika
 * IS 			: List belum terbuat
 * FS 			: List kosong dibuat dan isi dari struct Calculator telah di set
 */
void createCalculator(Calculator *calculator) 
{
	// pemberian nilai default
	memset(calculator->expression, '\0', sizeof(calculator->expression));
	calculator->result = 0;
	calculator->expressionTree = (address)malloc(sizeof(struct tElmtNode));
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR
 * Deskripsi 	: Fungsi ini bertujuan untuk mengecek apakah terdapat karakter yang bukan operator atau tidak valid pada ekspresi yang diinputkan oleh user.
 *                Fungsi ini akan mengembalikan nilai false apabila terdapat karakter yang bukan operator atau tidak valid 
 */
boolean isValidExpression(char *expression) {
	int i;
	
	// Check apakah pada string terdapat simbol yang bukan operator atau tidak valid
	for(i=strlen(expression)-1 ; i>=0 ; i--)
    {
        if(!isdigit(expression[i]) 	&& expression[i] != '-' && expression[i] != '+' 
			        && expression[i] != '/' && expression[i] != '*' && expression[i] != 'p'
			        && expression[i] != '^' && expression[i] != '%' && expression[i] != 'v' 
					&& expression[i] != ',' && expression[i] != '(' && expression[i] != ')' 
            ) 
        {
        	gotoxy(15, 5);
			printf("Invalid input!!\n");
			return false;				
		}
    }
    
    return true;
}

 /**
 * Tanggal		: 22-05-2022
 * Author 		: MFF
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan cek karakter pertama yang ada pada string.
 * 				  Jika karakter pertama merupakan '-', maka akan dikalikan oleh -1
 */
int checkExpression(char str[],int start,int end){
    int i;
    int sum = 0;
    int flag = 1;
    if(str[start] == '-'){
        flag = -1;
        start++;
    }
    for(i = start; i <= end; i++){
        if(!isdigit(str[i])) return MAX;
        sum = sum * 10 + str[i] - '0';
    }
    return sum * flag;
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk user menginputkan ekspresi matematika di dalam kalkulator
 * IS 			: User belum dapat melakukan input pada kalkulator
 * FS 			: User dapat melakukan input operand dan operator pada kalkulator
 */
void insertExpression(Calculator *calculator) {
	// melakukan proses insertion
	printf("\n\n");
    fflush(stdin);
    gotoxy(15,4);
    scanf("%s", calculator->expression);
    printf("\n\n");
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: RMM
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan perhitungan dari ekspresi matematika yang diinputkan oleh user pada tree. 
 * 				  Fungsi ini akan mengembalikan nilai true jika perhitungan pada tree berhasil dilakukan
 */
boolean isCalculateSuccess(Calculator *calculator, address root) {
	boolean isSuccess = true;
	
	// hitung hasil dari ekspresi pada tree
	calculator->result = calculate(root, &isSuccess);
	
	// kembalikan status perhitungan
	return isSuccess;
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan hasil ekspresi matematika yang diinputkan oleh user pada kalkulator
 * IS 			: Hasil ekspresi matematika belum ditampilkan pada kalkulator
 * FS 			: Hasil ekspresi matematika ditampilkan pada kalkulator
 */
void printResult(Calculator calculator, boolean isSuccess, address root) {
	
	// print calculator sesuai dengan format
    if(!isSuccess){
    	// jika proses kalkulasi tidak berhasil
		gotoxy(12,5);
        printf("= %s","Error!! Can't Divide by Zero");
    }
    else if (ceil(calculator.result) > calculator.result){
    	// jika proses kalkulasi berhasil dan hasilnya adalah bilangan desimal
		gotoxy(15,5);
        printf("= %f",calculator.result);
    }
	else{
		// jika proses kalkulasi berhasil dan hasilnya adalah bilangan bulat
		gotoxy(15,5);
        printf("= %d",(int)calculator.result);
    }
    
    gotoxy(64, 8);
    preOrder(root);
    gotoxy(64, 9);
    inOrder(root);
    gotoxy(64, 10);
    postOrder(root);
}

/**
 * Tanggal		: 22-05-2022
 * Author 		: MDR
 * Deskripsi 	: Fungsi ini bertujuan untuk menanyakan kepada user apakah akan mencoba kalkulator kembali atau tidak. 
 * 				  Fungsi ini akan mengembalikan nilai true apabila user menginputkan huruf 'y' atau 'Y' 
 * 				  dan akan mengembalikan nilai false apabila user menginputkan huruf 'n' atau 'N'
 */
boolean isContinueCalculator() {
	char choice;
	
	// tentukan apakah user mengulang proses atau tidak
	while(true){
		gotoxy(15,24);
    	printf("Try Again? (y/n) : ");
        fflush(stdin);
        scanf("%c", &choice);
            
        if(choice == 'y' || choice == 'Y'){
            return true;
        }else if(choice == 'n' || choice == 'N') {
        	return false;
		}else {
			gotoxy(15,25);
            printf("Please input a valid command; y(yes), n(no)\n");
        }
    }
}