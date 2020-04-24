#include <stdio.h>
#include <string.h>
#include "helpers.h"

/* DATA TYPES */
/************************************************************************/

typedef unsigned int WORD;  // 32 bits; SHA-256 operates on 32-bit words

/* 
 * MACROS
 * (FIPS 180-4, pages 8->10)
 * For ROTR and ROTL, we use w = 32, because SHA-256 operates on 32-bit words 
 */
/*******************************************************************************/

// Rotate right (circular right shift)
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

// Rotate left (circular left shift)
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define S0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ ((x) >> 3))
#define S1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ ((x) >> 10))

/* 
 * CONSTANTS 
 * (FIPS 180-4, page 11)
 * These words represent the first thirty-two bits of the fractional parts of
 * the cube roots of the first 64 prime numbers. 
 */
/*******************************************************************************/

const WORD K[64] = {
    0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
	0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
	0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
	0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
	0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
	0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
	0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
	0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

/* FUNCTION DEFINITIONS */
/*******************************************************************************/

/*
 * Padding the input message
 * (FIPS 180-4, Section 5.1.1, page 13)
 */
void padding(void *pointerMsg, size_t strlenMsg) {
	BYTE * msg = (BYTE *) pointerMsg;

	// Length of input message in bits
	unsigned int l = strlenMsg * 8;

	// Number of zeros to pad
	// Find k such that (l + 1 + k + 64) % 512 == 0
	unsigned int k = 512 - ((l + 1 + 64) % 512);

	// Number of 512-bit message blocks
	unsigned int n = (l + 1 + k + 64) / 512;

	// l in 64-bit format
	unsigned long long l_64 = (unsigned long long) l;

	// TODO: remember to append l_64 to the padded message in big-endian order (zeros go on the left)
	// TODO: return the padded message

	printf("l = %d\n k = %d\n n = %d\n", l, k, n);
	printBits(&l_64, sizeof(l_64));
}

/* MAIN */
/*******************************************************************************/

int main() {
	char testStr[] = "abc";
	padding(&testStr, strlen(testStr));
    return 0;
}