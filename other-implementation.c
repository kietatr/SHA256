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
	testOtherSHA256("abc ", "5488613c42b0d34d60f7aa9e94be317a3ee102a2bbd91ccc73cc79fbc2269955");

	testOtherSHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "3964294b664613798d1a477eb8ad02118b48d0c5738c427613202f2ed123b5f1");
	testOtherSHA256("0123456789", "84d89877f0d4041efb6bf91a16f0248f2fd573e6af05c19f96bedb9f882f7882");
	testOtherSHA256("!@#$%^&*()_+-= {}[];:<>,.? ~ `", "7c1b275b6e01e3ae39ed8ee8f9faf6dd9297e48e1d2f354de0c69a1288204353");
	testOtherSHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ  1234567890 !@#$%^&*()_+-= {}[];:<>,.? ~ `", "fcabf20898acdeb4cac195267c615a58adebaae5120a78dc8a608b366b1baa75");
	
	testOtherSHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "5e557aa2da4262edccbcb7dea9978a0cbda6371751b6c890a1fc35a3f25862d7");
	testOtherSHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "a88b0b5486d0edd934895adbd538764edae6b4acb4932d108d9cce4f4def9c72");

	printf("All tests passed for amosnier's implementation.\n");
}

/* MAIN */
/**********************************************************************************************************************/

int main() {
	runTests();
	return 0;
}