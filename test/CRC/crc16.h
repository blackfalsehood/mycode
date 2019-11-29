
#ifndef _CRC16_H_
#define _CRC16_H_
 
void sendMessage(unsigned char *meg,int const length);//���ͱ��ģ�������Ϣ��������Ϣ���ֽ��� 
 
void receiveMessage(unsigned char *meg,int const length);//���ձ��� 
 
static unsigned short crc16_xmodem(unsigned const char *meg,int const length);//����CRC16-XMODEM��׼����У������� 
 
static unsigned short crc16_xmodem_improve(unsigned const char *meg,int const length);//����CRC16-XMODEM��׼����У�������(�㷨��) 
 
static unsigned short crc16_ccitt(unsigned const char *meg,int const length);//����CRC16-CCITT��׼����У�������
 
#endif
