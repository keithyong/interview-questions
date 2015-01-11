#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./a.out [str1] [str2]\n");
        return 0;
    } else {
        char *str1 = argv[1];
        char *str2 = argv[2];
        int strlen1 = strlen(str1);
        int strlen2 = strlen(str2);
        if (strlen1 != strlen2) {
            printf("Nope, not a permutation of each other!\n");
            return 0;
        } else {
            qsort(str1, strlen1, sizeof(char), cmpfunc);
            qsort(str2, strlen2, sizeof(char), cmpfunc);
            
            for (; *str1; str1++, str2++)
                if (*str1 != *str2) {
                    printf("Nope, not a permutation of each other!\n");
                    return 0;
                }

            printf("Yes, a permutation of each other!\n");
            return 1;
        }
    }
        
}
