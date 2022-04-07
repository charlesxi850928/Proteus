#include <reg51.h>
sbit E = P2^0;
sbit RW = P2^1;
sbit RS = P2^2;
void writeCMD(unsigned char x){
	int i;
	RS=0;//CMD
	RW=0;//Write
	P0=x;//CMD Content
	E=1;//Enable/Start Read/Write Data
	for(i=0;i<2000;i++);//Wait
	E=0;//Colose/End Read/Write Data
}
void initLCD(){
	writeCMD(0x01);
	writeCMD(0x38);
	writeCMD(0x0F);
	writeCMD(0x06);
}
void writeData(unsigned char x){
	int i;
	RS=1;//Data
	RW=0;//Write
	P0=x;//Data Content
	E=1;//Enable/Start Read/Write Data
	for(i=0;i<2000;i++);//Wait
	E=0;//Colose/End Read/Write Data
}
void main(){
	int i;
	char text1[] = {"I'm Chinese!"};
	char text2[] = {"I love China!"};
	//Above 2 lines must be before below initLCD
	initLCD();

	for(i=0;i<12;i++){
		writeCMD(0x81+i);//Position/Address - First Row - See Screenshot
		writeData(text1[i]);
	}	
	for(i=0;i<13;i++){
		writeCMD(0xC1+i);//Position/Address - Second Row - See Screenshot
		writeData(text2[i]);
	}	
	while(1);
}
