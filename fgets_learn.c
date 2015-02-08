#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

const int max_buf_siz = 2000;

int main() {
    char buf[max_buf_siz];
    /* Get this type of input:
     * sum 2 3 3
     * min 9 8 72
     */

    while(fgets(buf, max_buf_siz, stdin) != NULL) {
        char *buf_cpy = buf;
        int x, str_offset, chars_read, bytes;
        bytes = str_offset = x = chars_read = 0;
        
        char arg1[200];
        sscanf(buf_cpy, "%s%n", arg1, &bytes);
        printf("arg1 = %s\n", arg1);
        str_offset += bytes;
        while(sscanf(buf_cpy + str_offset, "%d%n", &x, &bytes) > 0) {
            str_offset += bytes;
            printf("str_offset = %d\n", str_offset);
            printf("x = %d\n", x);
        }
    }
}
