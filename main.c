#include <stdio.h>
#include <stdint.h>
#include "system_at32f435_437.h"
#include "at32f435_437_board.h"

#define PERIPH_BASE_ADDRESS  0x40000000UL
#define AHB1_BASE  (PERIPH_BASE_ADDRESS + 0x00020000UL)
#define APB2_BASE   (PERIPH_BASE_ADDRESS + 0x00010000UL)
	
#define RCC_BASE  (AHB1_BASE + 0x3800UL)
#define RCC_AHB1ENR  (*(volatile uint32_t *)(RCC_BASE + 0x30))


// config gpio
#define GPIOD_BASE_ADDRESS (AHB1_BASE + 0x0C00UL)	

#define GPIOD_CFGR (*(volatile uint32_t *)(GPIOD_BASE_ADDRESS + 0x00))		// gpio mode configuration
// #define GPIOD_MODER (*(volatile uint32_t *)(GPIOD_BASE + 0x04))
// #define GPIOD_OSPEEDR (*(volatile uint32_t *)(GPIOD_BASE + 0x08))
// #define GPIOD_PUPDR (*(volatile uint32_t *)(GPIOD_BASE + 0x0C))
#define GPIOD_ODT (*(volatile uint32_t *)(GPIOD_BASE_ADDRESS + 0x14))		// the output status of I/O port.
#define GPIOD_SCR (*(volatile uint32_t *)(GPIOD_BASE_ADDRESS + 0x18))		// gpio set/clear bit
	


int main(){
	RCC_AHB1ENR |= (1 << 3);	// enable clocking for pin D
	
	GPIOD_CFGR &= ~(3 << (13 * 2));  
	GPIOD_CFGR |=  (1 << (13 * 2));	// PD13 output 
	
	// GPIOD_OSPEEDR &= ~(3 << (13 * 2)); 
	// GPIOD_PUPDR &= ~(3 << (13 * 2));
	
	while (1)
	{
		GPIOD_SCR = (1 << 13);
		delay_ms(500);
			
		GPIOD_SCR = (1 << (13 + 16));
		delay_ms(500);
	}
}