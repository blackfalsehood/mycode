#ifndef __CRC_H
#define __CRC_H

#include <stdio.h>

unsigned short CRC16_MODBUS(unsigned char *puchMsg, unsigned int usDataLen);
void InvertUint32(unsigned int *dBuf,unsigned int *srcBuf);
void InvertUint16(unsigned short *dBuf,unsigned short *srcBuf);
void InvertUint8(unsigned char *dBuf,unsigned char *srcBuf);

#endif