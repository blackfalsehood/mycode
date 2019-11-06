#include "crc.h"
#include <stdio.h>

int main(int argc, char* argv[])
{	
    char buffer[22] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x01, 0x02, 0x03, 0x04};
	crcInit();
	width_t crc = crcCompute(buffer, 20);
	//unsigned short crc = CalCrc(0, buffer, 20);//����õ���16λCRCУ����
    buffer[21] = (char)crc;//ȡУ����ĵͰ�λ
    buffer[20] = (char)(crc >> 8);//ȡУ����ĸ߰�λ
//���շ��ڽ��յ�buffer�е�����ʱ������CalCrc���м��㣬��result��ֵΪ0����˵�����ݴ����������
    width_t result = crcCompute(buffer, 22);
	//unsigned short result = CalCrc(0, buffer, 22);
	if (result == 0){
		printf("crc result is right\n");
	}
    return 0;
}

