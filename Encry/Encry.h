/*
 * Encry.h
 *
 *  Created on: Oct 15, 2022
 *      Author: user
 */


#ifndef encrypt_guard
#define encrypt_guard

typedef unsigned long long uint64;
typedef unsigned char uint8;



extern inline uint64 Initial_Permutation(uint64 data);
extern inline uint64 Inverse_Permutation(uint64 data);
extern inline uint64 Encrypt(uint64 data,uint64 key_origin);
extern inline uint64 Decrypt(uint64 data,uint64 key_origin);
extern inline void swap(uint64 *ptr_plain);

#endif
