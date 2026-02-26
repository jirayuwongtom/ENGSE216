#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MaxData 100
#define MaxRow 10
#define MaxCol 20

int Data[MaxData];
int Data2[MaxData]; // สำหรับ Heap Sort
int Radix[MaxRow][MaxCol]; // สำหรับ Radix Sort
int N;

// =========================================================================
// ฟังก์ชันส่วนกลางที่ใช้งานร่วมกัน
// =========================================================================

void PrepareRawData(int n, bool isRadix) {
    srand(time(NULL));
    if (isRadix) {
        // Radix Sort ใช้ index 0 ถึง n-1 และเป็นเลข 3 หลัก
        for (int i = 0; i < n; i++)
            Data[i] = (rand() % 899) + 100;
    } else {
        // อัลกอริทึมอื่นๆ ใช้ index 1 ถึง n และเป็นเลข 1-99
        for (int i = 1; i <= n; i++)
            Data[i] = 1 + rand() % 99;
    }
}

void DispData(int arr[], int n, bool isRadix) {
    if (isRadix) {
        for(int i = 0; i < n; i++) 
            printf("%3d ", arr[i]);
    } else {
        for(int i = 1; i <= n; i++) 
            printf("%2d   ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// =========================================================================
// 1. Insertion Sort
// =========================================================================
void InsertionSort(int n) {
    int i, j, temp;
    printf("---------------------------------------------------------------------\n");
    printf(" i ");
    for(i = 1; i <= n; i++) printf(" (%2d)", i);
    printf("\n---------------------------------------------------------------------\n");
    printf("%2d.  ", 0);
    DispData(Data, n, false);
    for (i = 1; i < n; i++) {
        if(Data[i+1] < Data[i]) {
            temp = Data[i+1];
            Data[i+1] = 0;
            j = i;
            while(temp < Data[j]) {
                Data[j+1] = Data[j];
                Data[j] = 0;
                printf("%2d.  ", i+1);
                DispData(Data, n, false);
                j = j - 1;
            }
            Data[j+1] = temp;
            printf("%2d.  ", i+1);
            DispData(Data, n, false);
        }
    }
}

// =========================================================================
// 2. Bubble Sort
// =========================================================================
void BubbleSort(int n) {
    int i, j;
    printf("----------------------------------------------------------------\n");
    printf(" i ");
    for(i = 1; i <= n; i++) {
        printf(" (%2d)", i);
    }
    printf("\n----------------------------------------------------------------\n");
    for(i = 1; i <= n-1; i++) {
        if(Data[i] > Data[i+1]) {
            printf("%2d.  ", i+1);
            DispData(Data, n, false);
            j = i + 1;
            while(Data[j] < Data[j-1]) {
                swap(Data, j-1, j);
                j--;
                printf("%2d.  ", i+1);
                DispData(Data, n, false);
            }
        }
    }
}

// =========================================================================
// 3. Quick Sort
// =========================================================================
void QuickSort(int f, int r) {
    int f1 = f, r1 = r;
    bool direction = true;
    while(f != r) {
        if(Data[f] > Data[r]) {
            printf("%2d %2d : ", f, r);
            DispData(Data, N, false);
            swap(Data, f, r);
            printf("%2d %2d : ", f, r);
            DispData(Data, N, false);
            direction = !direction;
        }
        if (direction) r--;
        else f++;
    }
    printf("k1=[%2d]--------------------------------------------------------\n", Data[f]);
    if((f > f1) && (f - 1 != f1)) QuickSort(f1, f - 1);
    if((r < r1) && (r + 1 != r1)) QuickSort(r + 1, r1);
}

// =========================================================================
// 4. Heap Sort
// =========================================================================
void HeapDispData(int arr[], int out) {
    for(int i = 1; i <= N; i++) {
        if(i < out) printf("%2d   ", arr[i]);
        else printf("[%2d] ", arr[i]);
    }
    printf("\n");
}
int Maximum(int a, int b) {
    return (a > b) ? a : b;
}
void AdjustTree(int LastNode) {
    int i = 1, Max, lson, rson, son;
    bool result = false;
    while(!result) {
        lson = (2 * i);
        rson = (2 * i) + 1;
        son = 0;
        if(lson == LastNode) {
            son = 1;
            if(Data2[i] < Data2[lson]) {
                swap(Data2, i, lson);
                HeapDispData(Data2, LastNode + 1);
            }
            result = true;
        }
        if(rson <= LastNode) {
            son = 2;
            Max = Maximum(Data2[lson], Data2[rson]);
            if(Data2[i] < Max) {
                if(Max == Data2[lson]) {
                    swap(Data2, i, lson);
                    HeapDispData(Data2, LastNode + 1);
                    if(rson == LastNode) result = true;
                    else i = lson;
                } else {
                    swap(Data2, i, rson);
                    HeapDispData(Data2, LastNode + 1);
                    if(rson == LastNode) result = true;
                    else i = rson;
                }
            } else result = true;
        }
        if(son == 0) result = true;
    }
    printf("---------------------------------------------------Adjust Tree Finished at N=%d \n", LastNode);
}
void CreateHeapTree() {
    int i, j, k, father;
    bool result;
    Data2[1] = Data[1];
    HeapDispData(Data2, N + 1);
    for(i = 2; i <= N; i++) {
        Data2[i] = Data[i];
        HeapDispData(Data2, N + 1);
        result = true;
        j = i;
        while(result) {
            father = j / 2;
            if((Data2[j] > Data2[father]) && (j > 1)) {
                swap(Data2, j, father);
                HeapDispData(Data2, N + 1);
                j = father;
                result = true;
            } else result = false;
        }
    }
    printf("---------------------------------------------------Create Heap Tree Finished \n");
    for(k = 1; k <= N; k++) printf("(%d)  ", k);
    printf("\n");
    for(i = N; i > 1; i--) {
        swap(Data2, 1, i);
        HeapDispData(Data2, i);
        AdjustTree(i - 1);
    }
}

// =========================================================================
// 5. Selection Sort
// =========================================================================
void SelectionDispData(int n, int out) {
    for(int i = 1; i <= n; i++) {
        if(out >= i) printf("[%2d] ", Data[i]);
        else printf("%2d   ", Data[i]);
    }
    printf("\n");
}

int Minimum(int j, int n) {
    int temp = Data[j], Location = j;
    for(int i = j + 1; i <= n; i++) {
        if(temp > Data[i]) {
            temp = Data[i];
            Location = i;
        }
    }
    return Location;
}

void SelectionSort(int n) {
    int i, Location;
    printf("---------------------------------------------------------------------\n");
    printf(" i LOC ");
    for(i = 1; i <= n; i++) printf("(%2d) ", i);
    printf("\n         ");
    SelectionDispData(n, 0);
    printf("---------------------------------------------------------------------\n");
    for(i = 1; i <= n; i++) {
        Location = Minimum(i, n);
        swap(Data, i, Location);
        printf("(%2d) (%2d) ", i, Location);
        SelectionDispData(n, i);
    }
}

// =========================================================================
// 6. Radix Sort
// =========================================================================
void ClearStackPT() {
    for(int i = 0; i < MaxRow; i++) Radix[i][0] = 0;
}

void Push(int Rad, int Dat) {
    int SP = Radix[Rad][0] + 1;
    Radix[Rad][0] = SP;
    Radix[Rad][SP] = Dat;
}

void ReadStack() {
    int k = 0, SP;
    for(int i = 0; i < MaxRow; i++) {
        SP = Radix[i][0];
        for(int j = 1; j <= SP; j++) {
            Data[k] = Radix[i][j];
            k++;
        }
    }
}

void RadixSort(int n) {
    int Digit, i, RadixNo;
    char Txt[10];
    for(Digit = 2; Digit >= 0; Digit--) {
        printf("[Digit : %d]==>\n", 3 - Digit);
        for(i = 0; i < n; i++) {
            sprintf(Txt, "%d", Data[i]); // ใช้ sprintf แทน itoa
            RadixNo = Txt[Digit] - '0';
            Push(RadixNo, Data[i]);
        }
        ReadStack();
        DispData(Data, n, true);
        ClearStackPT();
    }
}

// =========================================================================
// MAIN MENU
// =========================================================================
int main() {
    int choice;
    do {
        printf("\n=======================================================\n");
        printf("                   SORTING ALGORITHMS\n");
        printf("=======================================================\n");
        printf("  1. Insertion Sort\n");
        printf("  2. Bubble Sort\n");
        printf("  3. Quick Sort\n");
        printf("  4. Heap Sort\n");
        printf("  5. Selection Sort\n");
        printf("  6. Radix Sort\n");
        printf("  0. Exit\n");
        printf("=======================================================\n");
        printf("Select an option (0-6): ");
        scanf("%d", &choice);
        if (choice == 0) {
            printf("\nExiting program...\n");
            break;
        }
        switch (choice) {
            case 1:
                N = 12;
                PrepareRawData(N, false);
                printf("=============================="); 
                printf("\nASCENDING INSERTION SORT\n");
                printf("==============================\n"); 
                printf("Raw Data...");
                DispData(Data, N, false);
                printf("Processing Data...\n");
                InsertionSort(N);
                printf("----------------------------------------------------------------\n");
                printf("Sorted Data : ");
                DispData(Data, N, false);
                break;
            case 2:
                N = 12;
                PrepareRawData(N, false);
                printf("=============================="); 
                printf("\nASCENDING BUBBLE SORT\n");
                printf("==============================\n"); 
                printf("Raw Data : ");
                DispData(Data, N, false);
                printf("----------------------------------------------------------------\n");
                printf("Processing Data...\n");
                BubbleSort(N);
                printf("----------------------------------------------------------------\n");
                printf("Sorted Data : ");
                DispData(Data, N, false);
                break;
            case 3:
                N = 12;
                PrepareRawData(N, false);
                printf("=============================="); 
                printf("\nASCENDING QUICK SORT\n");
                printf("==============================\n"); 
                printf("Raw Data : ");
                DispData(Data, N, false);
                printf("Processing Data...\n");
                printf(" F  R  ");
                for(int i = 1; i <= N; i++) printf(" (%2d)", i);
                printf("\n");
                QuickSort(1, N);
                printf("----------------------------------------------------------------\n");
                printf("Sorted Data : ");
                DispData(Data, N, false);
                break;
            case 4:
                N = 8;
                PrepareRawData(N, false);
                printf("=============================="); 
                printf("\nASCENDING HEAP SORT\n");
                printf("==============================\n"); 
                printf("Raw Data : ");
                HeapDispData(Data, N + 1);
                printf("---------------------------------------------------Raw Data Finished \n");
                printf("Create Heap Tree...\n");
                CreateHeapTree();
                printf("Sorted Data is : ");
                HeapDispData(Data2, 1);
                printf("---------------------------------------------------Sort Finished \n");
                break;
            case 5:
                N = 12;
                PrepareRawData(N, false);
                printf("=============================="); 
                printf("\nASCENDING SELECTION SORT\n");
                printf("==============================\n"); 
                printf("Raw Data...");
                SelectionDispData(N, 0);
                printf("Processing Data...\n");
                SelectionSort(N);
                printf("---------------------------------------------------------------------\n");
                printf("Sorted Data : ");
                SelectionDispData(N, N);
                break;
            case 6:
                N = 16;
                PrepareRawData(N, true);
                printf("=============================="); 
                printf("\nASCENDING RADIX SORT\n");
                printf("==============================\n"); 
                printf("Raw Data...\n");
                DispData(Data, N, true);
                printf("---------------------------------------------------------------------\n");
                printf("Processing Data...\n");
                ClearStackPT();
                RadixSort(N);
                printf("--------------------------------------------------------------Finished\n");
                printf("Sorted Data : \n");
                DispData(Data, N, true);
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}