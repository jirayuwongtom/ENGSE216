#include <stdio.h>
#include <conio.h>
#define MaxStack 6
int stack[MaxStack]; 
int x;
int SP = 0;
char status = 'N';
char ch; 
 
void push(int x) { 
    if(SP == MaxStack-1){ 
        printf("!!!OVER FLOW!!!...\n");  
        status ='O'; 
    }else {  
        SP=SP+1;
        stack[SP]=x; 
    }  
}  
 
int pop() {  
    int x;  
    if (SP != 0) {  
        x=stack[SP]; 
        stack[SP] = 0;
        SP--;
        return(x);
    }else {  
        printf("\n!!!UNDER FLOW!!!...\n");  
        status = 'U';
        return(0);
    }  
}  
 
void ShowAllStack() {  
    int i;
    printf(" N : %d\n ",MaxStack-1);
    printf("Status : %c\n ",status);
    printf("SP : %d\n",SP);
    for ( i = 1; i < MaxStack; i++ ) {  
        printf("%d:%d ",i, stack[i]);
    }  
    printf("\n----------------------------------------------------------\n");  
}  
 
int main() {  
    printf("STACK PROGRAM...\n");  
    printf("===================\n");  
    while (status == 'N') {  
        printf("[1=PUSH : 2=POP] : ");
        ch = getch();
        switch(ch)
    {  
    case '1' : printf("\nEnter Number : ");  
        scanf("%d", &x);
        push(x);
        ShowAllStack();
        break;  
    case '2' : x=pop();
        printf("\nData : %d\n",x);
        ShowAllStack();
        break;  
    } 
} 
printf("\n");
return(0);  
}