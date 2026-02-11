#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MaxNode 4
char NodeName[4] = {'A', 'B', 'C', 'D'};
int graph[MaxNode][MaxNode] = {
    {0, 1, 1, 1},
    {1, 0, 1, 1},
    {1, 1, 0, 0},
    {1, 1, 0, 0},
};
struct Node {
    char info;
    struct Node *next;
};
struct Node *Start[MaxNode], *p;



Node *Allocate() {
    struct Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    return (temp);
}

void CreateHead() {
    int i;
    for (i = 0; i < MaxNode; i++) {
        p = Allocate();
        p->info = NodeName[i];
        p->next = NULL;
        Start[i] = p;
    }
}

void TransferToAdjacent() {
    int i, j;
    struct Node *Rear;
    for (i = 0; i < MaxNode; i++) {
        Rear = Start[i];
        for (j = 0; j < MaxNode; j++) {
            if (graph[i][j] == 1) {
                p = Allocate();
                p->info = NodeName[j];
                p->next = NULL;
                Rear->next = p;
                Rear = p;
            }
        }
    }
}

void DispSetOfVertex() {
    int i;
    printf("\nSet of Vertex = {");
    for (i = 0; i < MaxNode; i++) {
        printf("%c", Start[i]->info);
        if (i != MaxNode - 1) {
            printf(",");
        }
    }
    printf("}\n");
}

void DispSetOfEdge() {
    int i;
    struct Node *Temp;
    printf("\nSet of Edge = {");
    for (i = 0; i < MaxNode; i++) {
        Temp = Start[i];
        Temp = Temp->next;
        while (Temp != NULL) {
            printf("(%c,%c),", Start[i]->info, Temp->info); 
            Temp = Temp->next;                             
        }
    }
    printf("}\n");
}

int main() {
    printf("GRAPH (ADJACENCY LIST REPRESENTATION METHOD)\n");
    printf("=============================================\n");
    CreateHead();
    TransferToAdjacent();
    DispSetOfVertex();
    DispSetOfEdge();
    getch();
    return (0);
}
