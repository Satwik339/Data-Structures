#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = 0, rear = -1;

// ENQUEUE operation
void enqueue(int val) {
    if (rear == SIZE - 1)
        printf("Queue Overflow!\n");
    else
        queue[++rear] = val;
}

// DEQUEUE operation
void dequeue() {
    if (front > rear)
        printf("Queue Underflow!\n");
    else
        printf("Dequeued: %d\n", queue[front++]);
}

// DISPLAY operation
void display() {
    if (front > rear)
        printf("Queue is Empty!\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}

