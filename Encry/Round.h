/*
 * Round.h
 *
 *  Created on: Oct 15, 2022
 *      Author: user
 */
#ifndef round_guard
#define round_guard
typedef unsigned long long uint64;
typedef unsigned long uint32;
typedef unsigned char uint8;


typedef union
{
	unsigned long long Data;
	struct
	{
		unsigned long long BIT64:1;
		unsigned long long BIT63:1;
		unsigned long long BIT62:1;
		unsigned long long BIT61:1;
		unsigned long long BIT60:1;
		unsigned long long BIT59:1;
		unsigned long long BIT58:1;
		unsigned long long BIT57:1;
		unsigned long long BIT56:1;
		unsigned long long BIT55:1;
		unsigned long long BIT54:1;
		unsigned long long BIT53:1;
		unsigned long long BIT52:1;
		unsigned long long BIT51:1;
		unsigned long long BIT50:1;
		unsigned long long BIT49:1;
		unsigned long long BIT48:1;
		unsigned long long BIT47:1;
		unsigned long long BIT46:1;
		unsigned long long BIT45:1;
		unsigned long long BIT44:1;
		unsigned long long BIT43:1;
		unsigned long long BIT42:1;
		unsigned long long BIT41:1;
		unsigned long long BIT40:1;
		unsigned long long BIT39:1;
		unsigned long long BIT38:1;
		unsigned long long BIT37:1;
		unsigned long long BIT36:1;
		unsigned long long BIT35:1;
		unsigned long long BIT34:1;
		unsigned long long BIT33:1;
		unsigned long long BIT32:1;
		unsigned long long BIT31:1;
		unsigned long long BIT30:1;
		unsigned long long BIT29:1;
		unsigned long long BIT28:1;
		unsigned long long BIT27:1;
		unsigned long long BIT26:1;
		unsigned long long BIT25:1;
		unsigned long long BIT24:1;
		unsigned long long BIT23:1;
		unsigned long long BIT22:1;
		unsigned long long BIT21:1;
		unsigned long long BIT20:1;
		unsigned long long BIT19:1;
		unsigned long long BIT18:1;
		unsigned long long BIT17:1;
		unsigned long long BIT16:1;
		unsigned long long BIT15:1;
		unsigned long long BIT14:1;
		unsigned long long BIT13:1;
		unsigned long long BIT12:1;
		unsigned long long BIT11:1;
		unsigned long long BIT10:1;
		unsigned long long BIT9:1;
		unsigned long long BIT8:1;
		unsigned long long BIT7:1;
		unsigned long long BIT6:1;
		unsigned long long BIT5:1;
		unsigned long long BIT4:1;
		unsigned long long BIT3:1;
		unsigned long long BIT2:1;
		unsigned long long BIT1:1;
	}BITS;

	struct{
		unsigned long long remainder16:16;
		unsigned long long _6_BIT7:6;
		unsigned long long _6_BIT6:6;
		unsigned long long _6_BIT5:6;
		unsigned long long _6_BIT4:6;
		unsigned long long _6_BIT3:6;
		unsigned long long _6_BIT2:6;
		unsigned long long _6_BIT1:6;
		unsigned long long _6_BIT0:6;

	}_6_BITS;

	struct{
		unsigned long long remainder32:32;
		unsigned long long _4_BIT7:4;
		unsigned long long _4_BIT6:4;
		unsigned long long _4_BIT5:4;
		unsigned long long _4_BIT4:4;
		unsigned long long _4_BIT3:4;
		unsigned long long _4_BIT2:4;
		unsigned long long _4_BIT1:4;
		unsigned long long _4_BIT0:4;
	}_4_BITS;
}data_64bit;




extern inline uint64 Expansion(uint32 data);
extern inline uint64 XOR(uint64 right_data,uint64 key);
extern inline uint32 S_Box(uint64 data);
extern inline uint32 permutation(uint32 data);
extern inline uint64 Round(uint64 data , uint64 key_in);

#endif
