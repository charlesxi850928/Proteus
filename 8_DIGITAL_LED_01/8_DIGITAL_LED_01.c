#include <reg51.h>

char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void main(){
	long i,j,k;	
	j = 0;
	k = 1; 
	while(j<9){
		P3 = 0xff-k;
		P2 = table[j++];
		i = 50;
		while(i--);
		k = k*2;
	}
}



