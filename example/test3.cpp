#include <stdio.h> //use printf() 
#include <conio.h> //use getch() 
#define MaxStack 6 //Set Max Stack  
int stack[MaxStack]; //Declare Max Stack 0..5 
int x; //Temperature variable 
int SP = 0; //Initial SP=0 
char status = 'N'; //Initial Status = NORMAL 
char ch; //KBD Read variable 
 
void push(int x) //PUSH Function  
{ 
    if(SP == MaxStack-1){ //Check Stack FULL? 
        printf("!!!OVER FLOW!!!...\n");  
        status='O'; //set status = OVER FLOW 
    }  
    else{  
        SP=SP+1; //Increase SP 
        stack[SP]=x; //Put data into Stack 
    }  
}  
 
int pop() //POP Function 
{  
    int x;  
    if (SP != 0) //Check Stack NOT EMPTY? 
    {  
        x=stack[SP]; //Get data from Stack 
         SP--; //Decrease SP  
        return(x); //Return data 
    }  
    else 
    {  
        printf("\n!!!UNDER FLOW!!!...\n");  
        status = 'U'; //set STATUS = "UNDER FLOW" 
    }  
}  
 
void ShowAllStack() //Display Function 
 
{  
    int i; //Counter variable 
    printf(" N : %d\n ",MaxStack-1); //Display N 
    printf("Status : %c\n ",status); //Display STATUS 
    printf("SP : %d\n",SP); //Display SP 
    for ( i = 1; i < MaxStack; i++ )  
    {  
        printf("%d:%d ",i, stack[i]); //Display all of data in Stack 
    }  
    printf("\n----------------------------------------------------------\n");  
}  
 
int main() 
{  
    printf("STACK PROGRAM...\n");  
    printf("===================\n");  
    while (status == 'N')  
    {  
        printf("[1=PUSH : 2=POP] : "); //Show MENU 
        ch = getch(); //Wait and read KBD with out ENTER Press 
        switch(ch) //Check ch 
    {  
    case '1' : printf("\nEnter Number : ");  
        scanf("%d", &x); //Read data from KBD 
        push(x); //Call PUSH Function 
        ShowAllStack(); //Display all data in Stack 
        break;  
    case '2' : x=pop(); //POP data 
        printf("\nData : %d\n",x); //Display it 
        ShowAllStack(); //Display all data in Stack 
        break;  
    } //End SWITCH CASE 
} //End WHILE Loop 
printf("\n"); //line feed 
return(0);  
}//End MAIN Fn. 