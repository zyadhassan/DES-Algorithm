

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "key.h"


/*******************************************************************************
 *                                Global Variables                             *
 *******************************************************************************/
unsigned char round = 1;
static unsigned int c_left = 0;
static unsigned int c_right = 0;

//unsigned long long   arr[16] ;
//unsigned long long  key_To_encrypt = 0x0123456789ABCDEF;


/*******************************************************************************
 *                                Functions Definition                             *
 *******************************************************************************/

/*
 * Description:
 * Circular shift left rotate of right 28bits
 * if the round numbers 1, 2, 9, or 16 the shift is done by only one position for other rounds,
 *  the circular shift is done by two positions. */
inline unsigned long leftRotate_rightKey(unsigned long long effective_key){
	key_56bit n;
	n.Data = effective_key;
	unsigned char shift;
	unsigned char shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	shift = shifts[c_right];
	c_right++;
	n.Left_Right_BITS.R_BIT= (n.Left_Right_BITS.R_BIT << shift)|(n.Left_Right_BITS.R_BIT >> (28 - shift));
	return n.Left_Right_BITS.R_BIT;
}


/*
 * Description:
 * Circular shift left rotate of left 28bits
 * if the round numbers 1, 2, 9, or 16 the shift is done by only one position for other rounds,
 *  the circular shift is done by two positions. */
inline  unsigned long leftRotate_leftKey(long long effective_key){
	key_56bit n;
	n.Data = effective_key;
	unsigned char shift;
	unsigned char shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

	shift = shifts[c_left];
	c_left++;
	n.Left_Right_BITS.L_BIT= (n.Left_Right_BITS.L_BIT << shift)|(n.Left_Right_BITS.L_BIT >> (28 - shift));
	return n.Left_Right_BITS.L_BIT;
}




/*
 * Description:The permutation (permuted choice 1)discards some bits and transposes the remaining 56 bits
 * input 64 bit
 * output 56 bit
 */

inline unsigned long long Permuted_Choice1(unsigned long long original){
	key_64bit original_data;
	original_data.Data = original;

	key_56bit temp;
	temp.Data = 0;

	temp.BITS.BIT1 = original_data.BITS.BIT57;
	temp.BITS.BIT2 = original_data.BITS.BIT49;
	temp.BITS.BIT3 = original_data.BITS.BIT41;
	temp.BITS.BIT4 = original_data.BITS.BIT33;
	temp.BITS.BIT5 = original_data.BITS.BIT25;
	temp.BITS.BIT6 = original_data.BITS.BIT17;
	temp.BITS.BIT7 = original_data.BITS.BIT9;
	temp.BITS.BIT8 = original_data.BITS.BIT1;
	temp.BITS.BIT9 = original_data.BITS.BIT58;
	temp.BITS.BIT10 = original_data.BITS.BIT50;
	temp.BITS.BIT11 = original_data.BITS.BIT42;
	temp.BITS.BIT12 = original_data.BITS.BIT34;
	temp.BITS.BIT13 = original_data.BITS.BIT26;
	temp.BITS.BIT14 = original_data.BITS.BIT18;
	temp.BITS.BIT15 = original_data.BITS.BIT10;
	temp.BITS.BIT16 = original_data.BITS.BIT2;
	temp.BITS.BIT17 = original_data.BITS.BIT59;
	temp.BITS.BIT18 = original_data.BITS.BIT51;
	temp.BITS.BIT19 = original_data.BITS.BIT43;
	temp.BITS.BIT20 = original_data.BITS.BIT35;
	temp.BITS.BIT21 = original_data.BITS.BIT27;
	temp.BITS.BIT22 = original_data.BITS.BIT19;
	temp.BITS.BIT23 = original_data.BITS.BIT11;
	temp.BITS.BIT24 = original_data.BITS.BIT3;
	temp.BITS.BIT25 = original_data.BITS.BIT60;
	temp.BITS.BIT26 = original_data.BITS.BIT52;
	temp.BITS.BIT27 = original_data.BITS.BIT44;
	temp.BITS.BIT28 = original_data.BITS.BIT36;
	temp.BITS.BIT29 = original_data.BITS.BIT63;
	temp.BITS.BIT30 = original_data.BITS.BIT55;
	temp.BITS.BIT31 = original_data.BITS.BIT47;
	temp.BITS.BIT32 = original_data.BITS.BIT39;
	temp.BITS.BIT33 = original_data.BITS.BIT31;
	temp.BITS.BIT34 = original_data.BITS.BIT23;
	temp.BITS.BIT35 = original_data.BITS.BIT15;
	temp.BITS.BIT36 = original_data.BITS.BIT7;
	temp.BITS.BIT37 = original_data.BITS.BIT62;
	temp.BITS.BIT38 = original_data.BITS.BIT54;
	temp.BITS.BIT39 = original_data.BITS.BIT46;
	temp.BITS.BIT40 = original_data.BITS.BIT38;
	temp.BITS.BIT41 = original_data.BITS.BIT30;
	temp.BITS.BIT42 = original_data.BITS.BIT22;
	temp.BITS.BIT43 = original_data.BITS.BIT14;
	temp.BITS.BIT44 = original_data.BITS.BIT6;
	temp.BITS.BIT45 = original_data.BITS.BIT61;
	temp.BITS.BIT46 = original_data.BITS.BIT53;
	temp.BITS.BIT47 = original_data.BITS.BIT45;
	temp.BITS.BIT48 = original_data.BITS.BIT37;
	temp.BITS.BIT49 = original_data.BITS.BIT29;
	temp.BITS.BIT50 = original_data.BITS.BIT21;
	temp.BITS.BIT51 = original_data.BITS.BIT13;
	temp.BITS.BIT52 = original_data.BITS.BIT5;
	temp.BITS.BIT53 = original_data.BITS.BIT28;
	temp.BITS.BIT54 = original_data.BITS.BIT20;
	temp.BITS.BIT55 = original_data.BITS.BIT12;
	temp.BITS.BIT56 = original_data.BITS.BIT4;

	return temp.Data;
}


/*
 * Description
 *PC-2:Permuted choice 2 selects 48 bits from the 56 bit input
 * input concatenated key (56 bit)
 * output 48 bits
 */
inline unsigned long long Permuted_Choice2(unsigned long long original){
	key_64bit original_data;
	original_data.Data = original;
	key_48bit temp ;
	temp.Data= 0;
	temp.BITS.BIT1 = original_data.BITS.BIT14;
	temp.BITS.BIT2 = original_data.BITS.BIT17;
	temp.BITS.BIT3 = original_data.BITS.BIT11;
	temp.BITS.BIT4 = original_data.BITS.BIT24;
	temp.BITS.BIT5 = original_data.BITS.BIT1;
	temp.BITS.BIT6 = original_data.BITS.BIT5;
	temp.BITS.BIT7 = original_data.BITS.BIT3;
	temp.BITS.BIT8 = original_data.BITS.BIT28;
	temp.BITS.BIT9 = original_data.BITS.BIT15;
	temp.BITS.BIT10 = original_data.BITS.BIT6;
	temp.BITS.BIT11 = original_data.BITS.BIT21;
	temp.BITS.BIT12 = original_data.BITS.BIT10;
	temp.BITS.BIT13 = original_data.BITS.BIT23;
	temp.BITS.BIT14 = original_data.BITS.BIT19;
	temp.BITS.BIT15 = original_data.BITS.BIT12;
	temp.BITS.BIT16 = original_data.BITS.BIT4;
	temp.BITS.BIT17 = original_data.BITS.BIT26;
	temp.BITS.BIT18 = original_data.BITS.BIT8;
	temp.BITS.BIT19 = original_data.BITS.BIT16;
	temp.BITS.BIT20 = original_data.BITS.BIT7;
	temp.BITS.BIT21 = original_data.BITS.BIT27;
	temp.BITS.BIT22 = original_data.BITS.BIT20;
	temp.BITS.BIT23 = original_data.BITS.BIT13;
	temp.BITS.BIT24 = original_data.BITS.BIT2;
	temp.BITS.BIT25 = original_data.BITS.BIT41;
	temp.BITS.BIT26 = original_data.BITS.BIT52;
	temp.BITS.BIT27 = original_data.BITS.BIT31;
	temp.BITS.BIT28 = original_data.BITS.BIT37;
	temp.BITS.BIT29 = original_data.BITS.BIT47;
	temp.BITS.BIT30 = original_data.BITS.BIT55;
	temp.BITS.BIT31 = original_data.BITS.BIT30;
	temp.BITS.BIT32 = original_data.BITS.BIT40;
	temp.BITS.BIT33 = original_data.BITS.BIT51;
	temp.BITS.BIT34 = original_data.BITS.BIT45;
	temp.BITS.BIT35 = original_data.BITS.BIT33;
	temp.BITS.BIT36 = original_data.BITS.BIT48;
	temp.BITS.BIT37 = original_data.BITS.BIT44;
	temp.BITS.BIT38 = original_data.BITS.BIT49;
	temp.BITS.BIT39 = original_data.BITS.BIT39;
	temp.BITS.BIT40 = original_data.BITS.BIT56;
	temp.BITS.BIT41 = original_data.BITS.BIT34;
	temp.BITS.BIT42 = original_data.BITS.BIT53;
	temp.BITS.BIT43 = original_data.BITS.BIT46;
	temp.BITS.BIT44 = original_data.BITS.BIT42;
	temp.BITS.BIT45 = original_data.BITS.BIT50;
	temp.BITS.BIT46 = original_data.BITS.BIT36;
	temp.BITS.BIT47 = original_data.BITS.BIT29;
	temp.BITS.BIT48 = original_data.BITS.BIT32;



	return temp.Data;
}



/*
 * Description:
 *round function controls key generation
 *send effective key to be shift rotated
 *concatenate the key to enter the next round
 */
inline void get_keys(unsigned long long key,unsigned long long * arr){
	 long mask1;
	 long long mask2;
	long long x = Permuted_Choice1(key);
	long right_key = leftRotate_rightKey(x);
	long left_key = leftRotate_leftKey(x);

	long long concat = ((long long)  left_key <<  28) | (right_key) ;
	long long concat_shifted = concat<<8;
	mask1 = right_key;
	mask2 = left_key;
	long long y = Permuted_Choice2(concat_shifted);
	long long round_key = y << 16;
	arr[0]= round_key;
	for(int i = 1; i<16; i++)
	{
		long right_key = leftRotate_rightKey(mask1);
		long left_key = leftRotate_leftKey(mask2 << 28);
		long long concat = ((long long)  left_key <<  28) | (right_key) ;
		long long concat_shifted = concat<<8;
		mask1 = right_key;
		mask2 = left_key;
		long long y = Permuted_Choice2(concat_shifted);
		long long round_key = y << 16;
		arr[i]= round_key;
	}
	c_left=0;
	c_right=0;
}
/*
 * Description:
 *readFile() function read the plain text or the key.txt(hex format)
 *return key as long long (64-bit)
 */
inline void readFile(char* fileName){
	char buffer[150]; // Buffer to store data
	FILE * stream;
	stream = fopen(fileName, "r");
	while(!feof(stream)){
		fgets(buffer,150,stream);
		//puts(buffer);
	}

	//To test the fn to convert from string to hexa for only numbers/
	//printf("%llx ",((long long)buffer[0]-48));
	fclose(stream);

}



inline uint64 strToHexa(char *str)
{
	uint8 i = 0, j = 60;
	uint64 key64 = 0;
	while(str[i] != '\0')
	{
		switch(str[i])
		{
		case '0':
			key64 |= ((uint64_t)0<<j);
			j -= 4;
			break;
		case '1':
			key64 |= ((uint64_t)1<<j);
			j -= 4;
			break;
		case '2':
			key64 |= ((uint64_t)2<<j);
			j -= 4;
			break;
		case '3':
			key64 |= ((uint64_t)3<<j);
			j -= 4;
			break;
		case '4':
			key64 |= ((uint64_t)4<<j);
			j -= 4;
			break;
		case '5':
			key64 |= ((uint64_t)5<<j);
			j -= 4;
			break;
		case '6':
			key64 |= ((uint64_t)6<<j);
			j -= 4;
			break;
		case '7':
			key64 |= ((uint64_t)7<<j);
			j -= 4;
			break;
		case '8':
			key64 |= ((uint64_t)8<<j);
			j -= 4;
			break;
		case '9':
			key64 |= ((uint64_t)9<<j);
			j -= 4;
			break;
		case 'a':
		case 'A':
			key64 |= ((uint64_t)10<<j);
			j -= 4;
			break;
		case 'b':
		case 'B':
			key64 |= ((uint64_t)11<<j);
			j -= 4;
			break;
		case 'c':
		case 'C':
			key64 |= ((uint64_t)12<<j);
			j -= 4;
			break;
		case 'd':
		case 'D':
			key64 |= ((uint64_t)13<<j);
			j -= 4;
			break;
		case 'e':
		case 'E':
			key64 |= ((uint64_t)14<<j);
			j -= 4;
			break;
		case 'f':
		case 'F':
			key64 |= ((uint64_t)15<<j);
			j -= 4;
			break;
		}
		i++;
	}
	return key64;
}
inline uint64 strToAscci(char *string)
{
	uint64 ascci = 0;
	int j = 56;
	for(int i = 0; i<8; i++)
	{
		ascci |= ((uint64)string[i] << j);
		j -= 8;
	}
	return ascci;
}



inline void writeFile(char*ptr){
	FILE * fpointer;
		fpointer = fopen ("test.txt","w");
		fprintf(fpointer,ptr);
		fclose(fpointer);
}



#define UPPER_NUMBER 58
#define LOWER_NUMBER 47
#define DIFFERENCE_NUMBERS 48

#define UPPER_CHARACTER 103
#define LOWER_CHARACTER 96
#define DIFFERENCE_CHARACTERS 87


inline unsigned long long Get_hex(unsigned char ascii)
{
	unsigned long long  n = (unsigned long long) ascii;
	if(n < UPPER_NUMBER && n > LOWER_NUMBER)     //from 0 to 9
	{
		return n - DIFFERENCE_NUMBERS;
	}
	if(n < UPPER_CHARACTER && n > LOWER_CHARACTER)  // from a to f
	{
		return n - DIFFERENCE_CHARACTERS;
	}
	if(n <= 70 && n >= 65)  // from a to f
		{
			return n - 55;
		}
	return n;
}

inline unsigned long long readKey(char* filename)
{
	unsigned char buffer[17];
	FILE *file;
	unsigned long long key=0;
	file = fopen(filename, "r");

	if (fgets(buffer, 17, file) != NULL)
	{
		for(unsigned char i =16;i>0;i--)
		{
			key=key<<4;
			unsigned long long hex=Get_hex(buffer[16-i]);
			key|=hex;

		}

	}
	return key;
}


#if 0
int main (void){
	/* Converting key to HEXA*/
	char str[16] = "0123456789ABCDEF";
	long long d = strToHexa(str);
	printf("%.16" PRIX64 "\n", d);
	/* Converting 8 bytes string to ASCCI*/
	long long ascci = strToAscci("abcdedgh");
	printf("%llx\n", ascci);

	/*******************************************/
	/*unsigned int i ;
	long long *ptr = roundFunc(0x0123456789ABCDEF);
	for(i = 0 ; i <= 15 ; i++){
		printf("The key of round %d is %p\n" , i+1 , arr[i]);
	}
	 */

}

#endif
