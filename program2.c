#include <stdio.h>
#include <stdint.h>

extern void (*program2)();
extern void (*program3)();
extern void (*main_func)();

void entry_program2(){
	printf("Testing transition in program2\n");
	
	while(1){
		printf("Working");
	}
}

void (*program2)() = entry_program2;

