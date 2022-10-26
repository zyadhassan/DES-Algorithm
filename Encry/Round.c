/*
 * Round.c
 *
 *  Created on: Oct 15, 2022
 *      Author: user
 */



#include "Round.h"

uint64 keys[16] = {0x0B02679B49A50000, 0x69A659256A26, 0x45D48AB428D2, 0x7289D2A58257, 0x3CE80317A6C2, 0x23251E3C8545, 0x6C04950AE4C6,
                   0x5788386CE581, 0xC0C9E926B839, 0x91E307631D72, 0x211F830D893A, 0x7130E5455C54, 0x91C4D04980FC, 0x5443B681DC8D,
                   0xB691050A16B5, 0xCA3D03B87032};

char S1[4][16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
	              0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
		          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
		          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};

char S2[4][16] = {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
		          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
				  0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
				  13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};

char S3[4][16] = {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};

char S4[4][16] = {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                  10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};

char S5[4][16] = {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                  14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};

char S6[4][16] = {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                  9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};

char S7[4][16] = {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};

char S8[4][16] = {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};


inline uint64 Expansion(uint32 data)
{
	data_64bit right_data;
	right_data.Data=0;
	uint64 data_64=data;
	right_data.Data = (data_64<<32);
	data_64bit temp;
	temp.Data = 0;

	temp.BITS.BIT1 = right_data.BITS.BIT32;
	temp.BITS.BIT2 = right_data.BITS.BIT1;
	temp.BITS.BIT3 = right_data.BITS.BIT2;
	temp.BITS.BIT4 = right_data.BITS.BIT3;
	temp.BITS.BIT5 = right_data.BITS.BIT4;
	temp.BITS.BIT6 = right_data.BITS.BIT5;
	temp.BITS.BIT7 = right_data.BITS.BIT4;
	temp.BITS.BIT8 = right_data.BITS.BIT5;
	temp.BITS.BIT9 = right_data.BITS.BIT6;
	temp.BITS.BIT10 = right_data.BITS.BIT7;
	temp.BITS.BIT11 = right_data.BITS.BIT8;
	temp.BITS.BIT12 = right_data.BITS.BIT9;
	temp.BITS.BIT13 = right_data.BITS.BIT8;
	temp.BITS.BIT14 = right_data.BITS.BIT9;
	temp.BITS.BIT15 = right_data.BITS.BIT10;
	temp.BITS.BIT16 = right_data.BITS.BIT11;
	temp.BITS.BIT17 = right_data.BITS.BIT12;
	temp.BITS.BIT18 = right_data.BITS.BIT13;
	temp.BITS.BIT19 = right_data.BITS.BIT12;
	temp.BITS.BIT20 = right_data.BITS.BIT13;
	temp.BITS.BIT21 = right_data.BITS.BIT14;
	temp.BITS.BIT22 = right_data.BITS.BIT15;
	temp.BITS.BIT23 = right_data.BITS.BIT16;
	temp.BITS.BIT24 = right_data.BITS.BIT17;
	temp.BITS.BIT25 = right_data.BITS.BIT16;
	temp.BITS.BIT26 = right_data.BITS.BIT17;
	temp.BITS.BIT27 = right_data.BITS.BIT18;
	temp.BITS.BIT28 = right_data.BITS.BIT19;
	temp.BITS.BIT29 = right_data.BITS.BIT20;
	temp.BITS.BIT30 = right_data.BITS.BIT21;
	temp.BITS.BIT31 = right_data.BITS.BIT20;
	temp.BITS.BIT32 = right_data.BITS.BIT21;
	temp.BITS.BIT33 = right_data.BITS.BIT22;
	temp.BITS.BIT34 = right_data.BITS.BIT23;
	temp.BITS.BIT35 = right_data.BITS.BIT24;
	temp.BITS.BIT36 = right_data.BITS.BIT25;
	temp.BITS.BIT37 = right_data.BITS.BIT24;
	temp.BITS.BIT38 = right_data.BITS.BIT25;
	temp.BITS.BIT39 = right_data.BITS.BIT26;
	temp.BITS.BIT40 = right_data.BITS.BIT27;
	temp.BITS.BIT41 = right_data.BITS.BIT28;
	temp.BITS.BIT42 = right_data.BITS.BIT29;
	temp.BITS.BIT43 = right_data.BITS.BIT28;
	temp.BITS.BIT44 = right_data.BITS.BIT29;
	temp.BITS.BIT45 = right_data.BITS.BIT30;
	temp.BITS.BIT46 = right_data.BITS.BIT31;
	temp.BITS.BIT47 = right_data.BITS.BIT32;
	temp.BITS.BIT48 = right_data.BITS.BIT1;
	return temp.Data;
}





inline uint64 XOR(uint64 right_data,uint64 key){
	return right_data ^ key;
}
inline uint32 S_Box(uint64 data){
	data_64bit right_data;
	right_data.Data=data;
	unsigned char _6_bits;
	//S0
	_6_bits = right_data._6_BITS._6_BIT0;
	right_data._4_BITS._4_BIT0 = S1[(_6_bits & (1<<5)) >> 4 |(_6_bits & 1)][(_6_bits & 0x1F)>>1];

	_6_bits = right_data._6_BITS._6_BIT1;
	right_data._4_BITS._4_BIT1 = S2[(_6_bits & (1<<5)) >> 4 |(_6_bits & 1)][(_6_bits & 0x1F)>>1];

	_6_bits = right_data._6_BITS._6_BIT2;
	right_data._4_BITS._4_BIT2 = S3[(_6_bits & (1<<5)) >> 4 |(_6_bits & 1)][(_6_bits & 0x1F)>>1];

	_6_bits = right_data._6_BITS._6_BIT3;
	right_data._4_BITS._4_BIT3 = S4[(_6_bits & (1<<5)) >> 4 |(_6_bits & 1)][(_6_bits & 0x1F)>>1];

	_6_bits = right_data._6_BITS._6_BIT4;
	right_data._4_BITS._4_BIT4 = S5[(_6_bits & (1<<5)) >> 4 |(_6_bits & 1)][(_6_bits & 0x1F)>>1];

	_6_bits = right_data._6_BITS._6_BIT5;
	right_data._4_BITS._4_BIT5 = S6[(_6_bits & (1<<5)) >> 4 |(_6_bits & 1)][(_6_bits & 0x1F)>>1];

	_6_bits = right_data._6_BITS._6_BIT6;
	right_data._4_BITS._4_BIT6 = S7[(_6_bits & (1<<5)) >> 4 |(_6_bits & 1)][(_6_bits & 0x1F)>>1];

	_6_bits = right_data._6_BITS._6_BIT7;
	right_data._4_BITS._4_BIT7 = S8[(_6_bits & (1<<5)) >> 4 |(_6_bits & 1)][(_6_bits & 0x1F)>>1];

	right_data._4_BITS.remainder32 = 0;

	uint32 result = right_data.Data >>32 ;
	return result;
}
inline uint32 permutation(uint32 data){
	data_64bit temp;
	uint64 d = data;

	data_64bit right_data;
	right_data.Data= d<<32;

		temp.Data = 0;

		temp.BITS.BIT1 = right_data.BITS.BIT16;
		temp.BITS.BIT2 = right_data.BITS.BIT7;
		temp.BITS.BIT3 = right_data.BITS.BIT20;
		temp.BITS.BIT4 = right_data.BITS.BIT21;
		temp.BITS.BIT5 = right_data.BITS.BIT29;
		temp.BITS.BIT6 = right_data.BITS.BIT12;
		temp.BITS.BIT7 = right_data.BITS.BIT28;
		temp.BITS.BIT8 = right_data.BITS.BIT17;
		temp.BITS.BIT9 = right_data.BITS.BIT1;
		temp.BITS.BIT10 = right_data.BITS.BIT15;
		temp.BITS.BIT11 = right_data.BITS.BIT23;
		temp.BITS.BIT12 = right_data.BITS.BIT26;
		temp.BITS.BIT13 = right_data.BITS.BIT5;
		temp.BITS.BIT14 = right_data.BITS.BIT18;
		temp.BITS.BIT15 = right_data.BITS.BIT31;
		temp.BITS.BIT16 = right_data.BITS.BIT10;
		temp.BITS.BIT17 = right_data.BITS.BIT2;
		temp.BITS.BIT18 = right_data.BITS.BIT8;
		temp.BITS.BIT19 = right_data.BITS.BIT24;
		temp.BITS.BIT20 = right_data.BITS.BIT14;
		temp.BITS.BIT21 = right_data.BITS.BIT32;
		temp.BITS.BIT22 = right_data.BITS.BIT27;
		temp.BITS.BIT23 = right_data.BITS.BIT3;
		temp.BITS.BIT24 = right_data.BITS.BIT9;
		temp.BITS.BIT25 = right_data.BITS.BIT19;
		temp.BITS.BIT26 = right_data.BITS.BIT13;
		temp.BITS.BIT27 = right_data.BITS.BIT30;
		temp.BITS.BIT28 = right_data.BITS.BIT6;
		temp.BITS.BIT29 = right_data.BITS.BIT22;
		temp.BITS.BIT30 = right_data.BITS.BIT11;
		temp.BITS.BIT31 = right_data.BITS.BIT4;
		temp.BITS.BIT32 = right_data.BITS.BIT25;
		return (temp.Data>>32);

}
inline uint64 Round(uint64 data ,uint64 key_in){
	uint32 left,right;
	uint32 * ptr =(uint32*)&data;
	right=*ptr;
	ptr++;
	left=*ptr;

	uint64 key = key_in;



	uint64 round_right= Expansion(right);

	round_right= XOR(round_right,key);


	uint32 right_result=S_Box(round_right);

	right_result=permutation(right_result);

	uint32 temp=right;
	right=right_result ^ left;
	left= temp;


	uint64 result_data = (left) ;
	result_data = result_data << 32;
	result_data|=right;
	return result_data;
}

