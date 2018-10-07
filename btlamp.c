#include<reg51.h>

void delay();

sbit led=P1^0;
sbit motion=P0^0;

void main(){
	
	unsigned int chr;
	TMOD=0x20;	//timer 1 mode 2
	TH1=0xFD;	//9600 baud
	SCON=0x50;	//enable UART
	TR1=1;	//enable timer 1
	while(1){
		if(RI==1){	//wait for reception
			RI=0;
			chr=SBUF;	//received character
		}
			if(chr=='y'){	//if charcter='y'
				led=0;	//LED ON
			}
			else {	//if character='n'
				if(motion==1){
					led=0;
					delay();
				}
				else
					led=1;
			}
	}
	
}

void delay(){
	unsigned int i,j;
	for(i=0; i<1000; i++){
		for(j=0; j<1000; j++);
	}
}