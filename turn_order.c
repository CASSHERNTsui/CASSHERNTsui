#include<stdio.h>
#include<arpa/inet.h>

typedef union{
		unsigned short int value;
		unsigned char byte[2];
}to16;


typedef union{
		unsigned long int value;
		unsigned char byte[4];
}to32;

#define BITS16 16
#define BITS32 32

void showvalue(unsigned char *begin,int flag)
{
		int num=0,i=0;
		if(flag == BITS16){
				num = 2;
		}
		else if(flag ==BITS32)
		{
				num =4;
		}
		for(i=0;i<num;i++)
		{
				printf("%x",*(begin+i));
		}
		printf("\n");
}

int main(int argc,char *argv[])
{
		to16 v16_orig,v16_turn1,v16_turn2;
		to32 v32_orig,v32_turn1,v32_turn2;

		v16_orig.value = 0xabcd;
		v16_turn1.value = htons(v16_orig.value);
		v16_turn2.value = htons(v16_turn1.value);

		v32_orig.value=0x12345678;
		v32_turn1.value=htonl(v32_orig.value);
		v32_turn2.value=htonl(v32_turn1.value);

		printf("16 host to network byte order change:\n");
		printf("\torig:\t");showvalue(v16_orig.byte,BITS16);
		printf("\t 1 times:\t");showvalue(v16_turn1.byte,BITS16);
		printf("\t 2 times:\t");showvalue(v16_turn2.byte,BITS16);
		
		printf("32 hosts to network byte order change:\n");
		printf("\torig:\t");showvalue(v32_orig.byte,BITS32);
		printf("\t 1 times:\t");showvalue(v32_turn1.byte,BITS32);
		printf("\t 2 times:\t");showvalue(v32_turn2.byte,BITS32);

		return 0;
}
