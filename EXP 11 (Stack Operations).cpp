#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

// PUSH operation
void push(int val) {
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = val;
}

// POP operation
void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

// PEEK operation
void peek() {
    if (top == -1)
        printf("Stack is Empty!\n");
    else
        printf("Top Element: %d\n", stack[top]);
}

// DISPLAY
void display() {
    if (top == -1)
        printf("Stack is Empty!\n");
    else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    do {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); push(val); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}

