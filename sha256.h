#ifndef SHA256_H
#define SHA256_H

#include <stddef.h>

/* DATA TYPES */
/************************************************************************/

typedef unsigned char BYTE;  // 8 bits
typedef unsigned int WORD;  // 32 bits; SHA-256 operates on 32-bit words

/* FUNCTION DECLARATIONS */
/************************************************************************/

BYTE *padding(void *pointerMsg, size_t strlenMsg);
char *sha256(char *inputMsg);

#endif