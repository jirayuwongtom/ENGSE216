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
     
void BubbleSort(int N) {  
    int i,j,temp;  
    for(i=1;i<=N-1;i++) {  
        if(Data[i]>Data[i+1]) {  
            j=i+1;
            while(Data[j]<Data[j-1]) {  
                temp=Data[j-1];
                Data[j-1]=Data[j];  
                Data[j]=temp;  
                j--; 
            }
        } 
    } 
} 
 
bool BinarySearch(int Key1) {  
    int L,R,Mid;  
    L=1;  
    R=N;  
    Times=0;
    while(L<=R) {  
        Mid=(L+R)/2; 
        Times++; 
        printf("L : %2d ",L);  
        printf("R : %2d ",R);  
        printf("Mid : %2d ",Mid);  
        printf("Searching Time : %d\n",Times);  
        if(Key1==Data[Mid]) 
            return(true);
        else { 
            if(Key1<Data[Mid]) 
                R=Mid-1;  
            else 
                L=Mid+1; 
        } 
    }
    return(false);
} 
 
int main() {  
    printf("BINARY SEARCH\n");  
    printf("===================================================\n");  
    N=32;  
    PrepareRawKey(N);  
    printf("Raw key :\n");  
    DispKey(N);
    BubbleSort(N);  
    printf("----------------------------------------------------------------\n");  
    while(key!=-999) {  
        printf("Sorted Key :\n");  
        DispKey(N); 
        printf("\nEnter Key for Search(-999 for EXIT) = ");  
        scanf("%d",&key);
        if(key!=-999) {  
            result=BinarySearch(key);
            if(result) 
                printf("Result...FOUND\n");  
            else {  
                Beep(600,600);  
                printf("Result...NOT FOUND!!\n"); 
            } 
            printf("Searching Time : %d\n",Times); //
        printf("---------------------------------------------------Searching Finished\n");  
        } 
    }  
    return(0);  
}