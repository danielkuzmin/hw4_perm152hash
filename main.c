#include <stdio.h>
#include "hw4_perm152hash.c"

// The main is just to test perm152hash
int main() {
    unsigned char buf[72] = "THIS IS A TEST OF HASH 72 bytes. The last output chunk should be padded.";
    unsigned char out[32];

    perm152hash(buf, 72, out);

//    for (int i = 0; i < 32; i++) {
//        printf("%c",buf[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < 32; i++) {
//        printf("%x",out[i]);
//    }

    return 0;
}