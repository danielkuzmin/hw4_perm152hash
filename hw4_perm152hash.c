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
#include <stdlib.h>

#define Capacity 32
#define Rate 32
#define Output 32

// Externally defined function prototype
void perm152(unsigned char *in, unsigned char *out);  // each an array of 64 bytes

void perm152hash(unsigned char *m, int mbytes, unsigned char *res) {

    unsigned int paddedLength = 0;
    if (mbytes <= 32)
        paddedLength = 32;
    else if (mbytes > 32) {
        int numblocks = mbytes/32;
        if (mbytes%32==0)
            ;// do nothing
        else
            numblocks = numblocks + 1;

        paddedLength = (unsigned int)numblocks * 32;
    }

    unsigned char *Mpadded = malloc((unsigned long)paddedLength * sizeof(unsigned char));
    memcpy(Mpadded, m, (unsigned long)mbytes);

    // Block as defined by the assignment
    unsigned char block[64] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
             0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x20,
             0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
             0x37, 0x38, 0x39, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x50, 0x51, 0x52,
             0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x60, 0x61, 0x62, 0x63, 0x64};


    // Pad to a multiple of 32
    unsigned char* mPaddedOriginal = Mpadded;
    int mbytesCopy = mbytes;
    while (mbytesCopy >= 32) {
        memcpy(Mpadded, m, 32);
        mbytesCopy -= 32;
        m += 32;
        Mpadded += 32;
    }

    // Final block of M is created by initializing an array of zeroes, and copying the last block's data into it
    unsigned char paddedFinal[32];
    for (int i = 0; i < 32; i++) {
        paddedFinal[i] = 0x00;
    }
    // Copy the data into the zero array
    memcpy(paddedFinal, m, (unsigned long)mbytesCopy);
    // Set the correct byte to 1
    paddedFinal[mbytesCopy] = 0b10000000;
    // Copy the padded final section into Mpadded
    memcpy(Mpadded, paddedFinal, (unsigned long)mbytesCopy);

    // Reset pointer
    Mpadded = mPaddedOriginal;

    int totalBlocks = mbytes/32;
    if (totalBlocks == 0)
        totalBlocks = 1;
    // for i to n
    for (int blockNum = 1; blockNum <= totalBlocks; blockNum++) {
        // XOR Mi into the first r bytes of block
        for (int i = 0; i < 32; i++) {
            block[i] = block[i]^Mpadded[i];
        }
        // block = perm(block)
        perm152(block, block);
    }

    // output the first min(r,b) bytes of block
    memcpy(res, block, 32);

    free(Mpadded);
}