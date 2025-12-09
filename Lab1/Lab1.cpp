#include <stdio.h>

void printBinaryChar(unsigned char value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i == 4) {
            printf(" ");
        }
    }
}

void printBinaryInt(int value) {
    int totalBits = sizeof(int) * 8;
    for (int i = totalBits - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" ");
    }
}

void printBinaryDouble(double value) {
    unsigned char* bytes = (unsigned char*)&value;
    for (int i = sizeof(double)-1; i >=0; i--) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (bytes[i] >> j) & 1);
        }
    }
}

int main() {
    int choice;
    printf("=====MENU=====\n");
    printf("[1] : Int\n");
    printf("[2] : Char\n");
    printf("[3] : Double\n");
    printf("[0] : Exit\n");
    printf("Select Menu : ");
    scanf("%d", &choice);

    if (choice == 1) {
        int x;
        printf("Enter Data : ");
        scanf("%d", &x);
        printf("Decimal = %d\n", x);
        printf("Hexadecimal = %X\n", x);
        printf("Binary = ");
        printBinaryInt(x);
        printf("\nSize = %zu Bytes\n", sizeof(x));
    }
    else if (choice == 2) {
        unsigned char x;
        printf("Enter Data : ");
        scanf(" %c", &x);
        printf("Decimal = %u\n", x);
        printf("Hexadecimal = %X\n", x);
        printf("Binary = ");
        printBinaryChar(x);
        printf("\nSize = %zu Bytes\n", sizeof(x));
    }
    else if (choice == 3) {
        double x;
        printf("Enter Data : ");
        scanf("%lf", &x);
        printf("Decimal = %lf\n", x);
        unsigned char* bytes = (unsigned char*)&x;
        printf("Hexadecimal = ");
        for (size_t i = 0; i < sizeof(x); i++) {
            printf("%02X", bytes[i]);
        }
        printf("\n");
        printf("Binary = ");
        printBinaryDouble(x);
        printf("\nSize = %zu Bytes\n", sizeof(x));
    }
    else if (choice == 0) {
        return 0;
    }
    else {
        printf("Invalid choice.\n");
    }
    return 0;
}