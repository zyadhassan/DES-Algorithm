/*
 * key.h
 *
 *  Created on: Oct 16, 2022
 *      Author: nada
 */

#ifndef KEY_H_
#define KEY_H_

/*******************************************************************************
 *                               Union 64 bit access                           *
 *******************************************************************************/
typedef unsigned long long uint64 ;
typedef unsigned char uint8 ;

typedef union
{
	unsigned long long Data; //8 Byte
	struct
	{
		unsigned long long R_BIT:28; //first 28-bit (least)
		unsigned long long L_BIT:28; // second 28-bit (most)

	}Left_Right_BITS;
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
}key_64bit; //to access bit by bit




/*******************************************************************************
 *                               Union 56 bit access                           *
 *******************************************************************************/
typedef union
{
	unsigned long long Data; //8 Byte

	struct{
		unsigned long long BITS_56:56;
	}acces_56;

	struct{
		unsigned long long BITS_48:48;
	}acces_48;

	struct
	{
		unsigned long long R_BIT:28; //first 28-bit (least)
		unsigned long long L_BIT:28; // second 28-bit (most)

	}Left_Right_BITS;

	struct
	{
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
}key_56bit;




/*******************************************************************************
 *                               Union 48 bit access                           *
 *******************************************************************************/
typedef union
{
	unsigned long long Data; //8 Byte
	struct{
		unsigned long long BITS_48:48;
	}acces_48;

	struct
	{
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
}key_48bit;



/*******************************************************************************
 *                                Functions Prototypes                             *
 *******************************************************************************/


/*
 * Description:
 * Circular shift left rotate of right 28bits
 * if the round numbers 1, 2, 9, or 16 the shift is done by only one position for other rounds,
 *  the circular shift is done by two positions. */
extern inline unsigned long leftRotate_rightKey(unsigned long long effective_key);


/*
 * Description:
 * Circular shift left rotate of left 28bits
 * if the round numbers 1, 2, 9, or 16 the shift is done by only one position for other rounds,
 *  the circular shift is done by two positions. */
extern inline unsigned long leftRotate_leftKey(long long effective_key);


/*
 * Description:The permutation (permuted choice 1)discards some bits and transposes the remaining 56 bits
 * input 64 bit
 * output 56 bit
 */
extern inline unsigned long long Permuted_Choice1(unsigned long long original);




/*
 * Description
 *PC-2:Permuted choice 2 selects 48 bits from the 56 bit input
 * input concatenated key (56 bit)
 * output 48 bits
*/
extern inline unsigned long long Permuted_Choice2(unsigned long long original);


/*
 * Description:
 *round function controls key generation
 *send effective key to be shift rotated
 *concatenate the key to enter the next round
*/
extern inline void  get_keys(unsigned long long key,unsigned long long * arr);


/*
 * Description:
 *readFile() function read the plain text or the key.txt(hex format)
 *return key as long long (64-bit)
 */
extern inline void readFile(char* fileName );

extern inline uint64 strToHexa(char *str);
extern inline uint64 strToAscci(char *string);
extern inline  void writeFile(char*ptr);

extern inline unsigned long long Get_hex(unsigned char ascii);
extern inline unsigned long long readKey(char*);

#endif /* KEY_H_ */
