#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

char ch; // KBD Read variable

void DecToBin(unsigned int data2, int byt) // Convert Decimal to Binary as byt Bytes
{
    int count, chk, bits;
    bits = (byt * 8) - 1; // Calculate total bits started at bit no 0
    for (count = bits; count >= 0; count--)
    {
        chk = data2 >> count; // Shift right count bits of data2
        if (chk & 1)
            printf("1");
        else
            printf("0");
        if (count % 4 == 0 && count > 3)
            printf(" ");
    }
    printf("B\n");
}

void UnsignedShortInt()
{
    unsigned short int data;
    printf("\nUNSIGNED SHORT INTEGER MODE [0 to 65,535]\n");
    printf("===========================================\n");
    printf("Enter Raw Data : ");
    scanf("%hu", &data);
    printf("Data in Decimal = %huD\n", data);
    printf("Data in Hexadecimal = %xH\n", data);
    printf("Data in Binary  = ");
    DecToBin(data, sizeof(data));
    printf("Size            = %d Bytes\n", (int)sizeof(data));
    getch();
}

void UnsignedInt()
{
    unsigned int data;
    printf("\nUNSIGNED INTEGER MODE [0 to 4,294,967,295]\n");
    printf("============================================\n");
    printf("Enter Raw Data : ");
    scanf("%u", &data);
    printf("Data in Decimal = %uD\n", data);
    printf("Data in Hexadecimal = %xH\n", data);
    printf("Data in Binary  = ");
    DecToBin(data, sizeof(data));
    printf("Size            = %d Bytes\n", (int)sizeof(data));
    getch();
}

void Boolean()
{
    unsigned int data;
    printf("\nBOOLEAN MODE [0 to 255]\n");
    printf("==========================\n");
    printf("Enter Raw Data : ");
    scanf("%u", &data);
    printf("Data Meaning    = ");
    if (data)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    printf("Data in Decimal = %uD\n", data);
    printf("Data in Hexadecimal = %xH\n", data);
    printf("Character       = %c\n", data);
    printf("Data in Binary  = ");
    DecToBin(data, sizeof(data));
    printf("Size            = %d Bytes\n", (int)sizeof(data));
    getch();
}

void Character()
{
    char data;
    printf("\nCHARACTER MODE [0 to 255]\n");
    printf("==========================\n");
    printf("Enter Raw Data : ");
    scanf(" %c", &data); // ใส่ space ก่อน %c เพื่อข้าม newline
    printf("Data in Decimal = %uD\n", (unsigned char)data);
    printf("Data in Hexadecimal = %xH\n", (unsigned char)data);
    printf("Character       = %c\n", data);
    printf("Data in Binary  = ");
    DecToBin((unsigned char)data, sizeof(data));
    printf("Size            = %d Bytes\n", (int)sizeof(data));
    getch();
}

void SFloat()
{
    float data;
    printf("\nSingle Precision Float MODE [1.2E-38 to 3.4E+38]\n");
    printf("===================================================\n");
    printf("Enter Raw Data : ");
    scanf("%f", &data);
    printf("Data in Decimal = %fD\n", data);
    
    // แปลง float เป็น unsigned int เพื่อแสดง binary
    unsigned int *ptr = (unsigned int *)&data;
    printf("Data in Binary  = ");
    DecToBin(*ptr, sizeof(data));
    printf("Size            = %d Bytes\n", (int)sizeof(data));
    getch();
}

int main()
{
    printf("\nDATA REPRESENTATION PROGRAM...\n");
    printf("================================\n");
    while (ch != '0')
    {
        printf("\n[1]:Unsigned Short Int   [2]:Boolean    [3]:Unsigned Int\n");
        printf("[4]:Character            [5]:Single Prec Float [0]:Exit\n");
        ch = getch();
        switch (ch)
        {
        case '1':
            UnsignedShortInt();
            break;
        case '2':
            Boolean();
            break;
        case '3':
            UnsignedInt();
            break;
        case '4':
            Character();
            break;
        case '5':
            SFloat();
            break;
        }
    }
    printf("\n");
    return 0;
}
