#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node 
{
    struct node* next;
    char * str;
} node;

typedef struct hashTable {
    int size;
    node **table;
} hashTable;

void printLinkedList(node *head) {
    node * curr = head;
    while (curr != NULL) {
        printf("%s ->", curr->str);
        curr = curr->next;
    }
    if (curr == NULL)
        printf("(null)\n");
}

/* Assumes the programmer already malloced newNode */
void addNodeToLinkedList(node **newNode, node **nodeBeforeNewNode) {
    if (*nodeBeforeNewNode == NULL) {
        *nodeBeforeNewNode = *newNode;
    } else if ((*nodeBeforeNewNode)->next != NULL) {
        (*newNode)->next = (*nodeBeforeNewNode)->next;
        (*nodeBeforeNewNode)->next = (*newNode);
    } else if ((*nodeBeforeNewNode)->next == NULL){
        (*nodeBeforeNewNode)->next = (*newNode);
        (*newNode)->next = NULL;
    }
}

hashTable * createHashTable(int size) {
    hashTable *newTable;

    if (size < 1) 
        return NULL;
    if ((newTable = (hashTable *)malloc(sizeof(*newTable))) == NULL)
        return NULL;
    if ((newTable->table = malloc(sizeof(node *) * size)) == NULL)
        return NULL;

    int i;
    for (i = 0; i < size; i++)
        newTable->table[i] = NULL;

    newTable->size = size;
    
    return newTable;
}

unsigned int hash(hashTable *tab, char *str) {
    unsigned int hashval;
    hashval = 0;
    char * strptcpy = str;
    for (; *str; str++)
        hashval = *str + (hashval << 5) - hashval;

    printf("Hashed \"%s\" to %d\n", strptcpy, hashval%tab->size);
    return hashval % tab->size;
}

node* getFirstNodeFromHashTable(hashTable *t, char *str) {
    return (t->table)[hash(t, str)];
}

node * lookupString(hashTable *tab, char *str) {
    node *list = getFirstNodeFromHashTable(tab, str);

    for (; list; list = list->next) {
        if (strcmp(str, list->str) == 0)
            return list;
    }

    printf("Could not find \"%s\" in the hash table\n", str);
    return NULL;
}

int addString(hashTable *tab, char *str) {
    /* list is the first node of the hash table chain */
    node * list = getFirstNodeFromHashTable(tab, str);

    /* Check to see if we already have the string in our table */
    if (lookupString(tab, str)) {
        printf("String is in the table already!\n");
        return 0;
    }

    /* Our new node to be added */
    node* newString;
    if ((newString = (node *)malloc(sizeof(*newString))) == NULL)
        return 0;

    /* Alloc the node pointer's string */
    if ((newString->str = strdup(str)) == NULL)
        return 0;

    if (list == NULL)
        list = newString;
    else {
        newString->next = list->next;
        list->next = newString;
    }

    printf("Linked list shortly after hashing %s: ", str);
    printLinkedList(list);

    return 1;
}

int main(int argc, char *argv[]) {
    hashTable *tab = createHashTable(20);
    printf("Linked list at 13: ");
    printLinkedList((tab->table)[13]);
    char hi[] = "Hello!";
    addString(tab, hi);
    node *lookup = lookupString(tab, hi);
    printf("Lookup node: ");
    printLinkedList(lookup);
    printf("Linked list at 13: ");
    printLinkedList((tab->table)[13]);
}
