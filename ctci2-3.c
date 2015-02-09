#include <stdio.h>
#include "linkedlist.h"

int delete_node_ref(node **to_del) {
    if ((*to_del) == NULL) {
        return -1;
    }
    else if ((*to_del)->next == NULL) {
        (*to_del) = NULL;
        return 1;
    }
    else if ((*to_del)->next->next == NULL) {
        node *extra = (*to_del)->next;
        (*to_del)->str = extra->str;
        (*to_del)->next = NULL;
        free(extra);
        return 1;
    } else {
        node *extra = (*to_del)->next;
        (*to_del)->str = extra->str;
        (*to_del)->next = extra->next;
        free(extra);
        return 1;
    }
    return 0;
}
int main(int argc, char *argv[]) {
    node *head = parse_linked_list(&(argv[1]));
    traverse_linked_list(head);
    delete_node_ref(&head);
    delete_node_ref(&head);
    delete_node_ref(&head);
    delete_node_ref(&head);
    delete_node_ref(&head);
    traverse_linked_list(head);
}
