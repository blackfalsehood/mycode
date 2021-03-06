#include "crc.h"
#include <stdio.h>

int main(int argc, char* argv[])
{	
    //char buffer[22] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x01, 0x02, 0x03, 0x04};
    char buffer[22] = {0x4D,0x30,0x30,0x31,0x0A,0x04,0x0C,0x23,0x23,0x02,0x84,0x03,0x32,0x00,0x00,0x53} ;
	crcInit();
	width_t crc = crcCompute(buffer, 13);
	//unsigned short crc = CalCrc(0, buffer, 20);//计算得到的16位CRC校验码
    buffer[14] = (char)crc;//取校验码的低八位
    buffer[13] = (char)(crc >> 8);//取校验码的高八位
    printf("%2X,%2X\n",buffer[14],buffer[13]);
//接收方在接收到buffer中的数据时，代入CalCrc进行计算，若result的值为0，则说明数据传输过程无误
//    width_t result = crcCompute(buffer, 15);
//	//unsigned short result = CalCrc(0, buffer, 22);
//	if (result == 0){
//		printf("crc result is right\n");
//	}
    return 0;
}

