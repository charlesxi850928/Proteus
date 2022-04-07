#include <reg51.h>
int openEXINT0_NUM0();
int openTimerINT0_NUM1();
int openEXINT1_NUM2();
void show16();
void show10();
int count;
int x;
int MODE;
sbit LED_ONE = P1^0;
char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void main(){
	MODE = 0;
	LED_ONE = 1; //LED LIGTH
	openEXINT0_NUM0();
	openTimerINT0_NUM1();
	openEXINT1_NUM2();
	while(1){
		show16();
		show10();
	}
}
void show16(){
	count = 0;
	for(x=0;x<16;x++){
		P2=table[x];
		while(count<20);
		count = 0;
		if(x==16)x=0;
		if(MODE==1)break;
	}
}	
void show10(){
	count = 0;
	for(x=0;x<10;x++){
		P2=table[x];
		while(count<20);
		count = 0;
		if(x==10)x=0;
		if(MODE==0)break;
	}
}	
//INT0
void key1() interrupt 0{
	MODE = ~MODE;
}
//T0
void timer() interrupt 1{
	count++;
	TH0 = 0x3C;
	TL0 = 0xB0;
}
//INT1
void key2() interrupt 2{
	LED_ONE = ~LED_ONE;
}
//T1
//XDINT

int openEXINT0_NUM0(){
	IT0 = 1; //Falling Edge Trigger INT0 externel interrupt
	EX0 = 1; //Allow INT0 externel interrupt
	EA = 1;  //Open Main interrupt
	return 0;
}

int openTimerINT0_NUM1(){
	TMOD = 0x01;
	TH0 = 0x3C;
	TL0 = 0xB0;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
	return 0;
}

int openEXINT1_NUM2(){
	IT1 = 1; //Falling Edge Trigger INT1 externel interrupt
	EX1 = 1; //Allow INT1 externel interrupt
	EA = 1;  //Open Main interrupt
	return 0;
}



