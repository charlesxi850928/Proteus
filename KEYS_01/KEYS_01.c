#include <reg51.h>
sbit key1 = P1^0;
sbit key2 = P1^1;
sbit key3 = P1^2;
sbit key4 = P1^3;
sbit key5 = P1^4;
sbit key6 = P1^5;
sbit key7 = P1^6;
sbit key8 = P1^7;
int table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void main(){
	long i,j,k,p;	
	int num;
	while(1){
		p = P1;
		if(p!=0xFF){
			//debounce
			k = 2000;
			while(k--);
			p = P1;
			switch(p){
				case 0xFE: num = table[1]; break;
				case 0xFD: num = table[2]; break;
				case 0xFB: num = table[3]; break;
				case 0xF7: num = table[4]; break;
				case 0xEF: num = table[5]; break;
				case 0xDF: num = table[6]; break;
				case 0xBF: num = table[7]; break;
				case 0x7F: num = table[8]; break;
			}
		}
		P3 = 0xFE;
		P2 = num;
	}
	
	j = 0;
	k = 1; 
	while(0){
	//while(j<9){
		P3 = 0xff-k;
		P2 = table[j++];
		i = 50;
		while(i--);
		k = k*2;
	}
}



