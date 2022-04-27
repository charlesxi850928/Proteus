#include"reg51.h"			 

typedef unsigned char u8;
typedef unsigned int u16;

sbit dj=P2^0;
sbit k1=P1^0;
sbit k2=P1^1;
sbit k3=P1^2;
sbit k4=P1^3;
sbit smgwei1=P3^0;
sbit smgwei2=P3^1;

u16 T1_H,T1_L,T0_H,T0_L;
u8 a,fr;

u8 code smgduan[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
                     0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
   
void delay(u16 i){	
	while(i--);	 
}
     
void init(){  	
	TMOD=0X01;
	EA=1;
	ET0=1;
}

void display(){
	P0=smgduan[a/10];smgwei1=0; smgwei2=1;delay(100);P0=0X00;	
	P0=smgduan[a%10];smgwei1=1; smgwei2=0;delay(100);P0=0X00;	
}

void key(){	
	 if(k1==0) {delay(1000);while(!k1);TR0=1;a=50;}
	 if(k2==0) {delay(1000);while(!k2);TR0=0;dj=0;a=0;}
	 if(k3==0) {delay(1000);while(!k3);a=(a==100)?100:(a+10);}
	 if(k4==0) {delay(1000);while(!k4);a=(a==0)?0:(a-10);}
}

void time0 ()interrupt 1{
dj=~dj;
if(dj==1) { TH0=T1_H;TL0=T1_L; }
if(dj==0) { TH0=T0_H;TL0=T0_L; }
}

void chuzhi(){	
	T0_H=(65535-10000/fr+a*100/fr)/256;
	T0_L=(65535-10000/fr+a*100/fr)%256; 

	T1_H=(65535-a*100/fr)/256;
	T1_L=(65535-a*100/fr)%256; 	 
}

main(){
	dj=0;fr=5;
 	init();
	while(1)
	{ 
		chuzhi();
		key(); 
		display();
	}		
}
