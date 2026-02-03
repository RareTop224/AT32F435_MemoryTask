#include <stdio.h>
#include <stdint.h>

#define PERIPH_BASE  0x40000000UL
#define AHB1_BASE   (PERIPH_BASE + 0x00020000UL)
#define APB2_BASE   (PERIPH_BASE + 0x00010000UL)


#define RCC_BASE  (AHB1_BASE + 0x3800UL)
#define RCC_AHB1ENR  (*(volatile uint32_t *)(RCC_BASE + 0x30))

#define GPIOD_BASE  (AHB1_BASE + 0x0C00UL)

#define GPIOD_MODER  (*(volatile uint32_t *)(GPIOD_BASE + 0x00))
#define GPIOD_OTYPER    (*(volatile uint32_t *)(GPIOD_BASE + 0x04))
#define GPIOD_OSPEEDR   (*(volatile uint32_t *)(GPIOD_BASE + 0x08))
#define GPIOD_PUPDR     (*(volatile uint32_t *)(GPIOD_BASE + 0x0C))
#define GPIOD_ODR       (*(volatile uint32_t *)(GPIOD_BASE + 0x14))
#define GPIOD_BSRR   (*(volatile uint32_t *)(GPIOD_BASE + 0x18))

int main(){
	RCC_AHB1ENR |= (1 << 3);
	
	GPIOD_MODER &= ~(3 << (13 * 2));   
  GPIOD_MODER |=  (1 << (13 * 2));   

	GPIOD_OTYPER &= ~(1 << 13);

	GPIOD_OSPEEDR &= ~(3 << (13 * 2));

	GPIOD_PUPDR &= ~(3 << (13 * 2));
	
	while (1)
  {
		GPIOD_BSRR = (1 << 13);
		for (int i=0; i<500000; i++){}
			
		GPIOD_BSRR = (1 << (13 + 16));
		for (int i=0; i<500000; i++){}
  }
}