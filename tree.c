/**
 *========================================================
 * Program		: Cyclops Calculator
 * File			: tree.c
 * Deskripsi	: body file ADT Binary Tree
 * IDE			: Dev-C++, VSCode
 * Author		: Raka Mahardika Maulana 	(RMM)				  
 *				  Mochamad Ferdy Fauzan  	(MFF)
 *				  Muhammad Daffa Raihandika (MDR)
 *========================================================
 */
 
#include "tree.h"
#include "calculator.h"

/**
 * Modified from https://www.programmersought.com/article/95294413292/
 * Tanggal		: 21-05-2022
 * Author		: MDR
 * Deskripsi	: Modul ini bertujuan untuk menentukan operand yang akan menjadi root dan melakukan perhitungan di dalam tree.
 * 			   	  Modul ini mengembalikan nilai perhitungan ke root dan mengembalikan nilai angka jika tidak terdapat operator 
 * 			   	  dengan tipe data double
 */
double calculate(address root, boolean *isSuccess)
{
	// root adalah operator
    if(root->isOperator){
    	// Tentukan operand dan hitung
        switch(root->opr){
            case '+':{
                return calculate(root->leftChild,isSuccess) + calculate(root->rightChild,isSuccess);
                break;
            }
            case '-':{
                return calculate(root->leftChild,isSuccess) - calculate(root->rightChild,isSuccess);
                break;
            }
            case '*':{
                return calculate(root->leftChild,isSuccess) * calculate(root->rightChild,isSuccess);
                break;
            }
            case '/':{
                if(calculate(root->rightChild,isSuccess) == 0) {
                    (*isSuccess) = false;
				}
                else
                    return calculate(root->leftChild,isSuccess) / calculate(root->rightChild,isSuccess);
                break;
            }
            case '^':{
                return pow(calculate(root->leftChild,isSuccess), calculate(root->rightChild,isSuccess));
                break;
            }
            case '%':{
                return (calculate(root->leftChild,isSuccess))/100;
                break;
            }
            case 'p':{
                return (calculate(root->leftChild,isSuccess))*PI;
                break;
            }
            case 'v':{
                return sqrt(calculate(root->rightChild,isSuccess));
                break;
            }
        }
    }
    
    return root->digit;
}

/**
 * Modified from https://www.programmersought.com/article/95294413292/
 * Tanggal		: 21-05-2022
 * Author		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menemukan operator berdasarkan prioritasnya
 *				  Mengembalikan nilai posisi operator ke dalam string	
 */
int searchOperator(char str[], int start, int end)
{
	int posPlusOrSub = 0;//Position of plus and minus signs 
    int numPlusOrSub = 0;//Number of plus and minus signs 
    int posDivOrMul = 0;//Multiply and divide and percenting sign position 
    int numDivOrMul = 0;//Number of multiplication and division and percenting numbers
    int posPowOrRoot = 0; // Power and square root sign position
    int numPowOrRoot = 0; // Number of the result after powering or square rooting
 
    int in_brackets = 0; //Identifiers not in parentheses 
    
    for(int i = start; i <= end; i++)
    {
    	if(str[i] == '(')
    		in_brackets++;
    	else if(str[i] == ')')
    		in_brackets--;
    	
    	if(!in_brackets)
    	{
    		if(str[i] == '+' || str[i] == '-')
    		{
    			posPlusOrSub = i;
    			numPlusOrSub++;
			}else if(str[i] == '(' || str[i-1] == ')')
			{
				posPlusOrSub = i;
				numPlusOrSub++;
			}
			else if(str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == 'p')
			{
				posDivOrMul = i;
				numDivOrMul++;
			}else if(str[i] == '^' || str[i] == 'v')
			{
				posPowOrRoot = i;
				numPowOrRoot++;
			}
		}
	}
	
	int posOprPrior = -1;
	
	if(numPlusOrSub)
		posOprPrior = posPlusOrSub;
	else if(numDivOrMul)
		posOprPrior = posDivOrMul;
	else if(numPowOrRoot)
		posOprPrior = posPowOrRoot;
	
	return posOprPrior;
}

/**
 * Modified From https://www.programmersought.com/article/95294413292/
 * Tanggal		: 21-05-2022
 * Author		: MFF
 * Deskripsi	: Modul ini bertujuan untuk mengembalikan alamat dari tree yang berisi ekspresi matematika
 */
address buildTree(char str[], int start, int end)
{
	address root = (address)malloc(sizeof(ElmtNode));
	
	if(start > end)
		return NULL;
	
	double digit = checkExpression(str, start, end);
	
	if(digit != MAX)
	{
		root->isOperator = false;
		root->digit = digit;
		root->leftChild = NULL;
		root->rightChild = NULL;
		return root;
	}
	
	int posRoot = searchOperator(str, start, end);
	
	if(posRoot == -1)
		return buildTree(str, start + 1, end - 1);
	
	root->isOperator = true;
	root->opr = str[posRoot];
	root->leftChild = buildTree(str, start, posRoot-1);
	root->rightChild = buildTree(str, posRoot + 1, end);
	
	return root;
}

/**
 * Modified From https://www.programmersought.com/article/95294413292/
 * Tanggal		: 27-05-2022
 * Author 		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan ekspresi matematika secara postfix
 * IS 			: Ekspresi matematika belum ditampilkan secara postfix
 * FS 			: Ekspresi matematika ditampilkan dengan menggunakan transversal post-order
 */
void postOrder(address root)
{
	if(root != Nil)
	{
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		if(root->isOperator == false)
		{
			printf("%d ", (int)root->digit);
		}
		else
		{
			printf("%c ", root->opr);
		}
	}
}

/**
 * Tanggal 		: 27-05-2022
 * Author 		: MDR
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan ekspresi matematika secara prefix
 * IS 			: Ekspresi matematika belum ditampilkan secara prefix
 * FS 			: Ekspresi matematika ditampilkan dengan menggunakan transversal pre-order
 */
void preOrder(address root)
{
	if(root != Nil)
	{
		if(root->isOperator == false)
		{
			printf("%d ", (int)root->digit);
		}
		else
		{
			printf("%c ", root->opr);
		}
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}

/**
 * Tanggal 		: 27-05-2022
 * Author 		: RMM
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan ekspresi matematika secara infix
 * IS 			: Ekspresi matematika belum ditampilkan secara infix
 * FS 			: Ekspresi matematika ditampilkan dengan menggunakan transversal in-order
 */
void inOrder(address root)
{
	if(root != Nil)
	{
		inOrder(root->leftChild);
		if(root->isOperator == false)
		{
			printf("%d ", (int)root->digit);
		}
		else
		{
			printf("%c ", (root->opr));
		}
		inOrder(root->rightChild);
	}
	
}

/**
 * Tanggal 		: 21-05-2022
 * Author		: MFF
 * Deskripsi 	: Modul ini bertujuan untuk menghapus tree
 * IS 			: Tree belum dihapus
 * FS 			: Tree sudah dihapus
 */
void deleteTree(address root)
{
	if(root == NULL)
		return;
	
	deleteTree(root->leftChild);
	deleteTree(root->rightChild);
	
	free(root);
}