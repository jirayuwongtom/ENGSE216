#include <stdio.h>
#include <conio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MaxData 100 
#define MaxRow 10 
#define MaxCol 20 

int Data[MaxData];  
int Radix[MaxRow][MaxCol]; 
int N,N1;  

void ClearStackPT() {  
    int i;  
    for(i=0;i<=MaxRow;i++) 
    Radix[i][0]=NULL;
}

void PrepareRawData(int N2) {  
    int i;
    srand(time(NULL)); 
    for (i=0;i<N2;i++) 
        Data[i]=(rand() % 899)+100;
}  

void DispData(int N2) {  
    int i;  
    for(i=0;i<N2;i++) 
        printf("%3d ",Data[i]);  
    printf("\n");  
} 

void Push(int Rad, int Dat) {  
    int SP;  
    SP=Radix[Rad][0]+1; 
    Radix[Rad][0]=SP; 
    Radix[Rad][SP]=Dat; 
}  

void ReadStack() {  
    int i,j,k,SP;  
    k=0;  
    for(i=0;i<=MaxRow;i++) {  
        SP=Radix[i][0];  
        for(j=1;j<=SP;j++) {  
            Data[k]=Radix[i][j];  
            k++;  
        }  
    }
}

void RadixSort(int N2) {  
    int Digit,i,RadixNo;  
    char Txt[2];  
    for(Digit=2;Digit>=0;Digit--) {  
        printf("[Digit : %d]==>\n",3-Digit);  
        for(i=0;i<N2;i++) {  
            itoa(Data[i],Txt,10);
            RadixNo=Txt[Digit]-48;
            Push(RadixNo,Data[i]);
        }
        ReadStack();  
        DispData(N2);  
        ClearStackPT();  
    }  
}  

 int main() {  
    printf("ASCENDING RADIX SORT\n");  
    printf("=====================================================================\n");  
    N=16;  
    N1=N;
    PrepareRawData(N);  
    printf("Raw Data...\n");  
    DispData(N);  
    printf("---------------------------------------------------------------------\n");  
    printf("Processing Data...\n");  
    RadixSort(N);   
    printf("--------------------------------------------------------------Finished\n");  
    printf("Sorted Data : \n");  
    DispData(N1);
    getch();  
    return(0);  
}