#include "header.h"
#define sw1 ((IOPIN0 >> 14 )&1)
#define sw2 ((IOPIN0 >> 15 )&1)
#define sw3 ((IOPIN0 >> 16 )&1)
#define LED1 1<<17
#define LED2 1<<18 



 //tx to bluetooth
//tx	

main(){
 u8 tx=7,flag=1;
 uart0_init(9600);
 lcd_init();

  uart0_tx_str("welcom...");
 while(1){

  if(sw1==0){
  while(sw1==0);
    tx^=1;
  uart0_tx(tx);
  }


  if(sw2==0){
  while(sw2==0);
  tx= tx^(1<<1);
   uart0_tx(tx);
  } 


  if(sw3==0){
  while(sw3==0);
  flag^=1;
  if(flag)
  tx= tx|7;
  else
  tx= tx&0;
   uart0_tx(tx);


  }
  


 
 }
   }
