 #include<LPC21xx.H>
 #include"header.h"
 #define sw3  ((IOPIN0>>16)&1)

 extern u8 tx;
 			//---FOR SWITCHING BT-TO-MAN
 void EINT0_handler(void) __irq{
	   tx=tx^(1<<7);
	   EXTINT=1;
	   VICVectAddr=0;
	   }

 void config_vic_for_eint0(void){
     VICIntSelect=0;
	 VICVectCntl0=14|(1<<5);
	 VICVectAddr0=(u32)EINT0_handler;
	 VICIntEnable=(1<<14);
	 }

void config_eint0(void){
	PINSEL1|=1;
	EXTMODE=1;
	EXTPOLAR=0;
}
