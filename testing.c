//jfr
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	printf("%x\n", (unsigned int) atoi(argv[1]));
	printf("%d bytes big", sizeof(int));
	//printf("%c", argv[1][0]);
}
