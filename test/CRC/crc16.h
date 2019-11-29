
#ifndef _CRC16_H_
#define _CRC16_H_
 
void sendMessage(unsigned char *meg,int const length);//发送报文，报文信息，报文信息总字节数 
 
void receiveMessage(unsigned char *meg,int const length);//接收报文 
 
static unsigned short crc16_xmodem(unsigned const char *meg,int const length);//采用CRC16-XMODEM标准进行校验码计算 
 
static unsigned short crc16_xmodem_improve(unsigned const char *meg,int const length);//采用CRC16-XMODEM标准进行校验码计算(算法改) 
 
static unsigned short crc16_ccitt(unsigned const char *meg,int const length);//采用CRC16-CCITT标准进行校验码计算
 
#endif
