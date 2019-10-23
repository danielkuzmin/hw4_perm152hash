#include <stdio.h>
#include "hw4_perm152hash.c"

// The main is just to test perm152hash
int main() {
    unsigned char buf[32] = "THIS IS A TEST OF HASH 32 bytes.";
    int r;
    int c;
    int b;
    r = c = b = 32;

    for (int i = 0; i < c; i++) {
        //buf[i] = (unsigned char)i;
    }

    unsigned char out[32];
    perm152hash(buf, 32, out);

    for (int i = 0; i < 32; i++) {
        printf("%c",buf[i]);
    }
    printf("\n");
    for (int i = 0; i < 32; i++) {
        printf("%d ",out[i]);
    }

    return 0;
}