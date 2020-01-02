#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef unsigned  int uint32_t;
typedef unsigned  char uint8_t;
typedef struct 
{
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
}RTC_TimeTypeDef;

//@brief  Unix时间戳转北京时间
//@param  带入时间戳值
//---------------------------------------
RTC_TimeTypeDef unixTimeStamp_to_beijingTime(uint32_t time)
{
	time_t t_unix;				//时间撮
	struct tm *lt;
	RTC_TimeTypeDef t_location;	//本地时间
	t_unix=time+28800;			//Unix时间＋8小时为北京时间
	lt=localtime(&t_unix);
	t_location.year=lt->tm_year-100;
	t_location.month=lt->tm_mon+1;
	t_location.day=lt->tm_mday;
	t_location.hour =lt->tm_hour;
	t_location.minute=lt->tm_min;
	t_location.second=lt->tm_sec;
	return t_location;
}

//@brief  北京时间转Unix时间戳
//@param  返回时间戳
//---------------------------------------
uint32_t beijingTime_to_unixTimeStamp(RTC_TimeTypeDef t_location)
{
	time_t t_unix;//时间撮
	struct tm tmCurrentTime;
	tmCurrentTime.tm_year=t_location.year+2000-1900;
	tmCurrentTime.tm_mon=t_location.month-1;
	tmCurrentTime.tm_mday=t_location.day;
	tmCurrentTime.tm_hour=t_location.hour;
	tmCurrentTime.tm_min=t_location.minute;
	tmCurrentTime.tm_sec=t_location.second;
	t_unix = mktime(&tmCurrentTime);
	return (uint32_t)(t_unix-28800);
}

//@brief  UTC时间转化成北京时间，北京时间=UTC+8
//@param  
//---------------------------------------
RTC_TimeTypeDef utcSwitchLocal(RTC_TimeTypeDef temp_utc)
{
	RTC_TimeTypeDef temp_rtc;
	time_t t_unix;			//时间撮
	t_unix=beijingTime_to_unixTimeStamp(temp_utc);
	t_unix+=8*60*60;		//时间撮加上八个小时
	temp_rtc=unixTimeStamp_to_beijingTime(t_unix);
	return temp_rtc;
}

int main()
{
	RTC_TimeTypeDef tempTime;
	uint32_t tempUnixTime=1550832441;
	tempTime=unixTimeStamp_to_beijingTime(tempUnixTime);
	printf("unix timestamp=%d beijingTime=%d/%d/%d %d:%d:%d\r\n",tempUnixTime,tempTime.year,tempTime.month,tempTime.day,tempTime.hour,tempTime.minute,tempTime.second);
	tempTime.year=19;
	tempTime.month=2;
	tempTime.day=22;
	tempTime.hour=19;
	tempTime.minute=8;
	tempTime.second=10;
	printf("unix time=%d/%d/%d %d:%d:%d ",tempTime.year,tempTime.month,tempTime.day,tempTime.hour,tempTime.minute,tempTime.second);
	tempTime=utcSwitchLocal(tempTime);
	printf("beijingTime=%d/%d/%d %d:%d:%d\r\n",tempTime.year,tempTime.month,tempTime.day,tempTime.hour,tempTime.minute,tempTime.second);
	system("pause"); 
	return 0;
}
