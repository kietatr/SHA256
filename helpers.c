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
 * Assume the machine is little-endian (that's why the loops go backwards).
 * 
 * Adapted from: https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
 */
void printBinary(void const * const pointerX, size_t const sizeofX) {
    BYTE *X = (BYTE *) pointerX;

    // For every byte
    for (int i = sizeofX-1; i >= 0; i--) {

        // For every bit in byte
        for (int j = 7; j >= 0; j--) {

            // Print the bit
            printf("%u", (X[i] >> j) & 1);

            if (j % 4 == 0) {
                printf(" ");
            }
        }
        printf("| ");
        
    }
    printf("\n");
}