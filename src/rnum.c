#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int get_rand(char **argv);

int get_rand(char*argv[])
{
	char *c = argv[1];
	int range = atoi(c);
	if (!range)
		range = RAND_MAX;
	return rand() % range;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	if (argc > 1)
		return get_rand(argv);
	else
		fprintf(stderr, "rnum <LIMIT>\n");
	return 0;
}
