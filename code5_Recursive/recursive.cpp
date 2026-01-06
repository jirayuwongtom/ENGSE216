#include <stdio.h>
#include <conio.h>

int choice;
int Number, ans;
int M, N;

/* ---------- Factorial Function ---------- */
int Factorial(int N) {
    int x, y;
    if (N == 0) {
        printf("...............Roll Back Point\n");
        return 1;
    } else {
        x = N - 1;
        printf("%2d! = %2d * %2d!\n", N, N, x);
        y = Factorial(x);
        printf("%2d! = %2d * %3d = %5d\n", N, N, y, y * N);
        return N * y;
    }
}

/* ---------- Power Function M^N ---------- */
int Power(int M, int N) {
    if (N == 0) {
        printf("...............Roll Back Point\n");
        return 1;
    } else {
        printf("%d^%d = %d * %d^%d\n", M, N, M, M, N - 1);
        return M * Power(M, N - 1);
    }
}

/* ---------- Main Program ---------- */
int main() {

    do {
        printf("\nRECURSIVE PROGRAM MENU\n");
        printf("======================\n");
        printf("1. Factorial (N!)\n");
        printf("2. Power (M^N)\n");
        printf("0. Exit\n");
        printf("----------------------\n");
        printf("Select : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
    printf("\nRECRSIVE(FACTORIAL) PROGRAM\n");
    printf("===========================\n");

    printf("Enter Number (-999 is END) : ");
    scanf("%d", &Number);

    if (Number >= 0) {
        printf("N! = N(N-1)!\n");
        printf("------------\n");

        ans = Factorial(Number);

        printf("\nAnswer N! = %d\n", ans);
        printf("----------------Finished\n");
    }
    getch();
    break;


            case 2:
                printf("\nEnter M : ");
                scanf("%d", &M);
                printf("Enter N : ");
                scanf("%d", &N);

                if (N >= 0) {
                    ans = Power(M, N);
                    printf("\nAnswer %d^%d = %d\n", M, N, ans);
                } else {
                    printf("N must be >= 0\n");
                }
                getch();
                break;

            case 0:
                printf("\nExit Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
                getch();
        }

    } while (choice != 0);

    return 0;
}
