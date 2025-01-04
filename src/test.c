// C program to sort a doubly linked list
// using quicksort
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to swap the data of two nodes
void swap(struct Node* a, struct Node* b) {

    // Swap the data in the nodes
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to partition the list and find pivot
struct Node* partition(struct Node* low,
                       struct Node* high) {

    // Set pivot to the high node
    int pivot = high->data;

    // Pointer to place smaller elements
    struct Node* i = low->prev;i = (i == NULL) ? low : i->next;

    // Traverse the list to rearrange nodes
    for (struct Node* j = low; j != high;
         j = j->next) {

        // If current node's data is less than
        // or equal to the pivot
        if (j->data <= pivot) {

            // Move `i` forward and swap with `j`
            i = (i == NULL) ? low : i->next;
            swap(i, j);
        }
    }

    // Move `i` to the correct pivot position
    i = (i == NULL) ? low : i->next;

    // Swap pivot with `i`'s data
    swap(i, high);

    return i;
}

// Recursive function to apply quicksort
void quickSort(struct Node* low, struct Node* high) {

    // Base case: if the list has one element or
    // invalid range
    if (low != NULL && high != NULL
        && low != high && low != high->next) {

        // Find the partition node (pivot)
        struct Node* pivot = partition(low, high);

        // Recursively sort the left half
        quickSort(low, pivot->prev);

        // Recursively sort the right half
        quickSort(pivot->next, high);
    }
}

// Function to get the last node of the list
struct Node* getLastNode(struct Node* head) {

    // Traverse to the end of the list
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

void printList(struct Node* node) {
    struct Node* curr = node;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

struct Node* createNode(int new_data) {
    struct Node* new_node =
      (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int main() {

    // Create a hard-coded doubly linked list:
    // 5 <-> 3 <-> 4 <-> 1 <-> 2
    struct Node* head = createNode(5);
    head->next = createNode(3);
    head->next->prev = head;
    head->next->next = createNode(4);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(1);
    head->next->next->next->prev =
                     head->next->next;
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->prev =
                     head->next->next->next;

    struct Node* last = getLastNode(head);

    quickSort(head, last);

    printList(head);

    return(0);
}
