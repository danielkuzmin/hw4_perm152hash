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
#include "perm152.c"
// REMOVE THE ABOVE INCLUDE BEFORE TURNING IN

#include <stdio.h>
#include <stdbool.h>
#define Capacity 32
#define Rate 32
#define Output 32
#define Param64 64

void arrClear(unsigned char* arr, unsigned long len)
{
    memset(arr, 0, len);
}
void arrCopy(unsigned char* arrsrc, unsigned char* arrtgt, unsigned long len)
{
 memcpy(arrtgt, arrsrc, len);
}
void arrPrint(unsigned char* msg, unsigned long len)
{
    for(unsigned long i = 0; i < len; i++)
    {
        printf("%c", msg[i]);
    }
    printf("\n");
}
void printMsg(unsigned char* msg)
{
    printf("%s\n", msg);
}
// Perm152 is prototyped below but defined in a separate file
void perm152(unsigned char *in, unsigned char *out);

void xor(unsigned char *dst, unsigned char *src, int num_bytes) {
    for (int i = 0; i < num_bytes; i++)
    {
        dst[i] ^= src[i];
    }
}

void perm152hash(unsigned char *m, int mbytes, unsigned char *res) {
    //absorb
    unsigned long MPaddedLen = (unsigned long) (Capacity + (10 * mbytes));
    unsigned char MPadded[MPaddedLen];
    memset(MPadded, 0, MPaddedLen);
    arrCopy(m, MPadded, (unsigned long) mbytes);
    int n = mbytes/Rate;
    unsigned char chunk[Capacity];
    unsigned char result[Output];
    unsigned char ctemp2b[Param64], ctemp3b[Param64];
    memset(result, 0, Output);

    // This loop need to step through MPadded extracting chunks
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < Capacity; j++)
        {
            chunk[j] = MPadded[j];
        }
        xor(result, chunk, 32);
        memset(ctemp2b, 0, Param64);
        memset(ctemp3b, 0, Param64);
        arrCopy(ctemp2b, chunk, Rate);
        perm152(ctemp2b, ctemp3b);
        arrCopy(result, ctemp3b, Rate);
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
