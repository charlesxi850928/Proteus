#include <reg51.h>
#include <absacc.h>
#define DA XBYTE[0xFEFF]
//Below data from Sin.xlsx excel
unsigned char num[100]={127,	135,	143,	151,	159,	166,	174,	181,	188,	195,	202,	208,	214,	220,	225,	230,	234,	238,	242,	245,	248,	250,	252,	253,	254,	254,	254,	253,	252,	250,	248,	245,	242,	238,	234,	230,	225,	220,	214,	208,	202,	195,	188,	181,	174,	166,	159,	151,	143,	135,	127,	119,	111,	103,	95,	88,	80,	73,	66,	59,	52,	46,	40,	34,	29,	24,	20,	16,	12,	9,	6,	4,	2,	1,	0,	0,	0,	1,	2,	4,	6,	9,	12,	16,	20,	24,	29,	34,	40,	46,	52,	59,	66,	73,	80,	88,	95,	103,	111,	119};
int i;
//Triangular waves
void t3(){
	for(i=99;i>=0;i--){
		DA = i;
	}
	for(i=0;i<100;i++){
		DA = i;
	}
}
//Sine waves
void sin(){
	for(i=0;i<100;i++){
		DA = num[i];
	}
}
void main(){
	while(1){
		//t3();
		sin();
	}
}
