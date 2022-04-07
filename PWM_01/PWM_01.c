#include <reg51.h>
sbit led = P1^0;
void main(){
	int i,j;
	
	//0% LIGHT
	j=1000;
	while(j--){
		led = 0;
		i=100;
		while(i--);
	}
	
	//50% LIGHT
	j=1000;
	while(j--){
		led = 0;
		i=50;
		while(i--);

		led = 1;
		i=50;
		while(i--);
	}
	
	//75% LIGHT
	j=1000;
	while(j--){
		led = 0;
		i=25;
		while(i--);

		led = 1;
		i=75;
		while(i--);
	}
	
	//100% LIGHT
	j=1000;
	while(j--){
		led = 1;
		i=100;
		while(i--);
	}
}
