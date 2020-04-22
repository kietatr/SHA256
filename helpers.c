/*
 * Some helper functions for main.c
 */

#include <stdio.h>
#include "helpers.h"

/*
 * Print the bytes (in hex) of a variable X.
 * No assumption of little-endian or big-endian. 
 * Can be used to check what type of endian (little-/big-endian) your machine has.
 * 
 * Example call: 
 *     int x = 0x01234567;
 *     printBytes(&x, sizeof(x));
 */
void printBytes(void const * const pointerX, size_t const sizeofX) {
    BYTE *X = (BYTE *) pointerX;

    for (int i = 0; i < sizeofX; i++) {
        printf("%.2x ", X[i]);
    }
    printf("\n");
}

/*
 * Print the binary representation of a variable X (of any datatype).
 * 
 * Adapted from: https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
 * 
 * Example call: 
 *     int x = 0x01234567;
 *     printBits(&x, sizeof(x));
 */
void printBits(void const * const pointerX, size_t const sizeofX) {
    BYTE *X = (BYTE *) pointerX;

    for (int i = 0; i < sizeofX; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%u", (X[i] >> j) & 1);  // Print the bit
            if (j % 4 == 0) {
                printf(" ");
            }
        }
        printf("| ");
    }
    printf("\n");
}