/**
 *========================================================
 * Tanggal		: 21-05-2022
 * Program		: Cyclops Calculator
 * File			: main.c
 * Deskripsi	: Main Driver (alur utama dari program)
 * IDE			: Dev-C++, VSCode
 * Author		: Raka Mahardika Maulana 	(RMM)				  
 *				  Mochamad Ferdy Fauzan  	(MFF)
 *				  Muhammad Daffa Raihandika (MDR)
 *========================================================
 */
 
#include "UI.h"
#include "calculator.h"
#include "bmi.h"
#include "history.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char input;
	Calculator calculator;
	boolean isSuccess;
	dataBMI data;

	PlaySound(TEXT("bin/Chipmunk.wav"),NULL,SND_SYNC);
	
	splashScreen();
	getch();
	
	menu:
		do{
			system("cls");
			showMenu();
			input = getch();
			if(input == '1'){
				do{	
					system("cls");
					showStdCalc();
					createCalculator(&calculator);
					insertExpression(&calculator);
					if(!isValidExpression(calculator.expression)){
						getch();
						system("cls");
						goto menu;
					}else{
						checkExpression(calculator.expression, 0, strlen(calculator.expression)-1);
						calculator.expressionTree = buildTree(calculator.expression, 0, strlen(calculator.expression)-1);
						boolean isSuccess = isCalculateSuccess(&calculator, calculator.expressionTree);
						printResult(calculator, isSuccess, calculator.expressionTree);
						if(isSuccess){
							saveStdHistory(calculator.expression, calculator.result);
						}
						deleteTree(calculator.expressionTree);
						if(!isContinueCalculator()){
							break;
						}
						gotoxy(70,0);
					}

				}while(true);
			}else if(input == '2'){
				// kalkulator BMI
				do{
					showBMICalc();
					printCategories();
					inputBMI(data);
					gotoxy(3,17);
					if(!isContinueCalculator()){
						break;
					}
				}while(true);
				goto menu;
			}else if(input == '3'){
				// History
				system("mode 94, 30");
				system("cls");
				showStdHistory();
				showBmiHistory();
				goto menu;
			}else if(input == '4'){
				// Help
				showHelp();
				goto menu;
			}else if(input == '5'){
				// Credits
				showCredit();
				goto menu;
			}else if(input == '0'){
				exit(1);
			}
		}while(input != '0');
	
	return 0;
}