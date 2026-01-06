#include <stdio.h>
#include <conio.h> 
#include <stdlib.h> 
#define l 1  
#define u 5
#define l1 1  
#define u1 3  
#define l2 1  
#define u2 4  
#define l3 1  
#define u3 5  
int *BA1, *BA2, *BA3, *p;  
int i,j,k;

//---------------------------------------
// Array 1D
void Create1DArray() {
    int element,c,total_mem;  
    element=(u-l+1);  
    c=sizeof(*BA1);  
    total_mem=element*c;  
    BA1=(int*)malloc(total_mem);  
}  
void A1(int i,int x) {
    p=BA1+(i-l);  
    *p=x;  
} 
int ReadA1(int i) {  
    p=BA1+(i-l);  
    return(*p);
}

//---------------------------------------
//Array 2D
void Create2DArray() {  
    int element,c,total_mem;  
    element=(u1-l1+1)*(u2-l2+1);  
    c=sizeof(*BA2);  
    total_mem=element*c;  
    BA2=(int*)malloc(total_mem);  
}  
void A2(int i,int j,int x) {  
    p=BA2+((i-l1)*(u2-l2+1)+(j-l2));  
    *p=x;  
}  
int ReadA2(int i,int j) {  
    p=BA2+(i-l1)*(u2-l2+1)+(j-l2);  
    return(*p);  
}  

//---------------------------------------
//Array 3D Plane–Row–Column
void Create3DArray() {  
    int element,c,total_mem;  
    element=(u1-l1+1)*(u2-l2+1)*(u3-l3+1);  
    c=sizeof(*BA3);  
    total_mem=element*c;  
    BA3=(int*)malloc(total_mem);  
}  
void A3(int i,int j,int k,int x) {  
    p=BA3+((i-l1)*(u2-l2+1)*(u3-l3+1)+(j-l2)*(u3-l3+1)+(k-l3));  
    *p=x;  
}  
int ReadA3(int i,int j,int k){  
    p=BA3+(i-l1)*(u2-l2+1)*(u3-l3+1)+(j-l2)*(u3-l3+1)+(k-l3); ;  
    return(*p);  
} 

//=======================================
// Array 3D (Method: Column → Plane → Row)
void A3_CPR(int i, int j, int k, int x) {
    int planes = (u1 - l1 + 1);  // i
    int rows   = (u2 - l2 + 1);  // j

    p = BA3 +
        ( (k - l3) * (planes * rows) +
          (i - l1) * rows +
          (j - l2) );

    *p = x;
}

int ReadA3_CPR(int i, int j, int k) {
    int planes = (u1 - l1 + 1);
    int rows   = (u2 - l2 + 1);

    p = BA3 +
        ( (k - l3) * (planes * rows) +
          (i - l1) * rows +
          (j - l2) );

    return *p;
}

int main() {  
    printf("1-3 DIMENSION ARRAY FUNCTION...\n");  
    printf("=================================\n");  
    Create1DArray();  
    Create2DArray();  
    Create3DArray(); 
    // 1D Array 
    i=2;  
    A1(i,9); 
    printf("\nA1(%d) = %d ",i,ReadA1(i)); 
    // 2D Array 
    i=2; j=3;  
    A2(i,j,99);  
    printf("\nA2(%d,%d) = %d ",i,j,ReadA2(i,j));
    // 3D Array Plane–Row–Column 
    i=3; j=4;k=5;  
    A3(i,j,k,999);  
    printf("\nA3(%d,%d,%d) = %d ",i,j,k,ReadA3(i,j,k));  
    // 3D Array Column-Plane-Row
    i = 2; j = 3; k = 4;
    A3_CPR(i, j, k, 555);
    printf("\nA3_CPR(%d,%d,%d) = %d ", i, j, k, ReadA3_CPR(i,j,k));

    getch(); 
    free(BA1);
    free(BA2);  
    free(BA3);  
    return(0);  
}