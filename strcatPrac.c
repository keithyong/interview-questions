#include <stdio.h>
#include <string.h>

int main() {
    char buf[2000];
    strcat(buf, "hi");
    printf("%s\n", buf);
    strcat(buf, "hi");
    printf("%s\n", buf);

    char intbuf[20];
    int x = 7;
    sprintf(intbuf, "%d", x);
    strcat(buf, intbuf);
    printf("%s\n", buf);
}
