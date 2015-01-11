/* 1.2 Implement a function void reverse(char* str) in C or C++ which reverses a null- terminated string. */

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./a.out [string]\n");
        return 0;
    } else {
        char *str = argv[1];
        int strlen;

        /* Move str to end of string and calculate strlen*/
        for (strlen = 0; *str; str++)
            strlen++;

        /* str points to null char right now, move it back one */
        str--;

        /* Declare a char array of strlen characters */
        char reversed[strlen + 1];

        int i;
        /* Fill up reversed char array */
        for (i = 0; i < strlen; i++, str--)
            reversed[i] = *str;

        /* Null terminate our reversed string! */
        reversed[strlen] = '\0';
        
        printf("%s\n", reversed);
    }
}
