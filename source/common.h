#include <stdio.h>
#include <stdbool.h>


// @NOTE: convenience macros
#define TRUE (true)
#define FALSE (false)
#define NULL_CHAR '\0'


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
