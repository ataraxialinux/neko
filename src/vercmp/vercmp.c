#include <stdio.h>
#include <stdlib.h>
#include <dewey.h>

int main(int argc, char **argv) {
	if (argc != 3) {
			printf("It can handle only 2 arguments\n");
			return 1;
	}
	exit(xbps_cmpver(argv[1], argv[2]));
}
