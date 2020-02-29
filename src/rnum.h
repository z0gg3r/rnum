#ifndef RNUM_H
#define RNUM_H

#define FAIL 1
#define OKAY 0

#define USAGE_MAX 3

typedef struct flags_t {
	int range;
	int help;
	int _stdout;

	// Flag indexes
	int r_index;
} flags_t;

const static char *RANGE_SHORT = "-r";
const static char *RANGE_LONG = "--range";

const static char *HELP_SHORT = "-h";
const static char *HELP_LONG = "--help";

const static char *STDOUT_SHORT = "-so";
const static char *STDOUT_LONG = "--to-stdout";

const static char *USAGE[USAGE_MAX] = {
					"-r or --range: set the max value the generated number can be", 
					"-so or --to-stdout: print the generated number to stdout instead of returning it",
					"-h or --help: print this"
					};

int get_rand(char *);
flags_t parse(int, char *[]);
void help();
int _get_rand();

#endif
