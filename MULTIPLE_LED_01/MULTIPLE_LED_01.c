#include <reg51.h>
int count;
int main(){
	long i = 10000;
	int x;
	count = 0;
	TMOD = 0x01;
	TH0 = 0x3C;
	TL0 = 0xB0;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
	for(x=0x01;x<=0x80;x=x*2){
		P2=x;
		while(count<20);
		count = 0;
	}
	return 0;
}

void timer() interrupt 1{
	count++;
	TH0 = 0x3C;
	TL0 = 0xB0;
}
