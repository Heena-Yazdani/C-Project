// This code for Rock Paper Scissor using C Language
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char logic(char comp_choice,char user_choice){
    printf("computer select %c \t user select %c\n",comp_choice,user_choice);
    if(user_choice==comp_choice){
        return 'd';
    }
    else if(comp_choice=='r'){
        return(user_choice=='p')?'u':'c';
    }
      else if(comp_choice=='p'){
        return(user_choice=='r')?'c':'u';
    }
      else if(comp_choice=='s'){
        return(user_choice=='p')?'c':'u';
    }
   }

void main(){
    printf("\t\t_____________GAME FOR ROCK PAPER SCISSOR____________\t\t\n");
    srand(time(NULL));
    int comp_choice=rand()%3;
    printf("%d\n",comp_choice);
   char user_choice;
    if(comp_choice==0){
        comp_choice='r';
    }
    else if(comp_choice==1){
        comp_choice='p';
    }
    else{
        comp_choice='s';
    }
    printf(" enter the your choice :");
    scanf("%c",&user_choice);

    printf("winner is :%c",logic(comp_choice,user_choice));

}