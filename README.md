# NAME

rnum - Random Number Generator

# SYNOPSIS

**rnum** **-r** *max* \[**-l**\] \[**-b** *min*\]

# DESCRIPTION

**rnum** is a small util that generates a \'random\' number up to the
value that is passed to it.

# OPTIONS

**-r *max*** :   sets the ceiling for the number generation

**-b *min*** :   sets the base for the number generation

**-l**  :   return instead of printing to stdout (legacy mode)

# NOTES

**rnum** uses time.h to seed srand and is thus not safe for
cryptographic uses. Per default **rnum** used to return the generated
number, however now that is hidden behind the -l flag or the
\--enable-legacy configure option.

# AUTHOR

zockerfreunde03/z0gg3r 
