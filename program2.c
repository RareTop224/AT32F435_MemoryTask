#include <stdio.h>
#include <stdint.h>

extern void (*program2)();
extern void (*program3)();
extern void (*main_func)();

#define RCC_AHB1ENR (*(volatile uint32_t *)(0x40023800UL))

// config gpio for the user button
#define GPIOA_BASE_ADDRESS 0x40020000UL	
#define GPIOA_CFGR (*(volatile uint32_t *)(GPIOA_BASE_ADDRESS + 0x00))		// gpio mode configuration
#define GPIOA_OMODE (*(volatile uint32_t *)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_PUDR (*(volatile uint32_t *)(GPIOA_BASE_ADDRESS + 0x0C)) // pull-up/down
#define GPIOA_IDR (*(volatile uint32_t *)(GPIOA_BASE_ADDRESS + 0x10))		// input data

void entry_program2(){
	printf("Testing transition in program2\n");
	GPIOA_CFGR |= 
	// button PA0 or PC13
	
	while(1){
		printf("Working");
	}
}

void (*program2)() = entry_program2;

