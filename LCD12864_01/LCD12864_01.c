#include <reg51.h>
sbit E = P2^0;
sbit RW = P2^1;
sbit RS = P2^2;
sbit CS1 = P2^3;
sbit CS2 = P2^4;
sbit RST = P2^5;
unsigned char code dispx[]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x80,0xC0,0xC0,0xE0,0xE0,0xE0,0xE0,0xF0,0xF0,
0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0xE7,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xCF,0x0F,0x0F,0x07,0x1F,0xFF,
0xFF,0xFF,0xFF,0xFF,0xF8,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,
0xF0,0xF0,0xF8,0xFC,0xFC,0xFE,0xFE,0xFF,0xFE,0xFE,0xFE,0xFC,0x78,0x70,0x00,0x00,
0x38,0xF8,0xF0,0xF0,0xF0,0xC0,0xC0,0x00,0x00,0x60,0xF0,0xF0,0xC0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0xF0,0xF0,
0xF0,0xF0,0xE0,0xF0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFE,0xFE,
0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xE0,0xF0,0xF8,0xFC,
0x3F,0x1F,0x6F,0xE3,0xE3,0xF1,0xF8,0xF8,0xFD,0xFD,0xFF,0xFF,0xFE,0xFE,0x7E,0x3E,
0x3C,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0x7E,0x3E,0x1E,0x3E,0x9E,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0x78,0x30,0x80,0xC0,
0xE0,0xFF,0xFF,0xFF,0xFF,0x7F,0xBF,0xFE,0xFE,0xFE,0xFD,0xFB,0xF7,0xD7,0xFE,0xFE,
0xFE,0xFE,0xBE,0x3E,0x3C,0xFC,0xF0,0xE0,0xE6,0xA6,0x0F,0x3F,0x9F,0x9F,0x9F,0x1F,
0x1F,0x8F,0x87,0x03,0x03,0xFC,0xFC,0xF8,0xF0,0x40,0x00,0x80,0x80,0xE9,0xFF,0xFF,
0xFF,0xFC,0xBE,0xFE,0xDE,0xFF,0xEF,0xF7,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0x00,0x00,
0x00,0x00,0xC0,0xC0,0xC0,0x00,0xC0,0xE0,0xF8,0xFC,0xFF,0x3F,0x1F,0x07,0x03,0x02,
0x00,0x00,0xC0,0xC0,0xC0,0xFB,0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x7E,0xBE,0xFE,
0xDC,0xDC,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0xFC,0xFF,0xFF,0x7F,0xC7,0xCF,
0xE7,0xF7,0xF3,0xFD,0x3C,0x3E,0x1F,0x3F,0xFF,0xFF,0xF1,0xCE,0xDE,0xDE,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x67,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFC,0xFE,0xFE,0x7F,0x3F,0x7F,0xFF,0xFF,0xFE,0x7E,0xFF,0xFF,0xFF,0x3E,
0xFE,0xFF,0xFF,0xFE,0xF0,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xBF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xCF,0xC7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,
0x30,0xFE,0xFF,0xFF,0xFD,0x7F,0x7F,0x0F,0x07,0x05,0x00,0x00,0x00,0x00,0x00,0x60,
0xF0,0xF0,0xF3,0xFB,0xFF,0xFB,0xFB,0xFD,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x3F,0x3F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1C,0x00,0x1F,0x7F,0x7F,0x7F,0x7F,0x7F,0x1F,
0x0F,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x1F,0xFF,0xFF,0xFF,0xF7,0xEF,
0x8F,0x0F,0x03,0x03,0x00,0x01,0x03,0x07,0x07,0x0F,0x00,0x00,0x00,0x01,0x01,0x07,
0x07,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x7F,0x7F,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0x02,0x03,0x1F,0x7F,0x7F,0x7F,0xFF,0xFF,0x7F,0x7F,0x1F,
0x1F,0x1F,0x07,0x1F,0x3F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x1F,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x01,0x01,0x01,0x03,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0F,0x1F,0x1F,
0x1F,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,
0x83,0x03,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFE,0xFE,0x36,0x7E,0x7F,0xD7,
0xFF,0x7E,0x9F,0x9A,0x18,0x10,0x00,0x00,0x04,0x04,0x04,0x04,0x06,0x06,0x06,0x02,
0xFF,0xFF,0x76,0xF8,0xDE,0xCE,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1C,0x0F,0x03,0x01,0x1F,0x1F,0x01,0x7F,
0x7F,0x09,0x1F,0x1F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0x0F,0x1E,0x18,0x38,0x30,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
void writeCMD(unsigned char x){
	int i;
	RS=0;//CMD
	RW=0;//Write
	P0=x;//CMD Content
	E=1;//Enable/Start Read/Write Data
	for(i=0;i<20;i++);//Wait
	E=0;//Colose/End Read/Write Data
}
void initLCD(){
	writeCMD(0x3F);//Open Display
	writeCMD(0xC0);//Set Initial Row
	writeCMD(0xB8);//Set X Coordinate
	writeCMD(0x40);//Set Y Coordinate
}
void writeData(unsigned char x){
	int i;
	RS=1;//Data
	RW=0;//Write
	P0=x;//Data Content
	E=1;//Enable/Start Read/Write Data
	for(i=0;i<20;i++);//Wait
	E=0;//Close/End Read/Write Data
}
void main(){
	int x,y,k;
	RST = 0;
	RST = 1;
	initLCD();
	//Only 8 rows data
	for(k=0,x=0;x<8;x++){
		//Left 64 points
		CS1 = 0;
		CS2 = 1;
		writeCMD(0xB8+x);
		for(y=0;y<64;y++){
			writeData(dispx[k++]);
		}
		//Right 64 points
		CS1 = 1;
		CS2 = 0;
		writeCMD(0xB8+x);
		for(y=0;y<64;y++){
			writeData(dispx[k++]);
		}
	}
	while(1);
}