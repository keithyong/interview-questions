#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    struct node* next;
    char *str;
};

void printLinkedList(struct node *head) {
    for (; head; head = head->next)
        printf("%s -> ", head->str);
    printf("(null)\n");
}

/* Given a linked list, reverses the list and returns its head 
 *
 * Warning: Will return NULL if head is NULL */
struct node* reverseLinkedList(struct node *head) {
    struct node* prev = NULL;
    struct node* next;

    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL) {
        return head;
    } else {
        for (; head; head = next) {
            next = head->next;
            head->next = prev;
            prev = head;
        }
    }

    return prev;
}

/* Given a string array, parses a linked list of the strings
 * in that array and returns a head node 
 *
 * Warning: Will return NULL if the char array is NULL.*/
struct node* parseLinkedListFromStringArray(char *arr[]) {
    struct node* head;
    struct node** constructor;

    constructor = &head;
    
    /* For each string in the char array */
    for (; *arr; arr++) {
        /* Allocate memory for the node that the constructor doubly points to */
        *constructor = malloc(sizeof **constructor);
        
        /* Copies the current string, and set the current node to point to that
         * fresh new string */
        (*constructor)->str = *arr;

        /* Move the constructor forward to the next node */
        constructor = &(*constructor)->next;
    }

    /* Null terminate our linked list */
    *constructor = NULL;

    return head;
}
int main(int argc, char *argv[]) {
    char **argvcpy = argv;
    argvcpy++;

    struct node* head = parseLinkedListFromStringArray(argvcpy);
    printLinkedList(head);
    head = reverseLinkedList(head);
    printLinkedList(head);
}
