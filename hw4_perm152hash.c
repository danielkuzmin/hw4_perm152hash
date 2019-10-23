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

// REMOVE THIS INCLUDE BEFORE TURING IN
//#include "perm152.c"

#include <stdio.h>
#include <stdbool.h>
#define Capacity 32
#define Rate 32
#define Output 32
#define Param64 64

// Sets elements in a given array to 0
void arrClear(unsigned char* arr, unsigned long len) {
    memset(arr, 0, len);
}

// Copies an array into another array for the given amount of elements
void arrCopy(unsigned char* arrsrc, unsigned char* arrtgt, unsigned long len) {
 memcpy(arrtgt, arrsrc, len);
}


// Perm152 is prototyped below but defined in a separate file
void perm152(unsigned char *in, unsigned char *out);

// XOR Two arrays for a given amount of bytes
void xor(unsigned char *dst, unsigned char *src, int num_bytes) {
    for (int i = 0; i < num_bytes; i++) {
        dst[i] ^= src[i];
    }
}

void perm152hash(unsigned char *m, int mbytes, unsigned char *res) {
    //absorb
    unsigned long MPaddedLen = (unsigned long) (10 * mbytes);
    unsigned char MPadded[MPaddedLen];
    memset(MPadded, 0, MPaddedLen);
    arrCopy(m, MPadded, (unsigned long) mbytes);
    MPadded[mbytes+1] = 1;
    int n = mbytes/Rate;
    unsigned char chunk[Capacity];
    unsigned char result[Output];
    unsigned char ctemp2b[Param64], ctemp3b[Param64];
    memset(result, 0, Output);

    // This loop need to step through MPadded extracting chunks
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < Capacity; j++)
        {
            chunk[j] = MPadded[(i*Rate) + j];
        }
        xor(result, chunk, Capacity);
        memset(ctemp2b, 0, Param64);
        memset(ctemp3b, 0, Param64);
        arrCopy(chunk, ctemp2b, Rate);
        perm152(ctemp2b, ctemp3b);
        arrCopy(ctemp3b, result, Rate);
    }
//squeeze
    while(true)
    {
        for(int i = 0; i < Capacity; i++){
            res[i] = result[i];
            if(i >= Output - 1)
            {
                return;
            }
        }
        perm152(ctemp2b, ctemp3b);
    }
}
