# NAME

rnum - Random Number Generator

# SYNOPSIS

**rnum** **RANGE** \[**BASE**\] \[**-r** *max*\] \[**-l**\] \[**-b**
*min*\]

# DESCRIPTION

**rnum** is a small util that generates a \'random\' number up to the
value that is passed to it.

# OPTIONS

**-r, \--range *max***

:   sets the ceiling for the number generation

**-b, \--base *min***

:   sets the base for the number generation

**-l, \--legacy**

:   return instead of printing to stdout (legacy mode)

# NOTES

Per default **rnum** used to return the generated number, however now
that is hidden behind the -l flag.

# AUTHOR

zocker
