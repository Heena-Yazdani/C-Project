#include<stdio.h>
void fbchoice(){
    for(int i=0;i<=100;i++){
        if(i%3==0){
            printf("FIZZ \n");
        }
    else if(i%5==0){
        printf(" BIZZ \n");
    }
    else if(i%3==0&&i%5==0){
        printf("FIZZ & BUZZ \n");
    }
    else{
        printf("%d\n",i);
    }
    }
}
void main(){
fbchoice();
}