#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define MaxStack 40

/* ================= PART 1 : INFIX TO POSTFIX ================= */
char infix1[80] = {"A+B*(C^D*E/F)-G"};
char postfix[80];
char OpSt[MaxStack];
int SP = 0;

void push(char oper)
{
    if (SP == MaxStack)
        printf("ERROR STACK OVER FLOW!!!...\n");
    else
        OpSt[++SP] = oper;
}

char pop()
{
    if (SP != 0)
        return OpSt[SP--];
    else
        printf("ERROR STACK UNDER FLOW!!!...\n");
    return 0;
}

int precedenceIP(char oper)
{
    switch (oper)
    {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': case '(': return 4;
    }
    return 0;
}

int precedenceST(char oper)
{
    switch (oper)
    {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '(': return 0;
    }
    return 0;
}

void infixTOpostfix(char infix2[80])
{
    int i, k = 0, len;
    char ch, temp;

    printf("INFIX : %s\n", infix2);
    len = strlen(infix2);
    printf("INFIX LENGTH : %d\n", len);
    for (i = 0; i < len; i++)
    {
        ch = infix2[i];
        if (strchr("+-*/^()", ch) == 0)
            postfix[k++] = ch;
        else
        {
            if (SP == 0)
                push(ch);
            else if (ch != ')')
            {
                if (precedenceIP(ch) > precedenceST(OpSt[SP]))
                    push(ch);
                else
                {
                    postfix[k++] = pop();
                    while (SP != 0 &&
                           precedenceIP(ch) <= precedenceST(OpSt[SP]))
                        postfix[k++] = pop();
                    push(ch);
                }
            }
            else
            {
                temp = pop();
                while (temp != '(')
                {
                    postfix[k++] = temp;
                    temp = pop();
                }
            }
        }
    }
    while (SP != 0)
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("POSTFIX : %s\n\n", postfix);
}

/* ================= PART 2 : POSTFIX CALCULATION ================= */
float ValPostfix[80];
float ValOperandST[MaxStack];
int SP2 = 0;

void pushVal(float val)
{
    ValOperandST[++SP2] = val;
}

float popVal()
{
    return ValOperandST[SP2--];
}

void CalPostfix(char postfix1[80])
{
    float pop1, pop2, value;
    int i, len;
    char ch;
    len = strlen(postfix1);
    for (i = 0; i < len; i++)
    {
        ch = postfix1[i];
        if (strchr("+-*/^", ch) == 0)
        {
            printf("Assign Number to %c : ", ch);
            scanf("%f", &ValPostfix[i]);
        }
    }
    for (i = 0; i < len; i++)
    {
        ch = postfix1[i];

        if (strchr("+-*/^", ch) == 0)
            pushVal(ValPostfix[i]);
        else
        {
            pop1 = popVal();
            pop2 = popVal();

            switch (ch)
            {
                case '+': value = pop2 + pop1; break;
                case '-': value = pop2 - pop1; break;
                case '*': value = pop2 * pop1; break;
                case '/': value = pop2 / pop1; break;
                case '^': value = pow(pop2, pop1); break;
            }
            pushVal(value);
        }
    }
    printf("\nANS = %f\n", popVal());
}

/* ================= MAIN ================= */
int main()
{
    printf("INFIX TO POSTFIX & CALCULATION PROGRAM\n");
    printf("=====================================\n\n");
    infixTOpostfix(infix1);
    CalPostfix(postfix);
    getch();
    return 0;
}
