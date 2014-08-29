#ifndef __SHA256_H__
#define __SHA256_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

typedef struct _sha256_t
{ 
	char  Value[ 32 ]; 
	int32_t  DwordBufBytes;
	int32_t  ByteNumLo;
	int32_t  ByteNumHi;
	int32_t  reg[ 8 ]; /** h0 to h 7 -- old value store*/
	int32_t  DwordBuf[ 16 ]; /** data store */
	int32_t  Padding[ 64 ];
}sha256_t;

uint64_t sha256_init(sha256_t* sha256);
uint64_t sha256_uninit(sha256_t* sha256);
uint64_t sha256_reset(sha256_t* sha256);
uint64_t sha256_calculate(sha256_t* sha256, char *data, uint64_t data_len);

#endif