#include <stdio.h>
#include <ctype.h>
#define SIZE 50

int stack[SIZE], top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

int main() {
    char exp[SIZE];
    int i, op1, op2;
    
    printf("Enter a Postfix Expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i]))
            push(exp[i] - '0');  
        else {
            op2 = pop();
            op1 = pop();
            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}

