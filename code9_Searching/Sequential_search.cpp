#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <time.h> 
#include <windows.h> 
#define MaxData 100 

int Data[MaxData];  
int N,key,Times;  
bool result; 

bool Duplicate(int i,int Data1) {  
    int j;  
    for(j=1;j<=i;j++) { 
        if(Data1==Data[j]) 
            return(true);  
    } 
    return(false);  
}

void PrepareRawKey(int N) {  
    int i,j,temp;  
    srand(time(NULL));  
    for (i=1;i<=N;i++) {  
        temp=(rand() % 89)+10;  
        while(Duplicate(i-1,temp)) 
        temp=(rand() % 89)+10;
        Data[i]=temp;
    }  
}

void DispKey(int N) {  
    int i;  
    for(i=1;i<=N;i++) 
        printf("(%2d)",i);
    printf("\n");  
    for(i=1;i<=N;i++) 
        printf(" %2d ",Data[i]);
    printf("\n");
}  

bool SequentialSearch(int Key1) {  
    int i;  
    Times=0; 
    i=1;  
    while(i<=N) {  
        Times++;  
        if(Key1==Data[i]) 
        return(true);  
        i++;  
    }
    return(false);  
}

int main() {  
    printf("SEQUENTIAL SEARCH\n");  
    printf("===================================================\n");  
    N=16;  
    PrepareRawKey(N);  
    printf("Raw key :\n");  
    DispKey(N);
    printf("----------------------------------------------------------------\n");  
    while(key!=-999) {  
        printf("\nEnter Key for Search(-999 for EXIT) = ");  
        scanf("%d",&key); 
        if(key!=-999) {  
            result=SequentialSearch(key); 
            if(result) 
                printf("Result...FOUND\n"); 
            else {  
                Beep(600,600);  
                printf("Result...NOT FOUND!!\n"); //if NOT found  
            }  
            printf("Searching Time : %d\n",Times);  
            printf("---------------------------------------------------Searching Finished\n");  
        }
    }
    return(0);  
}
