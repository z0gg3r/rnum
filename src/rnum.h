#ifndef RNUM_H
#define RNUM_H

#define FAIL 1
#define OKAY 0

#define USAGE_MAX 4

typedef struct flags_t {
	int range;
	int help;
	int _stdout;
	int iter;

	// Flag indexes
	int r_index;
	int i_index;
} flags_t;

static char *RANGE_SHORT = "-r";
static char *RANGE_LONG = "--range";

static char *HELP_SHORT = "-h";
static char *HELP_LONG = "--help";

static char *STDOUT_SHORT = "-so";
static char *STDOUT_LONG = "--to-stdout";

static char *REPEAT_SHORT = "-i";
static char *REPEAT_LONG = "--iter";

const static char *USAGE[USAGE_MAX] = {
	"-r or --range: set the max value the generated number can be", 
	"-so or --to-stdout: print the generated number to stdout instead of returning it",
	"-h or --help: print this",
	"-i or --iter: do n times (implies -so)"
					};

int get_rand(char *);
flags_t parse(int, char *[]);
void help();
int _get_rand();
int cmp(char *, char *);
void rand_iter(char *, char *);

#endif
