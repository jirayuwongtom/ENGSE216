#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <math.h> 
#define MaxNode 100 
int N,data[MaxNode];
char ch;

void CreateTreeNS(int n) {  
    int i,temp;  
    for (i=1;i<=n;i++) {  
        temp=1+rand() % 99;
        data[i]=temp;  
    }  
} 

void ShowArray() {  
    int i=1;  
    while (data[i] != NULL) {  
        printf("[%i]%d ",i,data[i]); i++;  
    }  
    printf("\n==============================================================================\n");  
} 

void ShowTree() {
    int j,level,start,ends;  
    j=1;  
    level=1; 
    printf("\n");  
    while (data[j] != NULL) {  
        start=pow(2,level)/2; 
        ends=pow(2,level)-1; 
        for (j=start;j<=ends;j++) { 
            if(data[j] != NULL) {  
                switch (level) {  
                    case 1 : printf("%40d",data[j]);
                            break;  
                    case 2 : if (j==2)  
                                printf("%20d",data[j]);  
                            else 
                                printf("%40d",data[j]);   
                            break;   
                    case 3 : if(j==4)  
                                printf("%10d",data[j]);   
                            else  
                                printf("%20d",data[j]); 
                            break;   
                    case 4 : if(j==8)  
                                printf("%5d",data[j]);   
                            else 
                                printf("%10d",data[j]);  
                            break;   
                    case 5 : if(j==16) 
                                printf("%d",data[j]);  
                            else 
                                printf("%5d",data[j]); 
                            break;  
                }  
            }  
        } 
        printf("\n\n");
        level++;  
    }  
} 

void PreOrder(int i) { 
    int info,lson,rson;  
    info=data[i];
    if (info != NULL) {  
        printf(" %d",data[i]);
        lson=2*i; 
        rson=2*i+1; 
        PreOrder(lson); 
        PreOrder(rson); 
    }  
}  
  
void InOrder(int i) {  
    int info,lson,rson;  
    info=data[i];  
    if (info != NULL) {  
        lson=2*i;  
        rson=2*i+1; 
        InOrder(lson); 
        printf(" %d",data[i]); 
        InOrder(rson);
    }  
}  
  
void PostOrder(int i) {  
    int info,lson,rson;  
    info=data[i];  
    if (info != NULL) {  
        lson=2*i; 
        rson=2*i+1; 
        PostOrder(lson);  
        PostOrder(rson);  
        printf(" %d",data[i]); 
    }  
}

int main() {  
    N=31;  
    CreateTreeNS(N);
    while (ch != 'E') {  
        printf("\nTREE (NODE SEQUENCE)\n");  
        printf("==================================\n");  
        ShowArray();  
        ShowTree();  
        printf("\nMENU => P:PreOrder I:InOrder O:PostOrder E:Exit");  
        printf("\n-------------------------------------------------------------------------\n");  
        ch=getch(); 
        switch (ch) {  
        case 'P' :  ShowTree();  
                    printf("PRE ORDER TRAVERSAL : ");  
                    PreOrder(1);  
                    printf("\n");
                    break;  
        case 'I' :  ShowTree();  
                    printf("IN ORDER TRAVERSAL : ");  
                    InOrder(1);  
                    printf("\n");
                    break;  
        case 'O' :  ShowTree();  
                    printf("POST ORDER TRAVERSAL : ");  
                    PostOrder(1);  
                    printf("\n");
                    break;  
        }
    } 
return(0);  
}