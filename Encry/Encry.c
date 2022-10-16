/*
 * Encry.c
 *
 *  Created on: Oct 15, 2022
 *      Author: user
 */


#include <stdio.h>
#include "Round.h"
#include "Encry.h"

inline uint64 Initial_Permutation(uint64 data){
	data_64bit temp;
	data_64bit original_data;
	original_data.Data = data;
	temp.Data = 0;

	temp.BITS.BIT1 = original_data.BITS.BIT58;
	temp.BITS.BIT2 = original_data.BITS.BIT50;
	temp.BITS.BIT3 = original_data.BITS.BIT42;
	temp.BITS.BIT4 = original_data.BITS.BIT34;
	temp.BITS.BIT5 = original_data.BITS.BIT26;
	temp.BITS.BIT6 = original_data.BITS.BIT18;
	temp.BITS.BIT7 = original_data.BITS.BIT10;
	temp.BITS.BIT8 = original_data.BITS.BIT2;
	temp.BITS.BIT9 = original_data.BITS.BIT60;
	temp.BITS.BIT10 = original_data.BITS.BIT52;
	temp.BITS.BIT11 = original_data.BITS.BIT44;
	temp.BITS.BIT12 = original_data.BITS.BIT36;
	temp.BITS.BIT13 = original_data.BITS.BIT28;
	temp.BITS.BIT14 = original_data.BITS.BIT20;
	temp.BITS.BIT15 = original_data.BITS.BIT12;
	temp.BITS.BIT16 = original_data.BITS.BIT4;
	temp.BITS.BIT17 = original_data.BITS.BIT62;
	temp.BITS.BIT18 = original_data.BITS.BIT54;
	temp.BITS.BIT19 = original_data.BITS.BIT46;
	temp.BITS.BIT20 = original_data.BITS.BIT38;
	temp.BITS.BIT21 = original_data.BITS.BIT30;
	temp.BITS.BIT22 = original_data.BITS.BIT22;
	temp.BITS.BIT23 = original_data.BITS.BIT14;
	temp.BITS.BIT24 = original_data.BITS.BIT6;
	temp.BITS.BIT25 = original_data.BITS.BIT64;
	temp.BITS.BIT26 = original_data.BITS.BIT56;
	temp.BITS.BIT27 = original_data.BITS.BIT48;
	temp.BITS.BIT28 = original_data.BITS.BIT40;
	temp.BITS.BIT29 = original_data.BITS.BIT32;
	temp.BITS.BIT30 = original_data.BITS.BIT24;
	temp.BITS.BIT31 = original_data.BITS.BIT16;
	temp.BITS.BIT32 = original_data.BITS.BIT8;
	temp.BITS.BIT33 = original_data.BITS.BIT57;
	temp.BITS.BIT34 = original_data.BITS.BIT49;
	temp.BITS.BIT35 = original_data.BITS.BIT41;
	temp.BITS.BIT36 = original_data.BITS.BIT33;
	temp.BITS.BIT37 = original_data.BITS.BIT25;
	temp.BITS.BIT38 = original_data.BITS.BIT17;
	temp.BITS.BIT39 = original_data.BITS.BIT9;
	temp.BITS.BIT40 = original_data.BITS.BIT1;
	temp.BITS.BIT41 = original_data.BITS.BIT59;
	temp.BITS.BIT42 = original_data.BITS.BIT51;
	temp.BITS.BIT43 = original_data.BITS.BIT43;
	temp.BITS.BIT44 = original_data.BITS.BIT35;
	temp.BITS.BIT45 = original_data.BITS.BIT27;
	temp.BITS.BIT46 = original_data.BITS.BIT19;
	temp.BITS.BIT47 = original_data.BITS.BIT11;
	temp.BITS.BIT48 = original_data.BITS.BIT3;
	temp.BITS.BIT49 = original_data.BITS.BIT61;
	temp.BITS.BIT50 = original_data.BITS.BIT53;
	temp.BITS.BIT51 = original_data.BITS.BIT45;
	temp.BITS.BIT52 = original_data.BITS.BIT37;
	temp.BITS.BIT53 = original_data.BITS.BIT29;
	temp.BITS.BIT54 = original_data.BITS.BIT21;
	temp.BITS.BIT55 = original_data.BITS.BIT13;
	temp.BITS.BIT56 = original_data.BITS.BIT5;
	temp.BITS.BIT57 = original_data.BITS.BIT63;
	temp.BITS.BIT58 = original_data.BITS.BIT55;
	temp.BITS.BIT59 = original_data.BITS.BIT47;
	temp.BITS.BIT60 = original_data.BITS.BIT39;
	temp.BITS.BIT61 = original_data.BITS.BIT31;
	temp.BITS.BIT62 = original_data.BITS.BIT23;
	temp.BITS.BIT63 = original_data.BITS.BIT15;
	temp.BITS.BIT64 = original_data.BITS.BIT7;

	return temp.Data;
}

inline uint64 Inverse_Permutation(uint64 data){
	data_64bit temp;
	data_64bit original_data;
	original_data.Data = data;
	temp.Data = 0;

	temp.BITS.BIT1 = original_data.BITS.BIT40;
	temp.BITS.BIT2 = original_data.BITS.BIT8;
	temp.BITS.BIT3 = original_data.BITS.BIT48;
	temp.BITS.BIT4 = original_data.BITS.BIT16;
	temp.BITS.BIT5 = original_data.BITS.BIT56;
	temp.BITS.BIT6 = original_data.BITS.BIT24;
	temp.BITS.BIT7 = original_data.BITS.BIT64;
	temp.BITS.BIT8 = original_data.BITS.BIT32;
	temp.BITS.BIT9 = original_data.BITS.BIT39;
	temp.BITS.BIT10 = original_data.BITS.BIT7;
	temp.BITS.BIT11 = original_data.BITS.BIT47;
	temp.BITS.BIT12 = original_data.BITS.BIT15;
	temp.BITS.BIT13 = original_data.BITS.BIT55;
	temp.BITS.BIT14 = original_data.BITS.BIT23;
	temp.BITS.BIT15 = original_data.BITS.BIT63;
	temp.BITS.BIT16 = original_data.BITS.BIT31;
	temp.BITS.BIT17 = original_data.BITS.BIT38;
	temp.BITS.BIT18 = original_data.BITS.BIT6;
	temp.BITS.BIT19 = original_data.BITS.BIT46;
	temp.BITS.BIT20 = original_data.BITS.BIT14;
	temp.BITS.BIT21 = original_data.BITS.BIT54;
	temp.BITS.BIT22 = original_data.BITS.BIT22;
	temp.BITS.BIT23 = original_data.BITS.BIT62;
	temp.BITS.BIT24 = original_data.BITS.BIT30;
	temp.BITS.BIT25 = original_data.BITS.BIT37;
	temp.BITS.BIT26 = original_data.BITS.BIT5;
	temp.BITS.BIT27 = original_data.BITS.BIT45;
	temp.BITS.BIT28 = original_data.BITS.BIT13;
	temp.BITS.BIT29 = original_data.BITS.BIT53;
	temp.BITS.BIT30 = original_data.BITS.BIT21;
	temp.BITS.BIT31 = original_data.BITS.BIT61;
	temp.BITS.BIT32 = original_data.BITS.BIT29;
	temp.BITS.BIT33 = original_data.BITS.BIT36;
	temp.BITS.BIT34 = original_data.BITS.BIT4;
	temp.BITS.BIT35 = original_data.BITS.BIT44;
	temp.BITS.BIT36 = original_data.BITS.BIT12;
	temp.BITS.BIT37 = original_data.BITS.BIT52;
	temp.BITS.BIT38 = original_data.BITS.BIT20;
	temp.BITS.BIT39 = original_data.BITS.BIT60;
	temp.BITS.BIT40 = original_data.BITS.BIT28;
	temp.BITS.BIT41 = original_data.BITS.BIT35;
	temp.BITS.BIT42 = original_data.BITS.BIT3;
	temp.BITS.BIT43 = original_data.BITS.BIT43;
	temp.BITS.BIT44 = original_data.BITS.BIT11;
	temp.BITS.BIT45 = original_data.BITS.BIT51;
	temp.BITS.BIT46 = original_data.BITS.BIT19;
	temp.BITS.BIT47 = original_data.BITS.BIT59;
	temp.BITS.BIT48 = original_data.BITS.BIT27;
	temp.BITS.BIT49 = original_data.BITS.BIT34;
	temp.BITS.BIT50 = original_data.BITS.BIT2;
	temp.BITS.BIT51 = original_data.BITS.BIT42;
	temp.BITS.BIT52 = original_data.BITS.BIT10;
	temp.BITS.BIT53 = original_data.BITS.BIT50;
	temp.BITS.BIT54 = original_data.BITS.BIT18;
	temp.BITS.BIT55 = original_data.BITS.BIT58;
	temp.BITS.BIT56 = original_data.BITS.BIT26;
	temp.BITS.BIT57 = original_data.BITS.BIT33;
	temp.BITS.BIT58 = original_data.BITS.BIT1;
	temp.BITS.BIT59 = original_data.BITS.BIT41;
	temp.BITS.BIT60 = original_data.BITS.BIT9;
	temp.BITS.BIT61 = original_data.BITS.BIT49;
	temp.BITS.BIT62 = original_data.BITS.BIT17;
	temp.BITS.BIT63 = original_data.BITS.BIT57;
	temp.BITS.BIT64 = original_data.BITS.BIT25;

	return temp.Data;
}

inline uint64 Encrypt(uint64 data){
	uint64 plain;
	plain = Initial_Permutation(data);
	//printf("Initial Permutation: %p\n", plain);
	for(char i = 0; i < 16 ; i++){
		plain = Round(plain, i+1);
		//printf("Round number %d data: %p\n",i,plain);
	}

	swap(&plain);
	plain = Inverse_Permutation(plain);
	//printf("Inverse Permutation: %p\n", plain);
	return plain;
}



inline void swap(uint64 *ptr_plain){
	uint32 *ptr_left_data=ptr_plain;
	uint32 *ptr_right_data=ptr_left_data+1;
    uint32 temp = *(ptr_right_data);
	*ptr_right_data = (uint32)(*ptr_left_data);
	*ptr_left_data = temp;
}

inline uint64 Decrypt(uint64 data){
	uint64 plain;
	plain = Initial_Permutation(data);
	//printf("Initial Permutation: %p\n", plain);
	for(char i = 16; i > 0 ; i--){
		plain = Round(plain, i);
		//printf("Round number %d data: %p\n",i,plain);
	}

	swap(&plain);
	plain = Inverse_Permutation(plain);
	//printf("Inverse Permutation: %p\n", plain);
	return plain;
}
