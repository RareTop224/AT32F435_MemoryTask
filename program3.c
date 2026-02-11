#include <stdio.h>
#include <stdint.h>

extern void (*program2)();
extern void (*program3)();

void entry_program3(){
	printf("Testing transition in program3\n");
	
	while(1){
		printf("Working");
	}
}

void (*program3)() = entry_program3;	