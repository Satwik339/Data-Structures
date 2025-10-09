#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Insert key using linear probing
void insert(int key) {
    int index = key % SIZE;
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE)
        i++;

    if (i < SIZE)
        hashTable[(index + i) % SIZE] = key;
    else
        printf("Hash table is full! Cannot insert %d\n", key);
}

// Search key
void search(int key) {
    int index = key % SIZE;
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        if (hashTable[(index + i) % SIZE] == key) {
            printf("Key %d found at index %d\n", key, (index + i) % SIZE);
            return;
        }
        i++;
    }
    printf("Key %d not found!\n", key);
}

// Display hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, hashTable[i]);
}

int main() {
    int choice, key;

    init();

    do {
        printf("\n1.Insert 2.Search 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

