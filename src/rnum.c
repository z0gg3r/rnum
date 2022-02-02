#ifndef _USE_TIME
#include <time.h>
#else
#include <sys/random.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int get_rand(int range, int base);
void print_usage(char *c);

int get_rand(int range, int base)
{
	return rand() % range + base;
}

void print_usage(char * c)
{
	fprintf(
	stderr,
	"Usage: %s [OPTION]\n Options are:\n -r <VALUE>: The upper limit for the random number\n-l: Return the value instead of printing it\n",
       	c
	);
}

int main(int argc, char *argv[])
{
#ifndef _USE_TIME
	time_t t;
	srand((unsigned) time(&t));
#else
	char *s = malloc(sizeof(char) * 128);
	if ((getrandom(s, 128, 0)) == -1) {
		free(s);

		fprintf(stderr, "getrandom encountered an error\n");
		return 1;
	}

	srand(s);
	free(s);
#endif
#ifndef _ENABLE_LEGACY
	int print = 1;
#else
	int print = 0;
#endif
	int opt = 0;
	int range = 0;
	int range_set = 0;
	int base = 0;
	int base_set = 0;

	while ((opt = getopt(argc, argv, "lr:b:")) != -1) {
		switch (opt) {
			case 'r':
				range = atoi(optarg);
				range_set = 1;
				break;
			case 'l':
				print = 0;
				break;
			case 'b':
				base = atoi(optarg);
				base_set = 1;
				break;
			default:
				print_usage(argv[0]);
				return EXIT_FAILURE;
		}
	}

	if (!range_set) {
		fprintf(stderr, "You have to specify a range!\n");
		print_usage(argv[0]);
		return EXIT_FAILURE;
	}

	if (!range || range > RAND_MAX) {
		fprintf(stderr, "Range must not be zero or greater than RAND_MAX!\n");
		return EXIT_FAILURE;
	}

	if ((base_set && base == -1) || base > range) {
		fprintf(stderr, "Please provide a valid base.\n");
		return EXIT_FAILURE;
	}

	int num = get_rand(range, base);
	if (print) {
		fprintf(stdout, "%d\n", num);
		return EXIT_SUCCESS;
	} else {
		return num;
	}
}
