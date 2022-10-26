/*
 * main.c
 *
 *  Created on: Oct 15, 2022
 *      Author: user
 */


#include <stdio.h>
#include <time.h>
#include "./Encry/Round.h"
#include "./Encry/Encry.h"
#include "./key/key.h"
uint64  keys [32];

char* keyfile ;// = "key.txt";
char*  filein ;//=  "encryption.txt";
char mod ;
////
//char*  filein =  "plain_text.txt";
//char mod ='E';
int s;
//#define mod 'E'
int main(int argc,char*argv[]){
	FILE *files;
	for(int i=0;i<argc;i++){printf("%s   %d\n",argv[i],i);}
	filein=argv[1];
	mod=argv[2];
	if (mod=='e' || mod=='E'){
		mod='E';

	}
	else if(mod=='D' || mod=='d'  ){
		mod='D';
		keyfile=argv[5];
	}
	else if(mod=='c' || mod=='C'){
		mod='C';
		keyfile=argv[4];
	}

if(mod=='E' || mod=='C'){
		files = fopen(argv[3], "w");
		fprintf(files, "%s", "");
		fclose(files);

		files = fopen(argv[4], "w");
		fprintf(files, "%s", "");
		fclose(files);
}
if(mod=='D' || mod=='C'){
	if(mod=='D')files = fopen(argv[3], "w");
		if(mod=='C')files = fopen(argv[6], "w");

		fprintf(files, "%s", "");
		fclose(files);
}


	unsigned char buffer[9];
	unsigned long long binary=0;  //data binary
	unsigned long long output_enc_dec=0;  //output from encryption
	FILE *file;
	FILE *filePtr;
	unsigned char buffer2[9];
	/**************************************************KEY_TEXT****************************************************************/

	unsigned long long key = readKey(keyfile);
	//key=0x0E329232EA6D0D73;
	printf("Key: %llx \n",key);
	/**************************************************READING PLAIN_TEXT*********************************************************/



	file = fopen(filein, "r");
	if (file == NULL)
	{
		printf("Error opening file.\n");
	}
	while (!feof(file) && !ferror(file))
	{
//		if(mod=='E') s = 8;
//		if(mod=='D') s = 9;
		int count=0;
		if (fgets(buffer,9, file) != NULL)
		{

			//buffer[8]='\n';
			if (mod==' m'){
			for(int i=0;i<9;i++){

				if(buffer[i] =='\0'){
					count=100;
				}
				count++;
				if(count>=100)buffer[i]=0;
				printf("%x    %d\n",buffer[i],count);
			}}
			if(buffer[8]=='\0')printf("nullllll\n");

			output_enc_dec=0;
			binary=0;
			for(int i=0;i<9;i++)
			{
				buffer2[i]=buffer[8-i];
			}
			for (int i = 0; i < 9; ++i) {
				binary = binary | ((unsigned long long)buffer2[i] << (8 * (i-1)));
			}
		printf("PLAIN TEXT in string: %s  %d\n",buffer,sizeof(buffer));
		printf("PLAIN TEXT in hexa: %llx \n",binary);




			/****************************************ENCRYPTION PROCESS***************************************************************/
if(mod=='E' || mod=='C'){
			output_enc_dec=Encrypt(binary,key);

			printf("\nout: %llx \n",output_enc_dec);

			memcpy(buffer,&output_enc_dec,sizeof (output_enc_dec));


			printf("\nout: %llx \n",buffer);
			for(int i=0;i<9;i++)
			{
				buffer2[i]=buffer[7-i];
			}
			printf("\nout: %llx \n",buffer2);


			uint8* ptr = (uint8*)(&output_enc_dec);
			filePtr = fopen(argv[3], "a");
			for(int i=0;i<8;i++){
			printf( "%x\n", ptr[7-i]);
			fprintf(filePtr, "%c", ptr[7-i]);}

			fclose(filePtr);


			//appending the HEX encryption in the output.hex
			filePtr = fopen(argv[4], "a");
			fprintf(filePtr, "%llx", output_enc_dec);
			fclose(filePtr);

}
			/****************************************DECRYPTION PROCESS***************************************************************/
	if (mod=='D' || mod=='C'){
		uint64 in ;
		if(mod=='D')in=binary;
		else if(mod=='C')in=output_enc_dec;

			printf("%llx\n",binary);
			output_enc_dec=Decrypt(binary,key);

			/*uint64 test2 =Decrypt(test1,key);
			printf("testttttttttttttttttt2222 : %s",test2);*/

			printf("\noutput of Decryption: %llx \n",output_enc_dec);

			memcpy(buffer,&output_enc_dec,sizeof output_enc_dec);

			for(int i=0;i<9;i++)
			{
				buffer2[i]=buffer[7-i];
			}

			uint8* ptrd = (uint8*)(&output_enc_dec);
			filePtr = fopen(argv[3], "a");
			for(int i=0;i<8;i++){
				printf( "%x\n", ptrd[7-i]);
				fprintf(filePtr, "%c", ptrd[7-i]);}

			ptrd[8]='\0';
			printf("%s   %d\n",ptrd,sizeof(buffer2));

			fclose(filePtr);
		}





		}
	}
	fclose(file);


	return 0;
}





