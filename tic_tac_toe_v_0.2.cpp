#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <math.h>
#include <string.h>


int row = 0;        //size row in map
int column = 0;    //size column in map
int sGm=0;        //size game map
int vComb = 0;   //lengthVictoryKombination

struct myType{
    int i;
    char ch[3];
};
void chooseSizeMapGame();
void chooseLenghtViCombination();
void run();
int check(char sym[][3],char ch[],int inputIndex);
struct myType inputValue(char sym[][3],int count);
void showDisplay(char sym[][3]);
int frameMap(int flag);

int checkVertikal (char sym[][3],char ch[],int min,int max, int step);
int checkHorizontal (char sym[][3],char ch[],int min,int max, int step);
int checkDiag_L (char sym[][3],char ch[],int min,int max, int step);
int checkDiag_R (char sym[][3],char ch[],int min,int max, int step);

void toastWinner (char ch[]);

 int main(){
    char reStart;
    again:
	run();
	scanf("%s",&reStart);
	fflush(stdin);
	if(reStart == '1'){
            system("cls");
            goto again;
    }else if(reStart == '2'){
		sGm=0;
		row=0;
		column=0;
		vComb=0;
		system("cls");
        goto again;
	}
		else
        exit(0);
}

void run(){
    int count = 0;
    int i =0;
 
   struct myType info;
   while (sGm==0) {
   chooseSizeMapGame();
   }
   printf("%i",sGm);
   
    char symbol[sGm][3];
    for (i = 0;i<sGm;i++){
      sprintf (symbol [i],"%i",i+1);

	}
 
  	showDisplay(symbol);
    again:
    info = inputValue(symbol,count);
    strcpy(symbol[info.i], info.ch);
    system("cls");
    showDisplay(symbol);
    if(count+1>(vComb-1)*2){      // start check  
	printf("%i count",count); 
	    if(check(symbol,info.ch,info.i)==0){
           if(count==sGm-1){
              printf("the Game is DRAW");
              printf("\n\n If You Want To Play Again Press 1: \n Or Want to Change the Size of the Map Press 2:\n Else Any:");
              
           } else{
              count++;
              goto again;
           }
       }
    }else{
        count++;
        goto again;
    }

}
  int check(char sym[][3],char ch[],int inputIndex){
        int winValue =vComb-1;
    if(checkVertikal(sym, ch, inputIndex -column*winValue,inputIndex +column*winValue, column)==1)
    return 1;
    else if(checkHorizontal(sym, ch, inputIndex-winValue,inputIndex +winValue, 1)==1)
    return 1;
   	else if (checkDiag_L(sym, ch, inputIndex+(-column-1)*winValue,inputIndex +(column+1)*winValue, column+1)==1)
    return 1;
	else if (checkDiag_R(sym, ch, inputIndex+ (-column+1)*winValue,inputIndex +(column-1)*winValue, column-1)==1)
	return 1;
    else return 0;
    

}

 struct myType inputValue(char sym[][3],int count){
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
     fflush(stdin);
		    
    for(i=0;i<sGm;i++){
        if(strcmp(value, sym[i])==0){ 
            info.i = i;
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

void showDisplay(char symb[][3]){
	
	printf("\n\t\t\t\tTic  tac  toe   %i / %i ",row,column);
	printf("\n\t\t\t      Leng victory combination %i ",vComb);
	printf("\n\nFirst player  Symbol: X");
	printf("\nSecond player  Symbol: O\n");

	for(int i=0;i<sGm;i++){
     	if(i%column==0){
         frameMap(1);	
	     }
	     if(strlen(symb[i])==2){
	     printf("  %s  |",symb[i]);	
	     }	
	     else printf("  %s   |",symb[i]);	
	}
    	frameMap(2);
	
	}
	
	int frameMap(int flag){
		switch ( column ) {
case 3:
	if(flag==1){
      printf("\n\t\t\t|------|------|------|");
  	  printf("\n\t\t\t|");
    }else{
      printf("\n\t\t\t|------|------|------|\n");
      printf("\n\t\t\t         ");
    }
  break;
case 4:
	if(flag==1){
    printf("\n\t\t\t|------|------|------|------|");
	printf("\n\t\t\t|");
	}else{
	printf("\n\t\t\t|------|------|------|------|\n");
	printf("\n\t\t\t         ");
	}
  break;
  case 5:
  	if(flag==1){
    printf("\n\t\t\t|------|------|------|------|------|");
	printf("\n\t\t\t|");
	}else{
	printf("\n\t\t\t|------|------|------|------|------|\n");
	printf("\n\t\t\t         ");
	}
  break;
  case 6:
  	if(flag==1){
    printf("\n\t\t\t|------|------|------|------|------|------|");
	printf("\n\t\t\t|");
	}else{
		 printf("\n\t\t\t|------|------|------|------|------|------|\n");
	printf("\n\t\t\t         ");
	}
  break;
  case 7:
  	if(flag==1){
         printf("\n\t\t\t|------|------|------|------|------|------|------|");
	     printf("\n\t\t\t|");
	}else{
		 printf("\n\t\t\t|------|------|------|------|------|------|------|\n");
	     printf("\n\t\t\t         ");
	}
  break;
  case 8:
  	if(flag==1){
         printf("\n\t|------|------|------|------|------|------|------|------|");
	     printf("\n\t|");
	}else{
	     printf("\n\t|------|------|------|------|------|------|------|------|\n");
	     printf("\n\t         ");
	}
  break;
  case 9:
  	if(flag==1){
         printf("\n\t|------|------|------|------|------|------|------|------|------|");
	     printf("\n\t|");
	}else{
	     printf("\n\t|------|------|------|------|------|------|------|------|------|\n");
	     printf("\n\t         ");
	}
  break;
  case 10:
  	if(flag==1){
         printf("\n |------|------|------|------|------|------|------|------|------|------|");
	     printf("\n |");
	}else{
		 printf("\n |------|------|------|------|------|------|------|------|------|------|\n");
         printf("\n          ");
	}
  break;
default:
  /* Code */
  printf("problem Oo");
  break;
}
	}
	
	
void toastWinner (char ch[]){
    printf("The Winner is : %s",ch);
    printf("\n\n If You Want To Play Again Press 1: \n Or Want to Change the Size of the Map Press 2:\n Else Any:");
    
    //nElse Any:
	}
	
 int checkVertikal (char sym[][3],char ch[],int a,int b, int c){
	int i=0,l=0;
    for(i=a;i<=b;i+=c){ 
	   if(i>=0&&i<sGm){
	                         
 		  if(strcmp(sym[i],ch)==0){
			 l+=1;
			 if(l==vComb){
                toastWinner(ch);
                return 1;
             }
 		  } else{
			l=0;
		  }
	   }	
    }			    
	return 0;
}

 int checkHorizontal (char sym[][3],char ch[],int min,int max, int step){
	int i=0,l=0;
	
    for(i=min;i<=max;i+=step){
    
	 	       if(i>=0&&i<sGm){
           	   		                         
 		      if(strcmp(sym[i],ch)==0){
			       l+=1;
			       if(l==vComb){
                      toastWinner(ch);
                      return 1;
                    }
 		        }else{
			          l=0;
		        }
		      
		        if((i+1)%column == 0){    //check if it's last position in row;
	              l=0;
	            }
	       }	
    }			    
	return 0;
}

 int checkDiag_L (char sym[][3],char ch[],int min,int max, int step){//-18 +18 step 6 =else colums 5
	int i=0,l=0;
	
    for(i=min;i<=max;i+=step){
  	 	   if(i>=0&&i<sGm){
	   	           		   	                        
 		      if(strcmp(sym[i],ch)==0){
			       l+=1;
			       if(l==vComb){
                      toastWinner(ch);
                      return 1;
                    }
 		        }else{
			        l=0;
		        }
		           if(i!=0) 
                if((i+1)%column == 0){  //check on last position from row;
		          l=0;
	            } 
	   }	
    }			    
	return 0;
}

int checkDiag_R (char sym[][3],char ch[],int min,int max, int step){//-12 12 step 4
	int i=0,l=0;

    for(i=min;i<=max;i+=step){
   	 	   if(i>=0&&i<sGm){
           		   		                        
 		      if(strcmp(sym[i],ch)==0){
			       l+=1;
			       if(l==vComb){
                      toastWinner(ch);
                      return 1;
                    }
 		            }else{
			          l=0;
		            }
   				if((i)%column == 0){    //check on last position from row;
	              l=0;
	            }
	   }	
    }			    
	return 0;
}

void chooseSizeMapGame(){
	if(row<3||row>10){
	printf("Please enter size of row 3-10:");
	scanf("%i",&row);
	fflush(stdin);
	}
	if(column<3||column>10){
	printf("Please enter column count 3-10:");
	scanf("%i",&column);
		fflush(stdin);
    }
  
    if(row>2&&row<=10&&column>2&&column<=10){
     while (vComb<3||vComb>=10) {
     chooseLenghtViCombination();
   }
	sGm=row*column;
	system("cls");
	}else{
		sGm=0;
		system("cls");
		 
	}
}
 void chooseLenghtViCombination(){
 	printf("Please enter the lenght of victory combination >=3 && <=10:");
	scanf("%i",&vComb);
	fflush(stdin);
 	 	
 }



