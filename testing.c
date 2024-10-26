//jfr
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	printf("%x\n", (unsigned int) atoi(argv[1]));
	printf("%x\n", (unsigned int) atoi(argv[2]));
	printf("%d | %x\n", atoi(argv[1])-atoi(argv[2]));
	int num1, num2;
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	int diff;
	diff = num1 - num2;
	int mask = (diff >> (sizeof(int)*8 - 1)) & 1;
	printf("MASK: %d | %x\n", mask);
	printf("MAX RESULT: %d | %x\n", num1 - mask * diff);
	printf("%d bytes big\n", sizeof(int));
	//printf("%c", argv[1][0]);
}
