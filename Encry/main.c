

#include <stdio.h>
#include <time.h>
#include "Round.h"
#include "Encry.h"

int main(void){
	//clock_t begin =clock();
	printf("Encryption: \n");
	uint64 data1 = Encrypt(0x123456789ABCDEF);
	//printf("%p\n", data1);
	printf("\nDecryption: \n");
	data1 = Decrypt(data1);
	//clock_t end = clock();
	//double time =(double)(end-begin)/CLOCKS_PER_SEC;
	//printf("%p\n", data1);
	//printf("%f\n", time);


	return 0;
}
