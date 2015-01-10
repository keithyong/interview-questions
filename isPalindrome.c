#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *str;

    if (argc != 2) {
        printf("Usage: isPalindrome [string]");
        return -1;
    } else {
        str = argv[1];
    }
    
    char *end = str;

    /* Move pointer to the end of the string */
    while (*end++);
    end = end - 2;

    int length;
    if ((length = strlen(str)) % 2 == 0) {
        /* Detects for even length strings */
        int i;
        for (i = 0; i < (length / 2); i++) {
            if (*end != *str) {
                printf("Not a palindrome!");
                return -1;
            }
            end--;
            str++;
        }
    } else {
        /* Detects for odd length strings */
        while (end != str) {
            if (*end != *str) {
                printf("Not a palindrome!");
                return -1;
            }
            end--;
            str++;
        }
    }

    printf("Yes it is a palindrome!\n");
}
