#include <stdio.h>
#include <stdlib.h>

// Define the linked list node structure
struct ListNode {
    int value;
    struct ListNode* next;
};

// Function to insert an element at the end of the linked list
void insert(struct ListNode** head, int value) {
    struct ListNode* newNode;
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode* current;
	current= *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Helper function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for the linked list
struct ListNode* partition(struct ListNode* low, struct ListNode* high) {
    int pivot; 
    struct ListNode* i;
    struct ListNode* j;
    
    pivot = low -> value;
    i = low;
    j = low -> next;
    while( j != high) {
        if (j->value < pivot) {
            i = i->next;
            swap(&(i->value), &(j->value));
        }
	j = j -> next;
    }

    swap(&(i->value), &(low->value));
    return i;
}

struct ListNode* quickSelect(struct ListNode* head, int k) {

    struct ListNode* pivotNode;
    int pivotPosition;

    if (head == NULL) {
        return NULL;
    }
    pivotNode = partition(head, NULL);
    pivotPosition = 0;
    struct ListNode* current;
    current = head;
    while (current != pivotNode) {
        pivotPosition++;
        current = current->next;
    }

    if (pivotPosition == k) {
        return pivotNode;
    } else if (pivotPosition < k) {
        return quickSelect(pivotNode->next, k - pivotPosition - 1);
    } else {
        return quickSelect(head, k);
    }
}

struct ListNode* findNthElement(struct ListNode* head, int n) {
    return quickSelect(head, n);
}

#include <stdio.h>
int main() {
    struct ListNode* head = NULL;
    insert(&head, 1);
    insert(&head, 9);
    insert(&head, 7);
    insert(&head, 5);
    insert(&head, 3);

    int n = 2; // Find the 2nd element

    struct ListNode* nthElement = findNthElement(head, n);

    if (nthElement != NULL) {
        printf("The %dth element is: %d\n", n, nthElement->value);
    } else {
        printf("Element not found\n");
    }
    printf("%i", head -> next -> next ->  value);

    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

