#include<stdio.h> 
#include"crc16.h"
#define improvement 1     //ʹ����ͨ�ļĴ�����λ�㷨���ǸĽ��㷨 
 
static unsigned short crc_send;//����һ��ȫ�ֱ���,���ڴ�ŷ��͵�crcУ���� 
 
void sendMessage(unsigned char *meg,int const length){
	unsigned char *p;
	printf("���ڼ���CRC��...\n");
#if improvement
	crc_send=crc16_ccitt(meg,length);
	//crc_send=crc16_xmodem_improve(meg,length);//�������У������Ҫʵ�ʷ��͵�����֡�ֽ���
#else 
	crc_send=crc16_ccitt(meg,length);
	//crc_send=crc16_xmodem(meg,length);//����У����ֻ��ѭ������֡���ֽ���(��λʱ�Զ���������ĩβ��16��0)
#endif 
 
	printf("���ڷ��ͱ��ģ�");
	for(p=meg;p<&meg[length];printf("%0x\t",*p++));
	printf("%0x\t%0x\012",(unsigned char)(crc_send>>8),(unsigned char)crc_send);
	printf("���ķ�����ϣ�\012\012\012");
}
 
void receiveMessage(unsigned char *meg,int const length){
	unsigned char *p;
	unsigned short crc;
	
	printf("���ڽ��ձ���...");
	printf("\n���Ľ�����ϣ�\n");
	
	printf("����У��CRC��...\n");
#if improvement
	crc=crc16_ccitt(meg,length);
	//crc=crc16_xmodem_improve(meg,length);	
#else 
	crc=crc16_ccitt(meg,length);
	//crc=crc16_xmodem(meg,length);
	
#endif
	if(crc == crc_send)
		printf("OK,���Ľ��ճɹ���\n");
	else 
		printf("ERROR,���Ľ���ʧ�ܣ�\n");
}

/***********
�����������ʵ�֣�
1)��M*x^r��ǰrλ����һ������Ϊr�ļĴ�����
2)����Ĵ�������λΪ1�����Ĵ�������1λ(��Mx^rʣ�²��ֵ�MSB����Ĵ�����LSB)��
�������ɶ���ʽG�ĺ�rλ��򣬷�������Ĵ�������1λ(��Mx^rʣ�²��ֵ�MSB����Ĵ�����LSB)��
3)�ظ���2����ֱ��Mȫ��Mx^r����Ĵ�����
4)�Ĵ����е�ֵ��ΪУ���롣
***********/
 
unsigned short crc16_xmodem(unsigned const char *meg,int const length){
	int i,j;//ѭ������
	unsigned short crc_reg=(meg[0]<<8) + meg[1];//����һ��16λ��CRC�Ĵ�������ʼ��Ϊmeg���ǰ���ֽ� 
	for(i=0;i<length;++i)
		if(i<length-2){            //��i<len-iʱ,�������ֽ�������λ���Ĵ�������� 
			for(j=0;j<8;++j)
				if(crc_reg & 0x8000)          //��crc_reg�����λΪ1ʱ��ִ�еĲ��� 
					crc_reg=((crc_reg<<1) + (meg[i+2]>>7-j & 1)) ^ 0x1021;	//crc_reg����һλ��������ֽڵ������ֽ�λ��crc_reg����䣬�������յ�crc_reg��0x1021��� 
				else
					crc_reg=(crc_reg<<1) + (meg[i+2]>>7-j & 1);
		}
		else{              
			for(j=0;j<8;++j)
				if(crc_reg & 0x8000)          
					crc_reg=(crc_reg<<1) ^ 0x1021;	//��i>=len-iʱ,�Զ����0 
				else
					crc_reg=(crc_reg<<1);
		}				 
	return crc_reg;	
}
 
/***********
CRC16���㷨ԭ��
1.����CRC16�ı�׼ѡ���ֵcrc_ini��ֵ��
2.�����ݵĵ�һ���ֽ�tmp��crc_ini��8λ���
3.�ж����λ������λΪ 0 ����һλ����Ϊ 1 ����һλ�������ɶ���ʽGx���
4.�ظ�3ֱ��8λȫ����λ���������
5.�ظ��������������ݲ���������ϲ��裬����16λ����16λCRCУ���롣
***********/ 
 
unsigned short crc16_xmodem_improve(unsigned const char *meg,int const length){
	int i, j;  
    unsigned short crc_ini=0; 
    unsigned short tmp;   //����һ����ʱ�����������ݵ�ÿ���ֽ� 
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
 
/*��xmode�㷨���ƣ�ֻ�������㷨�������λ��Ϊ��λ��ǰ����λ�ں�*/
 
/*���ϵ������У���Ϣ��ÿ���ֽڶ����ȴ���MSB��CRC16-CCITT��׼ȴ�ǰ����ȴ���LSB����Ϣ
���ƽ��Ĵ���������ġ�ֻ�轫����ĳ��жϼĴ�����LSB����0x1021��λ�ߵ���(0x8408)��
�Ĵ�����򼴿ɣ�������ʾ*/
 
static unsigned short crc16_ccitt(unsigned const char *meg,int const length){
	int i, j;  
    unsigned short crc_ini=0; 
    unsigned short tmp;   //����һ����ʱ�����������ݵ�ÿ���ֽ� 
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
