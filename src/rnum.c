#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int get_rand(char **argv);

int get_rand(char *argv[])
{
	char *c = argv[1];
	int range = atoi(c);
	if (!range)
		range = RAND_MAX;
	return rand() % range;
}

int main(int argc, char *argv[])
{
	time_t t;
	srand((unsigned) time(&t));
	if (argc > 1)
		return get_rand(argv);
	else
		fprintf(stderr, "%s <LIMIT>\n", argv[0]);
	return 0;
}
