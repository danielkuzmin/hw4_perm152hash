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

// Perm152 is prototyped below but defined in a separate file
void perm152(unsigned char *in, unsigned char *out);

void xor(unsigned char *dst, unsigned char *src, int num_bytes) {
    for (int i = 0; i < num_bytes; i++)
    {
        dst[i] ^= src[i];
    }
}

void perm152hash(unsigned char *m, int mbytes, unsigned char *res) {
//if(*m == 'c') return;
//if(mbytes == 0) return;
//if(res[0] == '0') return;
//
//    for (int i = 0; i < mbytes; i++)
//    {
//        res[i] = m[i];
//    }
//
//unsigned char ctemp[32] = "ABCDEFGHIDKLMLNOPQRSTUVWXYZabcde";


    //Prepare arrays
//    int nCapacity = 32;
//    int nRate = 32;
//    int nSize = 32;
//    unsigned char cState[32];
//    unsigned char cPadded[10 * nRate];
/*
    xor(ctemp, m, mbytes);

    for(int i = 0; i < mbytes; i++)
    {
        printf("%c", ctemp[i]);

    }
    printf("\n");

    unsigned char ctemp2[64];
    unsigned char ctemp3[64];
    memset(ctemp3, 0, 64);
    memset(ctemp2, 0, 64);

    for(int i = 0; i < 32; i++)
    {
        ctemp2[i] = ctemp[i];
    }

    perm152(ctemp2, ctemp3);

    for(int i = 0; i < mbytes; i++)
    {
        printf("%c", ctemp3[i]);
    }
    printf("\n");*/



    //absorb
    unsigned long MPaddedLen = (unsigned long) (32 + (10 * mbytes));
    unsigned char MPadded[MPaddedLen];

    memset(MPadded, 0, MPaddedLen);

    for(int i = 0; i < mbytes; i++)
    {
        MPadded[i] = m[i];
    }

    int n = mbytes / 32; //need a variable for rate


    unsigned char chunk[32];
    unsigned char result[32];
    unsigned char ctemp2b[64], ctemp3b[64];
    memset(result, 0, 32);

    // This loop need to step through MPadded extracting chunks
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            chunk[j] = MPadded[j];

        }
        xor(result, chunk, 32);


        memset(ctemp2b, 0, 64);
        memset(ctemp3b, 0, 64);

        for(int z = 0; z < 32; z++)
        {
            ctemp2b[z] = chunk[z];
        }

        perm152(ctemp2b, ctemp3b);

        for(int x = 0; x < 32; x++ )
        {
            result[x] = ctemp3b[x];
            res[x] = ctemp3b[x];

            //printf("%d ", result[x]);
        }
        printf("\n");



    }
//squeeze

    //Capacity
    int c = 32;
    //Rate
//    int r = 32;
    //Output length
    int b = 32;

    while(true)
    {
        for(int i = 0; i < c; i++){
            res[i] = result[i];
            if(i >= b-1)
            {
                return;
            }
        }
        perm152(ctemp2b, ctemp3b);
    }



    //*m, mbytes, *res parameter names


    // Initialize an array of 32 bytes that are all zero
    //unsigned char zeroArray[32];
    //memset(zeroArray, 0 ,32);

/*    while (mbytes >= 32) {
        unsigned char toProcess[64];
        // Copy the first 32 bytes of m to the processing array
        for (int i = 0; i < 32; i++) {
            toProcess[i] = m[i];
            res[i] = m[i];
        }
        mbytes = mbytes - 32;
        m += 32;
    }
*/

}
