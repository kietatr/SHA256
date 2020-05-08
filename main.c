/*
 * Testing my SHA-256 implementation
 */

// My SHA-256 implementation
#include "sha256.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "helpers.h"

/* FUNCTION DEFINITIONS */
/**********************************************************************************************************************/

void testMySHA256(char *input, char *expectedOutput) {
	// printf("\nTesting sha256(%s) == %s\n", input, expectedOutput);

	assert(strcmp(sha256(input), expectedOutput) == 0);
	
	// printf("Test PASSED\n");
	// printf("------------------------------------------------------------------------------------------\n");
}

void runMyTests() {
	testMySHA256("abc", "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
	testMySHA256("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef", "a8ae6e6ee929abea3afcfc5258c8ccd6f85273e0d4626d26c7279f3250f77c8e");
	testMySHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ  1234567890 !@#$%^&*()_+-= {}[];:<>,.? ~ `", "fcabf20898acdeb4cac195267c615a58adebaae5120a78dc8a608b366b1baa75");
}

/* MAIN */
/**********************************************************************************************************************/

int main() {	
	runMyTests();
	return 0;
}