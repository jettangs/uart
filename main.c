

#include "reg51.H"

void UartInit(void)		//9600bps@11.0592MHz
{
	TMOD=0x20;
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	REN=1;
	SM0=0;
	SM1=1;
	REN=1;
	EA=1;
	ES=1;
}

void SendChar(unsigned char Char)
{	
	SBUF=Char;
	while(!TI);
	TI=0;
}

void  SendString(unsigned char *p)
{
	while(*p)
	{
		SendChar(*p);
		p++;
	}
}

void main()
{
UartInit();
SendString("finish!");
while(1);
}