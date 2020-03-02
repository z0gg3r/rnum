r(andom)num(ber)
================

### because looking for a program that does this is too damn hard™

rnum is a simple call to stdlibs rand() with srand initialised using
time.h\'s time function and time\_t type.

takes three arguments:

-	-h \| \--help : print help message and quit
-	-r \<num\> \| \--range \<num\> : generate number up to \--num
- 	-so \| \--to-stdout : print number to stdout via printf
-	-i \<num> \| \--iter \<num> : generate \--num numbers
