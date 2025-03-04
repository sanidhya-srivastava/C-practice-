#include <stdio.h>

#define MAX_SIZE 100 
int i;
// Function to add an element to the end of the list
int addElement(int list[], int size, int element) {
    if (size < MAX_SIZE) {
        list[size] = element;
        size++;
        printf("Element %d added to the list.\n", element);
    } else {
        printf("List is full! Cannot add more elements.\n");
    }
    return size;  // Return the updated size
}

// Function to insert an element at a specific position in the list
int insertElement(int list[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("List is full! Cannot insert element.\n");
        return size;
    }
    if (position < 0 || position > size) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", size);
        return size;
    }
    // Shift elements to the right to make space for the new element
    for (i = size; i > position; i--) {
        list[i] = list[i - 1];
    }
    list[position] = element;
    size++;
    printf("Element %d inserted at position %d.\n", element, position);
    return size;  // Return the updated size
}

// Function to remove an element from the list by value
int removeElement(int list[], int size, int element) {
	int j;
    int found = 0;
    for (i = 0; i < size; i++) {
        if (list[i] == element) {
            found = 1;
            for (j = i; j < size - 1; j++) {
                list[j] = list[j + 1];
            }
            size--;
            printf("Element %d removed from the list.\n", element);
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the list.\n", element);
    }
    return size;  // Return the updated size
}

// Function to remove an element from the list by position
int removeElementAtPosition(int list[], int size, int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", size - 1);
        return size;
    }
    // Shift elements to the left to fill the gap
    for (i = position; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    size--;
    printf("Element at position %d removed from the list.\n", position);
    return size;  // Return the updated size
}
// Function to search for an element in the list
void searchElement(int list[], int size, int element) {
    int found = 0;
    for (i = 0; i < size; i++) {
        if (list[i] == element) {
            printf("Element %d found at index %d.\n", element, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the list.\n", element);
    }
}

// Function to display the list
void displayList(int list[], int size) {
    printf("Current List: ");
    for (i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];  // Array to store the list elements
    int size = 0;  // Current size of the list
    int choice, element, position;

    // Initialize the list with some elements
    printf("Enter the number of initial elements in the list (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size > MAX_SIZE) {
        printf("Size exceeds maximum allowed. Setting size to %d.\n", MAX_SIZE);
        size = MAX_SIZE;
    }

    printf("Enter the elements of the list:\n");
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &list[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Element to End\n");
         printf("2. Insert Element at Position\n");
        printf("3. Remove Element by Value\n");
        printf("4. Remove Element by Position\n");
        printf("5. Search Element\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                size = addElement(list, size, element);//4  
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert at (0 to %d): ",size-1);
                scanf("%d", &position);
                size = insertElement(list, size, element, position);
                break;
            case 3:
                printf("Enter element to remove: ");
                scanf("%d", &element);
                size = removeElement(list, size, element);
                break;
            case 4:
                printf("Enter position to remove (0 to %d): ", size - 1);
                scanf("%d", &position);
                size = removeElementAtPosition(list, size, position);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &element);
                searchElement(list, size, element);
                break;
            case 6:
                displayList(list, size);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
                break;
        }
    }
    return 0;
}