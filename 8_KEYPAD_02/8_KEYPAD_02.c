#include <reg51.h>
int readKey();
int table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void main(){
	int i,j,t,show[8];
	for(i=0;i<8;i++)show[i] = 0x00;
	while(1){
		int kv = readKey();
		if(kv != 0xFF){
			for(i=0;i<7;i++)show[i] = show[i+1];
			show[7] = table[kv];
			kv = 0xFF;
		}
		j = 0;
		t = 1;
		while(j < 9){
			P3 = 0xFF - t;
			P2 = show[j++];
			i = 150;
			while(i--);
			t = t * 2;
		}
	}
}

int readKey(){
	  int keyValue = 0xFF;
	  int debounce = 3000;
		long k,p;	
    //7,4,1,ON/C		
		P1 = 0xEF;
		p = P1;
		if(p!=0xEF){
			//debounce
			k = debounce;
			while(k--);
			p = P1;
			switch(p){
				case 0xEE: keyValue = 7; break;
				case 0xED: keyValue = 4; break;
				case 0xEB: keyValue =  1; break;
				case 0xE7: keyValue =  10; break;
			}
		}
		//8,5,2,0
		P1 = 0xDF;
		p = P1;
		if(p!=0xDF){
			//debounce
			k = debounce;
			while(k--);
			p = P1;
			switch(p){
				case 0xDE: keyValue =  8; break;
				case 0xDD: keyValue =  5; break;
				case 0xDB: keyValue =  2; break;
				case 0xD7: keyValue =  0; break;
			}
		}
		//9,6,3,=
		P1 = 0xBF;
		p = P1;
		if(p!=0xBF){
			//debounce
			k = debounce;
			while(k--);
			p = P1;
			switch(p){
				case 0xBE: keyValue =  9; break;
				case 0xBD: keyValue =  6; break;
				case 0xBB: keyValue =  3; break;
				case 0xB7: keyValue =  11; break;
			}
		}
		//%,X,-,+
		P1 = 0x7F;
		p = P1;
		if(p!=0x7F){
			//debounce
			k = debounce;
			while(k--);
			p = P1;
			switch(p){
				case 0x7E: keyValue =  12; break;
				case 0x7D: keyValue =  13; break;
				case 0x7B: keyValue =  14; break;
				case 0x77: keyValue =  15; break;
			}
		}
		return keyValue;
}


