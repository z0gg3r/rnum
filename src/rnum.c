#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int get_rand(int range);
void print_usage(char *c);

int get_rand(int range)
{
	return rand() % range;
}

void print_usage(char * c)
{
	fprintf(
	stderr,
	"Usage: %s [OPTION]\n Options are:\n -r <VALUE>: The upper limit for the random number\n-p: Print to stdout\n",
       	c
	);
}

int main(int argc, char *argv[])
{
	time_t t;
	srand((unsigned) time(&t));
	int print = 0;
	int opt = 0;
	int range = 0;
	int range_set = 0;

	while ((opt = getopt(argc, argv, "pr:")) != -1) {
		switch (opt) {
			case 'r':
				range = atoi(optarg);
				range_set = 1;
				break;
			case 'p':
				print = 1;
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

	int num = get_rand(range);
	
	if (print) {
		fprintf(stdout, "%d\n", num);
		return EXIT_SUCCESS;
	} else {
		return num;
	}
}
