// Implement an algorithm to find the kth to last element of a singly linked list.
#include <stdio.h>
#include "linkedlist.h"

int get_ll_length(node *head) {
    int len = 0;
    for (; head; head = head->next, len++);
    return len;
}

node *get_kth_last_element(int k, node *head) {
    if (head == NULL) {
        printf("Null head");
        return 0;
    }
    int len = get_ll_length(head);
    int traverse_len = len - k;
    if (k >= len) {
        printf("k can't be greater than or equal to linked list len!\n");
        return 0;
    }

    for (; traverse_len-- > 1; head = head->next);
    
    return head;
}

int main(int argc, char *argv[]) {
    int k = strtol(argv[1], NULL, 10);
    char **argv_cpy = &(argv[2]);

    // Get linked list from argv
    node *head = parse_linked_list(argv_cpy);

    traverse_linked_list(head);
    node *kth_elem = get_kth_last_element(k, head);
    if (kth_elem != NULL) {
        printf("%s\n", kth_elem->str);
    }
}
