#include "stdio.h"
#include "string.h"
int i ;
int BIAS6_value1[][2]=
{
  {32,0},{32,2},{33,5},{34,8},{35,11},{36,14},{37,16},{38,19},{39,22},{40,26},{41,29},{42,32},{43,35},{44,39},{45,42},{46,45},{47,49},{48,52},{49,56},{50,60},{51,64},
  {52,68},{53,73},{54,88},{53,92},{52,95},{51,98},{50,99},{49,101},{48,103},{47,104},{46,105},{45,106},{44,107},{43,108},{42,109},{41,110},{40,111},{38,112},{37,113},
  {35,114},{33,115},{31,116},{29,117},{25,118},{7,119},{3,118},{0,117},{0,0}
};
	
int main (void) 
{
	for(i=0;i<60;i++)
	{
		BIAS6_value1[i][0] = BIAS6_value1[i][0] + 61;
		BIAS6_value1[i][1] = BIAS6_value1[i][1] + 43;
		printf("{%X,%X} ",BIAS6_value1[i][0],BIAS6_value1[i][1]); 
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
