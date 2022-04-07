#include <reg51.h>
void initUART(){
	//SCON = 0x40;//Way 2, Send
	SCON = 0x50;//Way 1, Receive
	TL1 = 0xFD;
	TH1 = 0xFD;
	TMOD = 0x20;
	TR1 = 1;
	PCON &=0xEF;
	ES = 1;//Enable UART Interrupt;
	EA = 1;//Open main switch
}
void sendStr(char* str){
	int i;
	while(str[i]!='\0'){
		SBUF = str[i];
		while(!TI);//Wait send finish
		//TI = 0;//Clear TI flag
		i++;
	}	
}
int main(){
	initUART();
	P2 = 0x00;
	sendStr("Hello World!");
	
	while(1);
}

void uart(void) interrupt 4{
	unsigned char temp;
	//Digital Code
	unsigned char num[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	//Receive Interruput
	if(RI){
		RI = 0;//Clear Receive Interrupt
		temp = SBUF;
		//'0' - 0x3f
		P2 = num[temp-'0'];
	}
	else{
		TI = 0;//Clear Send Interrupt
	}
}
