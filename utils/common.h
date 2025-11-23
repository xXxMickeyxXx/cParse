#include <stdio.h>
#include <stdbool.h>


// @NOTE: convenience macros; defining them via 'ifndef' directive to ensure
//		  they haven't been defined before, in case different 3rd party code
//		  does so. Solution isn't foolproof since the 'TRUE' and/or 'FALSE'
//		  macros may not be defined the same as they are intended to be, between
//		  code sources
#ifndef TRUE
	#define TRUE (true)
#endif

#ifndef FALSE
	#define FALSE (false)
#endif

#ifndef NULL_CHAR
	#define NULL_CHAR ('\0')
#endif


// @NOTE: convenience macros for outputting to terminal
#define PRINT(text) printf("%s\n", text); \
	fflush(stdout)
#define APPLY_COLOR(offset, text) ("\033[38;5;" #offset "m" text "\033[0m")
#define UNDERLINE_TEXT(text) ("\x1B[4m" text "\x1B[0m")
#define BOLD_TEXT(text) ("\x1B[1m" text "\x1B[0m")
#define COLOR_PRINT(offset, text) printf("%s", APPLY_COLOR(offset, text)); \
	fflush(stdout)
#define PRINT_NEWLINE printf("\n"); \
	fflush(stdout)
#define FLUSH_STDOUT (fflush(stdout))
#define NOT_IMPLEMENTED(name, file) printf("\n"); \
	printf("\033[38;5;9m'%s'- NotImplemented Error ('%s')\n\033[0m", name, file); \
	printf("\n")
#define VALID printf("\n"); \
	printf(APPLY_COLOR(10, "VALID")); \
	printf("\n")
#define INVALID printf("\n"); \
	printf(APPLY_COLOR(9, "INVALID")); \
	printf("\n")
