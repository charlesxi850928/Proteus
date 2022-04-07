#include <reg51.h>

int table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void main(){
	long k,p;	
	int num;

	while(1){
    //7,4,1,ON/C		
		P1 = 0xEF;
		p = P1;
		if(p!=0xEF){
			//debounce
			k = 2000;
			while(k--);
			p = P1;
			switch(p){
				case 0xEE: num = table[7]; break;
				case 0xED: num = table[4]; break;
				case 0xEB: num = table[1]; break;
				case 0xE7: num = table[10]; break;
			}
		}
		//8,5,2,0
		P1 = 0xDF;
		p = P1;
		if(p!=0xDF){
			//debounce
			k = 2000;
			while(k--);
			p = P1;
			switch(p){
				case 0xDE: num = table[8]; break;
				case 0xDD: num = table[5]; break;
				case 0xDB: num = table[2]; break;
				case 0xD7: num = table[0]; break;
			}
		}
		//9,6,3,=
		P1 = 0xBF;
		p = P1;
		if(p!=0xBF){
			//debounce
			k = 2000;
			while(k--);
			p = P1;
			switch(p){
				case 0xBE: num = table[9]; break;
				case 0xBD: num = table[6]; break;
				case 0xBB: num = table[3]; break;
				case 0xB7: num = table[11]; break;
			}
		}
		//%,X,-,+
		P1 = 0x7F;
		p = P1;
		if(p!=0x7F){
			//debounce
			k = 2000;
			while(k--);
			p = P1;
			switch(p){
				case 0x7E: num = table[12]; break;
				case 0x7D: num = table[13]; break;
				case 0x7B: num = table[14]; break;
				case 0x77: num = table[15]; break;
			}
		}
		
		P3 = 0x7F;
		P2 = num;
	}
	
	  
}



