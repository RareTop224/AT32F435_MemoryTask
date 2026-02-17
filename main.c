#include <stdio.h>
#include <stdint.h>
#include "system_at32f435_437.h"
#include "at32f435_437_board.h"
#include "at32f435_437_clock.h"

extern void (*program2)();
extern int (*main_func)();

typedef struct {
	volatile uint32_t CFGR;		// gpio mode configuration
	volatile uint32_t OMODER;
	volatile uint32_t ODRVR;
	volatile uint32_t PULL;		// pull-up/down
	volatile uint32_t IDT;	// input data
	volatile uint32_t ODT;	// the output status of I/O port
	volatile uint32_t SCR;		// gpio set/clear bit
} GPIO_TypeDef;

typedef struct{
	volatile uint32_t USART_STS;
	volatile uint32_t USART_DT;
	volatile uint32_t USART_BAUDR;
	volatile uint32_t USART_CTRL1;	// 0x0C
	volatile uint32_t USART_CTRL2;
	volatile uint32_t USART_CTRL3;
	volatile uint32_t USART_GTP;
} USART_TypeDef;

#define RCC_AHB1ENR 	(*(volatile uint32_t *)(0x40023830))
#define RCC_APB2ENR		(*(volatile uint32_t *)(0x40010044))

#define PERIPHERY_BASE 	0x40000000

#define GPIOD_BASE_ADDRESS 	(PERIPHERY_BASE + 0x00020C00)	// port D
#define GPIOA_BASE_ADDRESS 	(PERIPHERY_BASE + 0x00020000) 	// port A
#define USART_ADDRESS (PERIPHERY_BASE  + 0x00011000)

#define LED ((GPIO_TypeDef *) GPIOD_BASE_ADDRESS)
#define button ((GPIO_TypeDef *) GPIOD_BASE_ADDRESS)
#define usart_print ((USART_TypeDef *) USART_ADDRESS)

void blink_led(void){
	
	LED->SCR = (1 << 13);
	for (volatile int i=0; i<5000; i++){}
	//delay_ms(500);
		
	LED->SCR  = (1 << (13 + 16));
	for (volatile int i=0; i<5000; i++){}
	//delay_ms(500);
}

int main(void){
	//printf("Main program\n");
	RCC_AHB1ENR |= (1 << 3);	// enable clocking GPIOD
	RCC_AHB1ENR |= (1 << 0);	// enable clocking GPIOA
	RCC_APB2ENR |= (1 << 4);	// enalbe clocking USART1
	
	usart_print->USART_CTRL1 |= (1 << 4);		// enable T
	usart_print->USART_CTRL1 |= (1 << 3); 	// enable R
	usart_print->USART_CTRL1  |= (1 << 13);	// enable USART
	
	LED->CFGR &= ~(3 << (13 * 2)); 
	LED->CFGR |= (1 << (13 * 2));	// PD13 output 
	
	while (1){
		blink_led();
	}
}

int (*main_func)() = main;
