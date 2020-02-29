#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "rnum.h"

int get_rand(char *_range)
{
	int range = atoi(_range);
	return _get_rand() % range;
}

int _get_rand()
{
	time_t t;
	srand((unsigned) time(&t));
	return rand();
}

flags_t parse(int argc, char *argv[])
{
	flags_t flags = {
		.range = 0,
		.help = 0,
		._stdout = 0,
		.r_index = -1,
	};

	if(argc == 1)
		return flags;
	for(int i = 0; i < argc; ++i) {
		if(cmp(argv[i],  RANGE_SHORT) || cmp(argv[i], RANGE_LONG)) {
			printf("range\n");
			flags.range = 1;
			flags.r_index = i;
		} else if(cmp(argv[i], HELP_SHORT) || cmp(argv[i], HELP_LONG)) {
			printf("help\n");
			flags.help = 1;
		} else if(cmp(argv[i], STDOUT_SHORT) || cmp(argv[i], STDOUT_LONG)) {
			printf("stdout\n");
			flags._stdout = 1;
		}
	}
	return flags;
}

void help()
{
	for(int i = 0; i < USAGE_MAX; ++i)
		printf("%s\n", USAGE[i]);
}

int cmp(char *a, char *b)
{
	int c = strcmp(a, b);
	printf("%s && %s = %d\n", a, b, c);
	return strcmp(a, b) == 0;
}

int main(int argc, char *argv[])
{
	printf("%s && %s = %d\n", argv[1], RANGE_SHORT, cmp(argv[1], RANGE_SHORT));

	flags_t flags = parse(argc, argv);

	if(flags.help)
		help();
	else if(flags.range && flags._stdout)
		printf("%d\n", get_rand(argv[flags.r_index]));
	else if(flags.range)
		return get_rand(argv[flags.r_index]);
	else if(flags._stdout)
		printf("%d\n", _get_rand());
	else
		return _get_rand();
	
	return OKAY;
}
