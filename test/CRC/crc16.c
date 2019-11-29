#include<stdio.h> 
#include"crc16.h"
#define improvement 1     //使用普通的寄存器移位算法还是改进算法 
 
static unsigned short crc_send;//定义一个全局变量,用于存放发送的crc校验码 
 
void sendMessage(unsigned char *meg,int const length){
	unsigned char *p;
	printf("正在计算CRC码...\n");
#if improvement
	crc_send=crc16_ccitt(meg,length);
	//crc_send=crc16_xmodem_improve(meg,length);//这里计算校验码需要实际发送的数据帧字节数
#else 
	crc_send=crc16_ccitt(meg,length);
	//crc_send=crc16_xmodem(meg,length);//计算校验码只需循环数据帧的字节数(移位时自动在数据码末尾补16个0)
#endif 
 
	printf("正在发送报文：");
	for(p=meg;p<&meg[length];printf("%0x\t",*p++));
	printf("%0x\t%0x\012",(unsigned char)(crc_send>>8),(unsigned char)crc_send);
	printf("报文发送完毕！\012\012\012");
}
 
void receiveMessage(unsigned char *meg,int const length){
	unsigned char *p;
	unsigned short crc;
	
	printf("正在接收报文...");
	printf("\n报文接收完毕！\n");
	
	printf("正在校验CRC码...\n");
#if improvement
	crc=crc16_ccitt(meg,length);
	//crc=crc16_xmodem_improve(meg,length);	
#else 
	crc=crc16_ccitt(meg,length);
	//crc=crc16_xmodem(meg,length);
	
#endif
	if(crc == crc_send)
		printf("OK,报文接收成功！\n");
	else 
		printf("ERROR,报文接收失败！\n");
}

/***********
程序可以如下实现：
1)将M*x^r的前r位放入一个长度为r的寄存器；
2)如果寄存器的首位为1，将寄存器左移1位(将Mx^r剩下部分的MSB移入寄存器的LSB)，
再与生成多项式G的后r位异或，否则仅将寄存器左移1位(将Mx^r剩下部分的MSB移入寄存器的LSB)；
3)重复第2步，直到M全部Mx^r移入寄存器；
4)寄存器中的值则为校验码。
***********/
 
unsigned short crc16_xmodem(unsigned const char *meg,int const length){
	int i,j;//循环变量
	unsigned short crc_reg=(meg[0]<<8) + meg[1];//定义一个16位的CRC寄存器并初始化为meg码的前两字节 
	for(i=0;i<length;++i)
		if(i<length-2){            //当i<len-i时,需下下字节向左移位往寄存器中填充 
			for(j=0;j<8;++j)
				if(crc_reg & 0x8000)          //当crc_reg的最高位为1时所执行的操作 
					crc_reg=((crc_reg<<1) + (meg[i+2]>>7-j & 1)) ^ 0x1021;	//crc_reg左移一位，并与此字节的下下字节位往crc_reg中填充，并将最终的crc_reg与0x1021异或 
				else
					crc_reg=(crc_reg<<1) + (meg[i+2]>>7-j & 1);
		}
		else{              
			for(j=0;j<8;++j)
				if(crc_reg & 0x8000)          
					crc_reg=(crc_reg<<1) ^ 0x1021;	//当i>=len-i时,自动填充0 
				else
					crc_reg=(crc_reg<<1);
		}				 
	return crc_reg;	
}
 
/***********
CRC16的算法原理：
1.根据CRC16的标准选择初值crc_ini的值。
2.将数据的第一个字节tmp与crc_ini高8位异或。
3.判断最高位，若该位为 0 左移一位，若为 1 左移一位再与生成多项式Gx异或。
4.重复3直至8位全部移位计算结束。
5.重复将所有输入数据操作完成以上步骤，所得16位数即16位CRC校验码。
***********/ 
 
unsigned short crc16_xmodem_improve(unsigned const char *meg,int const length){
	int i, j;  
    unsigned short crc_ini=0; 
    unsigned short tmp;   //定义一个临时变量存入数据的每个字节 
    for (i=0;i<length;++i){
        tmp=meg[i]<<8;
        for (j=0;j<8;++j){
            if ((crc_ini ^ tmp) & 0x8000)
                crc_ini=(crc_ini<<1) ^ 0x1021;
            else
                crc_ini<<=1;
            tmp<<=1;           
        }
    }
    return crc_ini;	
}
 
/*与xmode算法类似，只不过该算法针对数据位序为低位在前，高位在后*/
 
/*以上的讨论中，消息的每个字节都是先传输MSB，CRC16-CCITT标准却是按照先传输LSB，消息
右移进寄存器来计算的。只需将代码改成判断寄存器的LSB，将0x1021按位颠倒后(0x8408)与
寄存器异或即可，如下所示*/
 
static unsigned short crc16_ccitt(unsigned const char *meg,int const length){
	int i, j;  
    unsigned short crc_ini=0; 
    unsigned short tmp;   //定义一个临时变量存入数据的每个字节 
    for (i=0;i<length;++i){
        tmp=meg[i];
        for (j=0;j<8;++j){
            if ((crc_ini ^ tmp) & 0x0008)
                crc_ini=(crc_ini>>1) ^ 0x8408;
            else
                crc_ini>>=1;
            tmp>>=1;           
        }
    }
    return crc_ini;
}
