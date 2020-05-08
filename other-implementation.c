/*
 * Testing amosnier's SHA-256 implementation
 */

// amosnier's SHA-256 implementation
#include "sha-2/sha-256.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "helpers.h"

/* FUNCTION DEFINITIONS */
/**********************************************************************************************************************/

/*
 * Stringify the result of amosnier's SHA-256 implementation
 */ 
char *otherSHA256(char *inputMsg) {
	char *input = inputMsg;

	char *result = malloc(sizeof(char) * 64);
	char hashByte[3];
	BYTE hash[32];

	// amosnier's SHA-256 implementation
	calc_sha_256(hash, input, strlen(input));

	for (int i = 0; i < 32; i++) {
		sprintf(hashByte, "%.2x", hash[i]);
		strcat(result, hashByte);
	}

	return result;
}

void testOtherSHA256(char *input, char *expectedOutput) {
	assert(strcmp(otherSHA256(input), expectedOutput) == 0);
}

void runTests() {
	testOtherSHA256("abc", "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
	testOtherSHA256("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef", "a8ae6e6ee929abea3afcfc5258c8ccd6f85273e0d4626d26c7279f3250f77c8e");
	testOtherSHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ  1234567890 !@#$%^&*()_+-= {}[];:<>,.? ~ `", "fcabf20898acdeb4cac195267c615a58adebaae5120a78dc8a608b366b1baa75");
}

/* MAIN */
/**********************************************************************************************************************/

int main() {
	runTests();
	return 0;
}