#include <stdio.h>
#include <stdint.h>
#include "system_at32f435_437.h"
#include "at32f435_437_board.h"
#include "at32f435_437_clock.h"

extern void (*program2)();
extern int (*main_func)();

typedef struct {
	volatile uint32_t CFGR;		// gpio mode configuration
	volatile uint32_t ODT;	// the output status of I/O port.
	volatile uint32_t IDT;	// input data
	volatile uint32_t PULL;		// pull-up/down
	volatile uint32_t SCR;		// gpio set/clear bit
} GPIO_TypeDef;


#define RCC_AHB1ENR 	(*(volatile uint32_t *)(0x40023830))

#define PERIHP_BASE 	0x40000000

#define GPIOD_BASE_ADDRESS 	(PERIPH_BASE + 0x00000400)	// port D
#define GPIOA_BASE_ADDRESS 	(PERIPH_BASE + 0x00000C00) 	// port A

#define LED ((GPIO_TypeDef *) GPIOD_BASE_ADDRESS)
#define button ((GPIO_TypeDef *) GPIOD_BASE_ADDRESS)


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
	
	LED->CFGR &= ~(3 << (13 * 2)); 
	LED->CFGR |= (1 << (13 * 2));	// PD13 output 
	
	while (1){
		blink_led();
	}
}

int (*main_func)() = main;
