#include <stdio.h>
#include <conio.h>
#define N 5

int Q[N];
int x, Qnumber = 0, F = 0,R = 0;
char status = 'N'; 
char ch;

void insertCQ(int y) {
    if((R==F-1) || (R==N-1 && F==1) ) {  
        printf("!!!OVER FLOW!!!...\n");  
        status='O';
    }else {  
        if(R==N-1) {  
            R=1;  
        }else {  
            R++;
            if(F==0)
            F=1;  
        }  
        Qnumber++;
        printf("Youe are queue number : %d\n", Qnumber);
        Q[R]=y; 
        status = 'N';
    } 
} 

int deleteCQ() {  
    int y;  
    if (F == 0) {  
        printf("\n!!!UNDER FLOW!!!...\n"); 
        status = 'U';
        return -1;
    }else {  
        y=Q[F];
        Q[F] = 0;
        if (F==R) {  
            F=0; R=0;  
        }else {  
            if(F==N-1)
                F=1; 
                 else 
                
                F++;  
        }  
        status = 'N';
        return(y);
    }  
} 

int DataInQueue() {  
    int y=0;  
    if (F!= 0 && R!=0) {  
        if (F<=R) 
            y=R-F+1;
        else 
            y=(N-1)-F+1+R; 
    } 
        return(y);  
}  

void ShowAllQueue() {  
    int i;
    printf("N : %d\n",N-1);  
    printf("Status = %c \n",status);
    printf("Data waiting in queue = %d\n",DataInQueue());  
    printf(" F = %d / R = %d\n",F,R);
    for ( i = 1; i < N; i++ ) {  
        printf("%d:%d / ",i, Q[i]);
    }  
    printf("\n----------------------------------------------------------\n");  
}  

int main() {  
    printf("CICULAR QUEUE PROGRAM...\n");  
    printf("=======================\n");  
    ch=' ';  
    while (ch != 'E') {  
        printf("\n[1=INSERT : 2=DELETE E:Exit] : ");
        ch = getch(); 
        switch(ch){  
            case '1' : printf("\nInsert Number : ");
            scanf("%d", &x); 
                insertCQ(x); 
                ShowAllQueue();
                break;  
            case '2' : x=deleteCQ(); 
                printf("\nData from Queue = %d\n",x); 
                ShowAllQueue();  
                break;  
        }
    }
    printf("\n");
    return(0);  
}
