#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* str;
    struct node *next;
} node;

node* parse_linked_list(char ** str_arr);
void traverse_linked_list(node *head);
void push_front(node **head, char *new_node_str);
void push_back(node **head, char *new_node_str);
node* search(node *head, char *search_str);
void free_list(node **head);
