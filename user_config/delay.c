
/*************	����˵��	**************

���ļ�ΪSTC15xxxϵ�еĶ˿ڳ�ʼ������,�û��������Բ��޸��������.


******************************************/

#include	"delay.h"



//========================================================================
// ����: void  delay_ms
// ����: ��ʱ������
// ����: ms,Ҫ��ʱ��ms��, ����ֻ֧��1~65536ms. �Զ���Ӧ��ʱ��.
// ����: none.
// �汾: VER1.0
// ����: 2013-4-1
// ��ע: 
//========================================================================
void delay_ms(u16 ms)
{
   u16 i;
	 do{
	    i = (u16)(MAIN_Fosc / 13000);
		  while(--i)	;   //14T per loop
     }while(--ms);
}


void delay_100us()		//@11.0592MHz
{
	unsigned char i, j;

	i = 2;
	j = 15;
	do
	{
		while (--j);
	} while (--i);
}