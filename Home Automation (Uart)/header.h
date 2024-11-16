 //LIBRARY FUNCTIONS
#include<LPC21XX.H>
#include<string.h>

//datatype Shortcuts
typedef signed char s8;
typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef signed int s32;
typedef unsigned int u32;

//delay function
extern void delay_sec(u32);
extern void delay_ms(u32);

//4 bit driver

 extern void lcd_init(void);
 extern void lcd_cmd(u8);
 extern void lcd_data(u8);
 extern void lcd_cgram(void);
 extern void lcd_int(int);
 extern void lcd_cgram1(unsigned char *,unsigned char );


 //uart0 driver 
 extern void uart0_init(unsigned int);
 extern	void uart0_tx(unsigned char);
 extern	void uart0_tx_str(char * );
 extern	unsigned char uart0_rx(void);
 extern void uart0_rx_str(char *,char );
 extern void uart0_itoa(int);
 extern void uart0_float(float);

 //uart0 intr
extern  void config_vic_for_eint0(void);
extern  void config_eint0(void);

 //eint0 intr
extern void config_vic_for_uart0(void);
extern void config_uart0(void);

//tmr0 intr
extern void config_vic_for_tmr0(void);
extern void config_tmr0(unsigned int);
