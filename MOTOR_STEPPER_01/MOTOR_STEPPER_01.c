#include <reg51.h>
sbit pos = P1^0;
sbit neg = P1^1;
sbit acc = P1^2;
sbit dec = P1^3;

unsigned int TIME;
unsigned int TIME_START = 0x3CB0; //65536 - 15536 = 1ms
unsigned char code turn[]={0x02,0x06,0x04,0x0c,0x08,0x09,0x01,0x03};

void delay(unsigned int x){
	while(x--);
}

void main(){
	unsigned char a;
	
	P2 = 0x03;
	
	TMOD = 0x01;
	TH0 = TIME_START/0xFF;
	TL0 = TIME_START%0xFF;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	
	while(1){
		if(pos&&neg) TIME = 0;
		if(!pos){
			if(TIME == 2){
				a = a<8?a+1:0;
				P2 = turn[a];
				TIME = 0;
			}
		}
		if(!neg){
			if(TIME == 2){
				a = a>0?a-1:7;
				P2 = turn[a];
				TIME = 0;
			}
		}

		if(acc==0) {
			delay(1000);
			while(!acc);
			if(TIME_START < 0xFFFF - 0x000a * 500){
				TIME=0;
				TIME_START = TIME_START + 0x000a * 500;
			}
		}
		if(dec==0) {
			delay(1000);
			while(!dec);
			if(TIME_START > 0x000a * 500){
				TIME=0;
				TIME_START = TIME_START - 0x000a * 500;
			}
		}
	}
}

void timer() interrupt 1{
	TH0 = TIME_START/0xFF;
	TL0 = TIME_START%0xFF;
	TIME++;
}

