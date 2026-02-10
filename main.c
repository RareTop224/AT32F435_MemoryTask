#include <stdio.h>
#include <stdint.h>
#include "system_at32f435_437.h"
#include "at32f435_437_board.h"
#include "at32f435_437_clock.h"

extern void (*program2)();
extern int (*main_func)();

#define RCC_AHB1ENR (*(volatile uint32_t *)(0x40023830))

// config gpio for LED
// #define GPIOD_BASE_ADDRESS 0x4002C30UL	
#define GPIOD_BASE_ADDRESS 0x40020C00UL	
#define GPIOD_CFGR (*(volatile uint32_t *)(GPIOD_BASE_ADDRESS + 0x00))		// gpio mode configuration
#define GPIOD_ODT (*(volatile uint32_t *)(GPIOD_BASE_ADDRESS + 0x14))		// the output status of I/O port.
#define GPIOD_SCR (*(volatile uint32_t *)(GPIOD_BASE_ADDRESS + 0x18))		// gpio set/clear bit

	
// config gpio for the user button
//#define GPIOA_BASE_ADDRESS 0x40023830UL	
#define GPIOA_BASE_ADDRESS 0x4002C30UL	
#define GPIOA_CFGR (*(volatile uint32_t *)(GPIOA_BASE_ADDRESS + 0x00))		// gpio mode configuration
#define GPIOA_PUDR (*(volatile uint32_t *)(GPIOA_BASE_ADDRESS + 0x0C)) // pull-up/down
#define GPIOA_IDR (*(volatile uint32_t *)(GPIOA_BASE_ADDRESS + 0x10))		// input data




void blink_led(void){
	GPIOD_SCR = (1 << 13);
	for (volatile int i=0; i<500000; i++){}
	// delay_ms(500);
		
	GPIOD_SCR = (1 << (13 + 16));
	for (volatile int i=0; i<500000; i++){}
	//delay_ms(500);
}

int main(void){
	//printf("Main program\n");
	
	RCC_AHB1ENR |= (1 << 3);	// enable clocking GPIOD
	RCC_AHB1ENR |= (1 << 0);	// enable clocking GPIOA
	
	GPIOD_CFGR &= ~(3 << (13 * 2));  
	GPIOD_CFGR |= (1 << (13 * 2));	// PD13 output 

	
	while (1){
		blink_led();
		//GPIOD_SCR ^= (1 << 13);
    //for (volatile int i=0; i<500000; i++){}
	}
}

int (*main_func)() = main;