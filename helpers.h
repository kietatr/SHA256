#ifndef HELPERS_H
#define HELPERS_H

/* DATA TYPES */
/************************************************************************/

typedef unsigned char BYTE;
typedef unsigned int WORD;    // SHA-256 operates on 32-bit words

/* MACROS */
/* These functions are defined in FIPS 180-4, on pages 8-10 */
/* We use w = 32 here because SHA-256 operates on 32-bit words */
/************************************************************************/

#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))    // circular right shift
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))    // circular left shift

#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define S0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ ((x) >> 3))
#define S1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ ((x) >> 10))

/* FUNCTION DECLARATIONS */
/************************************************************************/

void printBytes(void const * const pointerX, size_t const sizeofX);
void printBinary(void const * const pointerX, size_t const sizeofX);

#endif