#include <reg51.h>
sbit led = P1^0;
sbit buzzer = P2^0;
void delay(x){
	while(x--);
}
void main(){
	while(1){
		led = 0;
		buzzer = 0;
		delay(50000);
		led = 1;
		buzzer = 1;
		delay(50000);
	}
}