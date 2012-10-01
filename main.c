#include "stc.h"
#include <stdio.h>

int delay;


void putchar(char c) {
	ES=0;
	TI=0;
	SBUF=c;
	while (!TI);;
	TI=0;
	ES=1;
	
}

void uart_init() {
	/* PCON? */
	SCON=0xC0;
	BRT=0xF3;
	TH0=0x3F;
	TL0=0x1a;
	TMOD=0x28;
	//SMOD=1;
	
	

	TR1=1;
	ES=1;
	EA=1;
}

void rxisr(void) __interrupt 4 {

}

int main()
{
	while(1)
	{
		P0M0=0xff;
		P0=0xf0;
		delay=0xffff;
		while(delay--);;
		P0M0=0xff;
		P0=0x0f;
		delay=0xffff;
		while(delay--);;
		printf("Hello, world\n");
	}
}

