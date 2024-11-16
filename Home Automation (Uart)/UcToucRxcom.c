 #include "header.h"
#define LED1 1<<17
#define LED2 1<<18 
#define SW1  ((IOPIN0>>14)&1)
#define SW2  ((IOPIN0>>15)&1)
#define sw3  ((IOPIN0>>16)&1)



/*
rx--> temp          4321
		 temp= 0000 0000		(Logic for the operation)
		              ||led1
					  |led2
					 mode change
*/	
   u8 tx;
 main(){
	   config_vic_for_eint0();
	   config_eint0();
	   config_vic_for_uart0();
	   config_uart0();

//unsigned char tx;
IODIR0= LED1|LED2;
IOCLR0=	LED1|LED2;

 uart0_init(9600);
 lcd_init();
 //uart0_tx_str("welcom...");
 uart0_tx_str("\r\n MENU:");
 uart0_tx_str("\r\n B1 =>LED 1");
 uart0_tx_str("\r\n B2 =>LED 2");
 uart0_tx_str("\r\n B3 =>LED 1 & LED 2");
 lcd_cmd(0x80);
 lcd_string("welcome...");
  lcd_cmd(0xc0);
 lcd_string("Device started..");
	while(1){
		 if((tx>>7)&1){
		 //------switch---MANUAL MODE

			 if(SW1==0){
			 while(SW1==0);
			 //--- 
			 tx=tx^(1<<0);
			 }

			 if(SW2==0){
			 while(SW2==0);
			 //--- 
			 tx=tx^(1<<1);
			 }



		 }
		
					
					if(((tx)&1) ==1	){	//checking for the 1st bit
						IOCLR0=LED1;
					  //uart0_tx_str("\r\n LED 1:ON");
					}
					else{
						IOSET0=LED1;
					    //uart0_tx_str("\r\n LED 1:OFF");
						}
					
					
					if(((tx>> 1 )&1) ==1){	  //checking for the 2nd bit
						IOCLR0=LED2;
					 // uart0_tx_str("\r\n LED 2:ON");
					 }
					else	 {
						IOSET0=LED2;
					 // uart0_tx_str("\r\n LED 2:OFF");
					 }
		   }
	   }

   
