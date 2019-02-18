#include <stdio.h>
#include <stdint.h>

int getopc(uint16_t IR) {
	int result = IR & ~(~0U >> 4) >> 12;
	printf("%d",result);
}

int main(void) {
	uint16_t RAM[1<<12] = {0};
	getopc(RAM[32]);
}

