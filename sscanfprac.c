#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    static char buf[] = "1 2 3 hi\0";
    FILE *stream;

    stream = fmemopen(buf, strlen(buf), "r");
}
