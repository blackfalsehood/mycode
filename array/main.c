#include "stdio.h"
#include "string.h"

int BIAS6_value1[][2]=
{
  {0,117},{3,116},{5,115},{7,114},{9,113},{10,112},{11,111},{12,110},{14,109},{15,108},{16,107},{17,106},{18,105},{19,103},{20,101},{21,98},{22,97},{23,95},{24,93},
  {25,91},{26,89},{27,87},{28,85},{29,82},{30,80},{31,78},{32,76},{33,74},{34,71},{35,69},{36,67},{37,64},{38,62},{39,59},{40,57},{41,55},{42,52},{43,50},{44,47},
  {45,45},{46,42},{47,39},{48,37},{49,34},{50,32},{51,29},{52,26},{53,23},{54,21},{55,18},{56,15},{57,13},{58,10},{59,6},{60,3},{61,0},{0,0}
};

int i;
int main(void)
{
	for(i=0;i<62;i++)
	{
		BIAS6_value1[i][0]=61-BIAS6_value1[i][0];
		BIAS6_value1[i][1]=BIAS6_value1[i][1]+43;
		printf("%X,%X ",BIAS6_value1[i][0],BIAS6_value1[i][1]);
	}
 } 
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
