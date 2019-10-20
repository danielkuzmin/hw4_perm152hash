/*
 Daniel Kuzmin
 Class code: 1618
 October 20 2019
 Brief Description:
 This file contains the code for part A of the fourth assignment.
 This encrypts an array of 64 bits with the given algorithm.
 from the assignment, using Intel's SSE registers.
 Tested on Athena, compiled like so:
 clang -g -O0 -std=c99 -Werror -Wall -Wextra -Wconversion -fsanitize=address hw4_perm152hash.c
*/

#include "perm152.c"

void perm152hash(unsigned char *m, int mbytes, unsigned char *res) {

}

void perm152(unsigned char *in, unsigned char *out);