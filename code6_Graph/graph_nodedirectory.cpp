#include <stdio.h>
#include <conio.h>
#define MaxNode 4
#define Block 4
#define MaxEdge 6

char Head[MaxNode][Block] = {
    {'A', '-', '1', '1'},
    {'B', '-', '3', '2'},
    {'C', '-', '2', '5'},
    {'D', '-', '0', '0'},
};

char Edge[MaxEdge][2] = {
    {'2', 'B'},
    {'5', 'A'},
    {'9', 'C'},
    {'7', 'D'},
    {'8', 'B'},
    {'6', 'D'},
};

void DispHead() {
    int i, j;
    printf("NODE...\n");
    printf("No. Name Data Edge Pointer\n");
    for (i = 0; i < MaxNode; i++) {
        printf("%d   ", i + 1);
        for (j = 0; j < Block; j++) {
            printf("%c    ", Head[i][j]);
        }
        printf("\n");
    }
}

void DispEdge() {
    int i, j;
    printf("EDGE...\n");
    printf("No. Weight Node\n");
    for (i = 0; i < MaxEdge; i++) {
        printf("%d   ", i + 1);
        for (j = 0; j < 2; j++) {
            printf("%c      ", Edge[i][j]);
        }
        printf("\n");
    }
}

void DispSetOfVertex() {
    int i;
    printf("\nSet of Vertex = {");
    for (i = 0; i < MaxNode; i++) {
        printf("%c", Head[i][0]);
        if (i != MaxNode - 1) {
            printf(",");
        }
    }
    printf("}\n");
}

void DispSetOfEdge() {
    int i, j, AmtEdge, PT;
    printf("\nSet of Edge = {");
    for (i = 0; i < MaxNode; i++) {
        AmtEdge = Head[i][2] - 48;
        PT = Head[i][3] - 48;
        for (j = 0; j < AmtEdge; j++) {
            printf("(%c%c)%c,", Head[i][0], Edge[PT - 1 + j][1], Edge[PT - 1 + j][0]);
        }
    }
    printf("}\n");
}

int main() {
    printf("GRAPH NODE DIRECTORY REPRESENTATION METHOD\n");
    printf("=============================================\n");
    DispHead();
    DispEdge();
    DispSetOfVertex();
    DispSetOfEdge();
    getch();
    return (0);
}