#include <stdio.h>
#include <stdint.h>
#include "at32f435_437_board.h"
#include "at32f435_437_clock.h"

extern void (*program2)();
extern void (*main_func)();

#define RCC_AHB1ENR (*(volatile uint32_t *)(0x40023800UL))	// clock port C

// config gpio for the user button
#define GPIOC_BASE_ADDRESS 0x40020000UL	
#define GPIOC_CFGR (*(volatile uint32_t *)(GPIOC_BASE_ADDRESS + 0x00))		// gpio mode configuration
#define GPIOC_OMODE (*(volatile uint32_t *)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_ODT (*(volatile uint32_t *)(GPIOC_BASE_ADDRESS + 0x14))		//status
#define GPIOC_PUDR (*(volatile uint32_t *)(GPIOC_BASE_ADDRESS + 0x0C)) // pull-up/down
#define GPIOC_IDR (*(volatile uint32_t *)(GPIOC_BASE_ADDRESS + 0x10))		// input data


void entry_program3(){
	printf("Testing transition in program3\n");
	
	while(1){
		printf("Working");
		uint16_t timer = 0;
		
		if (((GPIOC_ODT & (1 << 13)) == 0)){
			while (((GPIOC_ODT & (1 << 13)) == 0)){
				timer++;
				delay_ms(1);
			}
			
			if(timer >= 1500){
				// entry program3
				program2();
			}
			else {
				// entry main
				main_func();
			}
		}
	}
}

void (*program3)() = entry_program3;	