#include<stdio.h>
#include<stdlib.h>
#include"crc16.h"
 
int main(int argc, char **argv) {
	unsigned char meg[4]={0xB5,0x12,0xA3,0x49};
	sendMessage(meg,sizeof(meg));
	receiveMessage(meg,sizeof(meg));
	return EXIT_SUCCESS;
}
