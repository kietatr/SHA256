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
	testMySHA256("abc ", "5488613c42b0d34d60f7aa9e94be317a3ee102a2bbd91ccc73cc79fbc2269955");

	testMySHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "3964294b664613798d1a477eb8ad02118b48d0c5738c427613202f2ed123b5f1");
	testMySHA256("0123456789", "84d89877f0d4041efb6bf91a16f0248f2fd573e6af05c19f96bedb9f882f7882");
	testMySHA256("!@#$%^&*()_+-= {}[];:<>,.? ~ `", "7c1b275b6e01e3ae39ed8ee8f9faf6dd9297e48e1d2f354de0c69a1288204353");
	testMySHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ  1234567890 !@#$%^&*()_+-= {}[];:<>,.? ~ `", "fcabf20898acdeb4cac195267c615a58adebaae5120a78dc8a608b366b1baa75");
	
	testMySHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "5e557aa2da4262edccbcb7dea9978a0cbda6371751b6c890a1fc35a3f25862d7");
	testMySHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "a88b0b5486d0edd934895adbd538764edae6b4acb4932d108d9cce4f4def9c72");
	testMySHA256("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "3fc0da3e78ee2d243f80d085f154ef52d01aadf37cdceb614e682d50dd37f45a");	

	printf("All tests passed for my implementation.\n");
}

/* MAIN */
/**********************************************************************************************************************/

int main() {	
	runMyTests();
	return 0;
}