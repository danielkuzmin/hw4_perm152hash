#include <stdio.h>
#include "hw4_perm152hash.c"

// The main is just to test perm152hash
int main() {
    printf("Printing out buffer:\n");
    unsigned char buf[72];

    for (int i = 0; i < 72; i++) {
        buf[i] = (unsigned char)i;
    }

    unsigned char out[32];
    perm152hash(buf, 72, out);

    for (int i = 0; i < 32; i++) {
        printf("%x\n",out[i]);
    }

    return 0;
}