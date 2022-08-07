#ifdef _USE_TIME
#include <time.h>
#else
#include <sys/random.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

static int ABORT_WAS_ERROR = 1;

typedef struct options_t {
	int range;
	int base;
	int legacy;
} options_t;

int get_rand(int range, int base);
void print_usage(char *c);
options_t *parse(int argc, char **argv);
int *last_arg(int argc, char **argv);

options_t *parse(int argc, char **argv)
{
	options_t *o = calloc(1, sizeof(options_t));

	char *err = "";
	int b_flag = 0;
	int r_flag = 0;
	int l_flag = 0;

	for (int i = 0; i < argc; ++i) {
		if (!strcmp(argv[i], "-b") || !strcmp(argv[i], "--base")) {
			if ((i + 1) < argc) {
				b_flag = 1;
				o->base = atoi(argv[i + 1]);
			} else {
				err = "-b was set, but no value was given!";
				goto abort;
			}
		} else if (!strcmp(argv[i], "-r") || !strcmp(argv[i], "--range")) {
			if ((i + 1) < argc) {
				r_flag = 1;
				o->range = atoi(argv[i + 1]);
			} else {
				err = "-r was set, but no value was given!";
				goto abort;
			}
		} else if (!strcmp(argv[i], "-l") || !strcmp(argv[i], "--legacy")) {
			l_flag = 1;
		} else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
			ABORT_WAS_ERROR = 0;
			goto help;
		}
	}

	o->legacy = l_flag;

	if (b_flag && o->base == -1) {
		err = "Please provide a valid non-zero positive integer.";
		goto abort;
	}

	if (r_flag && o->range == -1) {
		err = "Please provide a valid non-zero positive integer.";
		goto abort;
	}

	int *args  = last_arg(argc, argv);
	if (!b_flag && !r_flag && !args[0]) {
		o->range = atoi(argv[args[1]]);
		if (o->range == -1) {
			err = "Please provide a valid non-zero positive integer";
			free(args);
			goto abort;
		}
	} else if (!b_flag && !r_flag) {
		o->base = atoi(argv[args[1]]);
		o->range = atoi(argv[args[0]]);
		if (o->base == -1 || o->range == -1) {
			err = "Please provide a valid non-zero positive integer.";
			free(args);
			goto abort;
		}
	} else if (b_flag && !r_flag) {
		o->range = atoi(argv[args[1]]);
		if (o->range == -1) {
			err = "Please provide a valid non-zero positive integer.";
			free(args);
			goto abort;
		}
	} else if (!b_flag && r_flag) {
		o->base = atoi(argv[args[1]]);
		if (o->base == -1) {
			err = "Please provide a valid non-zero positive integer.";
			free(args);
			goto abort;
		}
	}

	free(args);
	return o;

abort:
	fprintf(stderr, "%s\n", err);
help:
	free(o);
	return NULL;
}

int *last_arg(int argc, char **argv)
{
	int one = 0;
	int two = 0;
	for (int i = 1; i < argc; ++i) {
		if (!strcmp(argv[i], "-b") || !strcmp(argv[i], "--base")
				|| !strcmp(argv[i], "-r") || !strcmp(argv[i], "--range")) {
			++i;
			continue;
		}

		if (!strcmp(argv[i], "-l") || !strcmp(argv[i], "--legacy"))
			continue;

		one = two;
		two = i;
	}

	int *ret = calloc(2, sizeof(int));
	ret[0] = one;
	ret[1] = two;

	return ret;
}

int get_rand(int range, int base)
{
	return rand() % range + base;
}

void print_usage(char *c)
{
	fprintf(
		stderr,
		"Usage: %s RANGE [BASE] or %s -r RANGE [-b BASE]\n",
		c,
		c
	);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		print_usage(argv[0]);
		return 1;
	}
	options_t *o = parse(argc, argv);
	if (!o) {
		print_usage(argv[0]);
		return ABORT_WAS_ERROR;
	}

	if (o->base > o->range) {
		fprintf(stderr, "Please choose a base <= range!\n");
		free(o);
		return EXIT_FAILURE;
	}

#ifdef _USE_TIME
	time_t t;
	srand((unsigned) time(&t));
#else
	unsigned int buf;
	if ((getrandom(&buf, sizeof(unsigned int), GRND_NONBLOCK)) == -1) {
		free(o);

		fprintf(stderr, "getrandom encountered an error\n");
		return EXIT_FAILURE;
	}

	srand(buf);
#endif

#ifndef _ENABLE_LEGACY
	int print = 1;
#else
	int print = 0;
#endif
	int num = get_rand(o->range, o->base);
	if (print || !o->legacy) {
		fprintf(stdout, "%d\n", num);
		free(o);
		return EXIT_SUCCESS;
	} else {
		free(o);
		return num;
	}
}
