#include "stdio.h"
#include "string.h"
#include <stdlib.h>

//int a = 0x0171;
//float b;
//
//void main()
//{
//	b=a/10;
//	printf("%d\n", a);
//	printf("%.1f\n", b);
//	printf("0x%X ", a);
//		
//} 
//***************************************************
//@function：数据处理 
//
//*****************************************************
char temp[] = "01230120011e021c02190317031504130511070f090d0b0c0d0b0f0b110a1409160918081a081d071f0721062306250528052a042c042f0431053304";
char temp1[] ="350438033a033c023e02400143014500470049014b024d044e064f08500a510c510f5111511451165119501b501d501f4f224f244f264f29502b502d";
char temp2[] ="503050324f344f374e394e3b4d3d4c3f4b414a44494548484548454a434c414e3f4f3d513b52395237533553325430542e552e552c55295527552455";
char temp3[] ="22551f551d541b531953175215511350114f0f4e0d4d0b4b094a07480546044503430240023e013c01390137003500320130012e002c002900270025";
char  i,j,a,b;

void deal(char x[])
{
	j = strlen(x);
	//printf("strlen(x)=%d\n",j); 
	for(i =0; i <j ;i=i+2)
	{
		a= x[i];
		b= x[i+1];
		if((a < 0x40) && (b<0x40))
		{
			printf("%c",a);
			printf("%c ",b);
		}
		else if((a > 0x40) && (b<0x40))
		{
			printf("%c",a-0x20);
			printf("%c ",b);
		}
		else if((a < 0x40) && (b>0x40))
		{
			printf("%c",a);
			printf("%c ",b-0x20);
		}
	
//		printf("%02X\n ",a+b);
	}

}

void main(void)
{	
	printf("4D 30 30 31 1A ");
	deal(temp);
	printf("00 00 00 00 00 00 00 00 00 00 2F 2D 53\n");
	
	printf("4D 30 30 31 1B ");
	deal(temp1);
	printf("00 00 00 00 00 00 00 00 00 00 2F 2D 53\n");
	
	printf("4D 30 30 31 1C ");
	deal(temp2);
	printf("00 00 00 00 00 00 00 00 00 00 2F 2D 53\n");
	
	printf("4D 30 30 31 1D ");
	deal(temp3);
	printf("00 00 00 00 00 00 00 00 00 00 2F 2D 53\n");
//	printf("%d ",a+b);
		
} 

//////***************************************************
//////@function：二维数组当参数升级版 
//////
//////*****************************************************
//int i , halflen;
//float len;
//
//int BIAS6_value1[][2]=
//{
//  {32,0},{32,2},{33,5},{34,8},{35,11},{36,14},{37,16},{38,19},{39,22},{40,26},{41,29},{42,32},{43,35},{44,39},{45,42},{46,45},{47,49},{48,52},{49,56},{50,60},{51,64},
//  {52,68},{53,73},{54,88},{53,92},{52,95},{51,98},{50,99},{49,101},{48,103},{47,104},{46,105},{45,106},{44,107},{43,108},{42,109},{41,110},{40,111},{38,112},{37,113},
//  {35,114},{33,115},{31,116},{29,117},{25,118},{7,119},{3,118},{0,117},{0,0}
//};
//int BIAS6_value2[][2]=
//{
//  {0,117},{3,116},{5,115},{7,114},{9,113},{10,112},{11,111},{12,110},{14,109},{15,108},{16,107},{17,106},{18,105},{19,103},{20,101},{21,98},{22,97},{23,95},{24,93},
//  {25,91},{26,89},{27,87},{28,85},{29,82},{30,80},{31,78},{32,76},{33,74},{34,71},{35,69},{36,67},{37,64},{38,62},{39,59},{40,57},{41,55},{42,52},{43,50},{44,47},
//  {45,45},{46,42},{47,39},{48,37},{49,34},{50,32},{51,29},{52,26},{53,23},{54,21},{55,18},{56,15},{57,13},{58,10},{59,6},{60,3},{61,0},{0,0}
//};
//int BIAS6_value3[][2]=
//{
//  {61,0},{61,14},{60,16},{59,18},{58,20},{57,21},{56,22},{55,23},{54,24},{53,25},{52,26},{51,27},{50,28},{48,29},{47,30},{45,31},{44,32},{42,33},{40,34},{38,35},{35,36},
//  {34,37},{30,38},{27,39},{24,40},{20,41},{16,42},{0,43},{0,0}
//};
//int BIAS6_value4[][2]=
//{
//  {0,43},{4,43},{8,42},{10,41},{12,40},{13,39},{14,38},{15,37},{16,36},{17,35},{18,33},{19,32},{20,30},{21,28},{22,26},{23,24},{24,21},{25,18},{26,16},{27,13},{28,10},
//  {29,7},{30,5},{31,2},{32,0},{0,0}
//};
//
//
//
//void Point_Handle(int temp[][2],int size,int j,int k)
//{	
//	printf("size = %d\n",size);
//	for(i=0;i<size;i++)
//	{
//		temp[size-i-1][0] = abs(temp[size-i-1][0] + j);
//		temp[size-i-1][1] = abs(temp[size-i-1][1] + k);
//		printf("%02X %02X ",temp[size-i-1][0],temp[size-i-1][1]); 
//		//printf("%d %d ",temp[size-i-1][0],temp[size-i-1][1]); 
//	}
//}	
//
//int main (void) 
//{
//	printf("\n6号A区\n"); 
//	Point_Handle(BIAS6_value1,(sizeof(BIAS6_value1)/sizeof(int))/2,61,43);
//	printf("\n6号B区\n"); 
//	Point_Handle(BIAS6_value2,(sizeof(BIAS6_value2)/sizeof(int))/2,-61,43);
//	printf("\n6号C区\n"); 
//	Point_Handle(BIAS6_value3,(sizeof(BIAS6_value3)/sizeof(int))/2,-61,-43);
//	printf("\n6号D区\n"); 
//	Point_Handle(BIAS6_value4,(sizeof(BIAS6_value4)/sizeof(int))/2,61,-43);
//	
//}

//int i = 0xFF22;
//char j ;
//int main()
//{
//	j = i;
//	printf("%#X\n",j);	
//} 
////***************************************************
////功能：负数转化为十六进制（利用有符号位和无符号位的关系） 
////
////*****************************************************
//unsigned char i =0xB6;
//signed char j; 
//int k;
//
//int main(void)
//{
//	j=i;
//	k=i;
//	printf("%d\n",j);
//	printf("%d\n",k);
//	printf("%d\n",k+j);
//}
////***************************************************
////功能： 
////
////*****************************************************
//int i,j;
//int array_test[3][2]={0};
//int array_temp[3][2]={0};
//int array_copy[6] = {1,2,3,4,5,6};
//
//
//void print_array (int array_test[3][2])
//{
//	for(i=0;i<3;i++)
//	{
//		for(j=0;j<2;j++)
//		{
//			printf("%d ",array_test[i][j]);
//		}
//	}
//}
//
//int main(void)
//{
//		for(i=0;i<3;i++)
//	{
//		for(j=0;j<2;j++)
//		{
//			printf("%d ",array_temp[i][j]);
//		}
//	}
//	printf("\n");
//	memcpy(array_temp,array_copy,sizeof(int)*6);
//	for(i=0;i<3;i++)
//	{
//		for(j=0;j<2;j++)
//		{
//			printf("%d ",array_temp[i][j]);
//		}
//	}
//	
//	printf("\n");
//	print_array(array_temp);
//	
//	printf("\n");
//	printf("%d",array_temp[2][1]- array_temp[0][0]);
//} 
////***************************************************
////功能：一维数组给二维数组赋值 
////
////*****************************************************
//int main()
//{
//  int i,j,count =0;
//  int a[6]={11,33,22,55,66,44};
//  int b[i][j];
//  for(i=0;i<3;i++)
//	{
//		for(j=0;j<2;j++)
//		{
//			b[i][j] =a[count++];
//			printf("%d ",b[i][j]);
//		}
//	}
//	
//}

////***************************************************
////功能：二维数组当参数 
////
////*****************************************************
//int i,j;
//
//void fun (int array[i][j]) 
//{
//	
//	for(i=0;i<5;i++)
//	{
//		for(j=0;j<2;j++)
//		{
//			printf("i = %d\n",i);
//			printf("%d \n",array[i][j]);
//		}
//	}
//
//}
//int main()
//{
//	
//	int Data[5][2] ={1,2,33,42,5,65,7,83,91,10};
//	fun(Data);
//	return 0;
//}
//***************************************************
//功能：memcpy的用法 
//
//*****************************************************
//int main(void)
//{	
// int i= 0,j=0,k=0;
// int array[5][2]={1,2,3,4,5,6,7,8,9,10} ;
// int array_copy[5][2] = {0};
// int array_flush[10] = {1,2,3,4,5,6,7,8,9,10};
// int *p;
//  
// 
// memcpy(array_copy,array,sizeof(array));
// p=&array_flush[0];
// for(k=0;k<10;k++)
// {
// 	printf{"%d\n",*(p+k)};
// 	
// }
// 
// printf("%d %d \n",sizeof(array),sizeof(array)/sizeof(int)); 
// for( i=0;i<5;i++)
// {
// 	for(j=0;j<2;j++)
//	 {
//	 	printf("%d ",array_copy[i][j]);
//	 }
// 	
// }
//} 
//	int ans = 4;
//	int *pns =&ans;
//	*pns = 5;
//	printf("%d\n",&ans);
//	printf("ans =%d\n",ans); 
	
	
//	int i;
//	int *p = NULL;
//	int array[3] = {1,5,8};
//	int array_copy[3] ={0};
//	
//	p=&array[0];
//	printf("%d\n",*p);
//
//	for( i=0;i<3;i++)
//	{	
//		
//		array_copy[i] = *(p+i);
//		printf("The %d bit is %d\n",i+1,array_copy[i]);
//		
//	}
//	printf("\n");
//	
//	return 0;
//}
