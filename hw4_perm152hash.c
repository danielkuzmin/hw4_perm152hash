/*
 Daniel Kuzmin
 Class code: 1618
 October 20 2019
 Brief Description:
 This file contains the code for part A of the fourth assignment.
 This is a sponge-based cryptographic hash that uses Perm152, constructed using the assignment PDF'S pseudocode
 Tested on Athena, compiled like so:
 clang -g -O0 -std=c99 -Werror -Wall -Wextra -Wconversion -fsanitize=address hw4_perm152hash.c
*/

// REMOVE THIS INCLUDE BEFORE TURING IN
#include "perm152.c"
// REMOVE THE ABOVE INCLUDE BEFORE TURNING IN

#include <stdio.h>

// Perm152 is prototyped below but defined in a separate file
void perm152(unsigned char *in, unsigned char *out);

void perm152hash(unsigned char *m, int mbytes, unsigned char *res) {

    // Initialize an array of 32 bytes that are all zero
    unsigned char zeroArray[32];
    memset(zeroArray, 0 ,32);
    //for (int i = 0; i < 32; i++)
    //    zeroArray[i] = zeroArray[i] & 0;


    while (mbytes >= 32) {
        unsigned char toProcess[64];
        // Copy the first 32 bytes of m to the processing array
        for (int i = 0; i < 32; i++)
            toProcess[i] = m[i];



        mbytes = mbytes - 32;
        m += 32;
    }
}
