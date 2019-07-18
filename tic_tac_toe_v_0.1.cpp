#include<stdio.h>
#include<dos.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>

struct myType{
    int i;
    char ch[3];
};

void run();
int check(char sym[35][3],char ch[],int count);
struct myType inputValue(char sym[35][3],int count);
void showDisplay(char sym[35][3]);
void toastWinner (char ch[]);

 int main(){
// 	system("color 81");

    char reStart;
    again:
	run();
	
	scanf("%s",&reStart);
	if(reStart == '1')
        {
            system("cls");//clean consol
            goto again;
        }
    else
        exit(0);
}

void run(){
    int count = 0;
    int i =0;
 
   struct myType info;
   //char symbol[35][3] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22",
   //"23","24","25","26","27","28","29","30","31","32","33","34","35"};
   
    char symbol[35][3];
    for (i = 0;i<35;i++){
    sprintf (symbol [i],"%i",i+1);
	}
 
  	showDisplay(symbol);
    again:
    info = inputValue(symbol,count);
    strcpy(symbol[info.i], info.ch);///symbol[info.i] = info.ch;
    system("cls");
    showDisplay(symbol);

    if(check(symbol,info.ch,count)==1);
    else{
        count++;
        goto again;
    }

}
int check(char sym[35][3],char ch[],int count){
    int i;
    
    for(i = 0;i<=35; i+=5)//horizontal
      if(strcmp(sym[i],ch)==0 && strcmp(sym[i+1],ch)==0 && strcmp(sym[i+2],ch)==0 && strcmp(sym[i+3],ch)==0 ||
        strcmp(sym[i+1],ch)==0 && strcmp(sym[i+2],ch)==0 && strcmp(sym[i+3],ch)==0 && strcmp(sym[i+4],ch)==0){
 		  	                    toastWinner(ch);
				                return 1;
        }
  
    for(i = 0;i<5; i++)//vertical   
        if(strcmp(sym[i],ch)==0 && strcmp(sym[i+5],ch)==0 && strcmp(sym[i+10],ch)==0 && strcmp(sym[i+15],ch)==0 ||
	    strcmp(sym[i+5],ch)==0 && strcmp(sym[i+10],ch)==0 && strcmp(sym[i+15],ch)==0 && strcmp(sym[i+20],ch)==0 ||
		strcmp(sym[i+10],ch)==0 && strcmp(sym[i+15],ch)==0 && strcmp(sym[i+20],ch)==0 && strcmp(sym[i+25],ch)==0||
		strcmp(sym[i+15],ch)==0 && strcmp(sym[i+20],ch)==0 && strcmp(sym[i+25],ch)==0 && strcmp(sym[i+30],ch)==0){
            			       toastWinner(ch);
			                   return 1;
        }
        //diagonal Left_top -1;
        if(strcmp(sym[5],ch)==0 && strcmp(sym[11],ch)==0&&strcmp(sym[17],ch)==0&&strcmp(sym[23],ch)==0||
	              strcmp(sym[11],ch)==0&&strcmp(sym[17],ch)==0&&strcmp(sym[23],ch)==0&&strcmp(sym[29],ch)==0){
                               toastWinner(ch);
                               return 1;
        }//diagonal L_top main ind'0';
         else if(strcmp(sym[0],ch)==0 && strcmp(sym[6],ch)==0&&strcmp(sym[12],ch)==0&&strcmp(sym[18],ch)==0||
	              strcmp(sym[6],ch)==0&&strcmp(sym[12],ch)==0&&strcmp(sym[18],ch)==0&&strcmp(sym[24],ch)==0){
                                toastWinner(ch);
                                return 1;
        }//diagonal L_top 1;
         else if(strcmp(sym[1],ch)==0 && strcmp(sym[7],ch)==0&&strcmp(sym[13],ch)==0&&strcmp(sym[19],ch)==0){
                                toastWinner(ch);
                                return 1;
        }//diagonal Right_top 4;        
         else if(strcmp(sym[3],ch)==0&&strcmp(sym[7],ch)==0&&strcmp(sym[11],ch)==0&&strcmp(sym[15],ch)==0){
                                toastWinner(ch);
                                return 1;
        }//diagonal R_top main 5;
         else if(strcmp(sym[4],ch)==0 && strcmp(sym[8],ch)==0 && strcmp(sym[12],ch)==0 && strcmp(sym[16],ch)==0 ||
		          strcmp(sym[8],ch)==0 && strcmp(sym[12],ch)==0 && strcmp(sym[16],ch)==0 && strcmp(sym[20],ch)==0){
                                toastWinner(ch);
                                return 1;
        }
	    //diagonal R_top 5;
         else if(strcmp(sym[9],ch)==0 && strcmp(sym[13],ch)==0&&strcmp(sym[17],ch)==0&&strcmp(sym[21],ch)==0||
		          strcmp(sym[13],ch)==0&&strcmp(sym[17],ch)==0&&strcmp(sym[21],ch)==0&&strcmp (sym[25],ch)==0){
                                toastWinner(ch);
                                return 1;
        }
		//diagonal Left_bottom main  ind'30';
         else if(strcmp(sym[14],ch)==0&&strcmp(sym[18],ch)==0&&strcmp(sym[22],ch)==0&&strcmp(sym[26],ch)==0||
		           strcmp(sym[18],ch)==0&&strcmp(sym[22],ch)==0&&strcmp(sym[26],ch)==0&&strcmp(sym[30],ch)==0){
                                toastWinner(ch);
                                return 1;
        }
         //diagonal Left_battom ind 31;
         else if(strcmp(sym[19],ch)==0 && strcmp(sym[23],ch)==0&&strcmp(sym[27],ch)==0&&strcmp(sym[31],ch)==0){
                                toastWinner(ch);
                                return 1;
        }
		//diAGONAL Right_battom ind 33;
		 else if(strcmp(sym[15],ch)==0 && strcmp(sym[21],ch)==0&&strcmp(sym[27],ch)==0&&strcmp(sym[33],ch)==0){
                                toastWinner(ch);
                                return 1;
        }
        //diAGONAL Right_battom ind 34;
         else if(strcmp(sym[10],ch)==0&& strcmp(sym[16],ch)==0&&strcmp(sym[22],ch)==0&&strcmp(sym[28],ch)==0||
		           strcmp(sym[16],ch)==0&&strcmp(sym[22],ch)==0&&strcmp(sym[28],ch)==0&&strcmp(sym[34],ch)==0){
                                toastWinner(ch);
                                return 1;
        }
      
    else if(count==34){
        printf("the Game is DRAW");
        return 1;
    }else return 0;
}
struct myType inputValue(char sym[35][3],int count){
    char value[3];
    int i;
    struct myType info;
    inputAgain:
         	
    if(count%2 == 0){
        printf("\nEnter Your Choice X:");
    }else{
        printf("\nEnter Your Choice O:");
    }
     scanf("%s",&value);
		    
    for(i=0;i<35;i++){///strlen()
        if(strcmp(value, sym[i])==0){ 
            info.i = i;//
            if(count%2 == 0){
            strcpy(info.ch, "X"); 
            }
			else
            strcpy(info.ch, "0");
			break;
            }else{
            info.i = -1;
            strcpy(info.ch, " ");
        	}
    }
    if(info.i == -1){
        printf("\nInput is not Valid");
        goto inputAgain;
    }
    return info;
}

void showDisplay(char symb[35][3]){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, ABM_ACTIVATE);
	printf("\n\t\t\t\tTic  tac  toe 7/5");
	SetConsoleTextAttribute(hConsole, ABE_BOTTOM);
	printf("\n\nFirst player  Symbol: X");
	printf("\nSecond players  Symbol: O\n");

	for(int i=0;i<35;i++){
	if(i==0|i==5||i==10||i==15||i==20||i==25||i==30){
	printf("\n\t\t\t|------|------|------|------|------|");
	printf("\n\t\t\t|");
	}
	if(strlen(symb[i])==2){
	printf("  %s  |",symb[i]);	
	}	
	else printf("  %s   |",symb[i]);	
	}
	printf("\n\t\t\t|------|------|------|------|------|\n");
	printf("\n\t\t\t         ");
	}
	
void toastWinner (char ch[]){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, ABM_ACTIVATE);
    printf("the Winner is : %s",ch);
    SetConsoleTextAttribute(hConsole, ABE_BOTTOM);
    printf("\n\nIf You Want To Play Again Press 1: \nElse Any:");
	}
	
//	printf("\n\t\t\t       |       |       |       |       ");
//	printf("\n\t\t\t-------|-------|-------|-------|-------");
//	printf("\n\t\t\t   %s   |   %s   |   %s   |   %s   |  %s  ",symb[0],symb[1],symb[2],symb[3],symb[4]);
//	printf("\n\t\t\t-------|-------|-------|-------|-------");
//	printf("\n\t\t\t   %s   |   %s   |   %s   |   %s   |  %s  ",symb[5],symb[6],symb[7],symb[8],symb[9]);
//	printf("\n\t\t\t-------|-------|-------|-------|-------");
//	printf("\n\t\t\t   %s   |   %s   |   %s   |   %s   |  %s  ",symb[10],symb[11],symb[12],symb[13],symb[14]);
//	printf("\n\t\t\t-------|-------|-------|-------|-------");
//	printf("\n\t\t\t   %s  |   %s  |   %s  |   %s  |  %s  ",symb[15],symb[16],symb[17],symb[18],symb[19]);
//	printf("\n\t\t\t-------|-------|-------|-------|-------");
//	printf("\n\t\t\t   %s  |   %s  |   %s  |   %s  |  %s  ",symb[20],symb[21],symb[22],symb[23],symb[24]);
//	printf("\n\t\t\t-------|-------|-------|-------|-------");
//	printf("\n\t\t\t   %s  |   %s  |   %s  |   %s  |  %s  ",symb[25],symb[26],symb[27],symb[28],symb[29]);
//	printf("\n\t\t\t-------|-------|-------|-------|-------");
//	printf("\n\t\t\t   %s  |   %s  |   %s  |   %s  |  %s   ",symb[30],symb[31],symb[32],symb[33],symb[34]);
//	printf("\n\t\t\t-------|-------|-------|-------|-------");
//	printf("\n\t\t\t        ");


//                                  index
                 
/*	printf("\n\t\t\    0   |    1  |    2  |    3  |   4  
	printf("\n\t\t\ -------|-------|-------|-------|-------
	printf("\n\t\t\    5   |    6  |    7  |    8  |   9  
	printf("\n\t\t\ -------|-------|-------|-------|-------
	printf("\n\t\t\    10  |   11  |   12  |   13  |  14  
	printf("\n\t\t\ -------|-------|-------|-------|-------
	printf("\n\t\t\    15  |   16  |   17  |   18  |  19  
	printf("\n\t\t\ -------|-------|-------|-------|-------
	printf("\n\t\t\    20  |   21  |   22  |   23  |  24 
	printf("\n\t\t\ -------|-------|-------|-------|-------
	printf("\n\t\t\    25  |   26  |   27  |   28  |  29  
	printf("\n\t\t\ -------|-------|-------|-------|-------
	printf("\n\t\t\    30  |   31  |   32  |   33  |  34   
	printf("\n\t\t\ -------|-------|-------|-------|-------
}*/
	


