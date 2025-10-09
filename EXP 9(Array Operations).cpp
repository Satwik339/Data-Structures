#include <stdio.h>

int main() {
    int arr[50], n, i, pos, choice, element;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Insert
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert (1 to %d): ", n+1);
                scanf("%d", &pos);
                if(pos < 1 || pos > n+1) {
                    printf("Invalid position!\n");
                    break;
                }
                for(i = n; i >= pos; i--)
                    arr[i] = arr[i-1];
                arr[pos-1] = element;
                n++;
                printf("Element inserted.\n");
                break;

            case 2: // Delete
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if(pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                for(i = pos-1; i < n-1; i++)
                    arr[i] = arr[i+1];
                n--;
                printf("Element deleted.\n");
                break;

            case 3: // Display
                printf("Array elements: ");
                for(i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 4: // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}

