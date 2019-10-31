/*
 Daniel Kuzmin
 Class code: 1618
 October 20 2019
 Brief Description:
 This file contains the code for the fourth assignment.
 This is a sponge-based cryptographic hash that uses Perm152, constructed using the assignment PDF'S pseudocode
 Tested on Athena, compiled like so:
 clang -g -O0 -std=c99 -Werror -Wall -Wextra -Wconversion -fsanitize=address hw4_perm152hash.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define Capacity 32
#define Rate 32
#define Output 32

// Externally defined function prototype
void perm152(unsigned char *in, unsigned char *out);  // each an array of 64 bytes

void perm152hash(unsigned char *m, int mbytes, unsigned char *res) {

    unsigned char *Mpadded = malloc((unsigned long)mbytes * sizeof(unsigned char));
    memcpy(Mpadded, m, (unsigned long)mbytes);

    unsigned char block[64];
    for (int i = 0; i < 64; i++)
    {
        block[i] = (unsigned char)i+1;
        printf("%x ", block[i]);
    }

    while (mbytes >= 32)
    {
        // Process 32 bytes of m

        // 32 Bytes processed, decrement the counter by 32
        mbytes -= 32;
        // Advance the pointer by 32 bytes
        m += 32;
    }
    // Pad the remaining <32 bytes

    memcpy(res, Mpadded, 1);


    free(Mpadded);
}