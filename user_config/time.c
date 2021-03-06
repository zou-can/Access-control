#include "time.h"

time_t g_time;

/* 10毫秒@12.000MHz */
static void Timer1Init(void)
{
	AUXR &= 0xBF;		//定时器时钟12T模式
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0x00;		//设置定时初值
	TH1 = 0xDC;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
}

/* 50毫秒@11.0592MHz */
static void Timer0Init(void)
{
	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x00;		//设置定时初值
	TH0 = 0x4C;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 0;		//定时器0开始计时
}

void TimerInit()
{
	Timer0Init();
// 	Timer1Init();
}

void time0() interrupt 1 	
{
  	static u8 t0_count = 0;
	
	TH0 = 0x4C;//定时50ms
	TL0 = 0x00;
	
	t0_count++;	
    if(t0_count % 2  == 0) g_time.time_100ms = 1;
    if(t0_count % 4  == 0) g_time.time_200ms = 1;
    if(t0_count % 10 == 0) {
        g_time.time_500ms = 1;
    }
	if(t0_count >= 20) {
		t0_count = 0;
        g_time.time_1000ms = 1;
	}
} 

void time1() interrupt 3
{
	TL0 = 0x00;		//设置定时初值
	TH0 = 0x4C;		//设置定时初值
}