#include <reg51.h>
sbit led = P1^0;
int main(){
	led = 0;
	IT0 = 1; //Falling Edge Trigger INT0 externel interrupt
	EX0 = 1; //Allow INT0 externel interrupt
	EA = 1;  //Open Main interrupt
	while(1);
	return 0;
}

void KEY_EX_INT0() interrupt 0{
	led = ~led;
	IE0 = 0; //Clear INT0
}