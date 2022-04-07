#include <reg51.h>
#include <absacc.h>
#define AD XBYTE[0xFEFC]//IN1 -- 1111 1001(F9), IN2 -- 1111 1010(FA), IN3 -- 1111 1011(FB), IN4 -- 1111 1100(FC)
sbit bai = P2^4;
sbit shi = P2^5;
sbit ge = P2^6;
int num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
int x,i;
void main(){
	EA=1;
	EX0=1;
	IT0=1;

	x = 789;
	bai = 1;
	shi = 1;
	ge = 1;
	while(1){
		AD = 0;
		P1 = num[x/100];
		bai = 0;
		i = 50;
		while(i--);
		bai = 1;
		
		P1 = num[x/10%10];
		shi = 0;
		i = 50;
		while(i--);
		shi = 1;
		
		P1 = num[x%10];
		ge = 0;
		i = 50;
		while(i--);
		ge = 1;
	}
}

void ADChange() interrupt 0{
	x = AD;
}

