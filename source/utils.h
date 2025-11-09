#ifndef CPARSE_UTILS_H
#define CPARSE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

#include "common.h"


#define FORMAT_STRING(format_text, ...) (__format_string(format_text, __VA_ARGS__))
#define WHITESPACE_RTRIM(str) (__trim_whitespace_right(str))
#define ENDS_WITH(character, str) (__ends_with(character, str))
#define TO_LOWERCASE(str) (__make_lowercased(str))
#define TO_UPPERCASE(str) (__make_uppercase(str))
#define CHAR_IN(character, char_array) (__character_in(character, char_array))
#define CONTAINS_STR(sub_str, str) (__contains_string(sub_str, str))
#define DISPLAY_TARGS(argc, argv) (__display_targs(argc, argv))


// @NOTE: Wrapper function over the 'assert' macro (provided by the 'assert.h'
//		  to allow for adding specific assert/error messages 
#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "Assertion failed: %s, file %s, line %d. Message: %s\n", \
                    #condition, __FILE__, __LINE__, message); \
            assert(0); /* Terminate the program */ \
        } \
    } while (0)


static inline void __trim_whitespace_right(char* str) {
	// @NOTE: trim's whitespace on the right side of a string (in place)
	size_t _str_len = strlen(str);
	while (_str_len > 0 && isspace((unsigned char)str[_str_len - 1])) {
		str[--_str_len] = NULL_CHAR;
	}
}


static inline bool __ends_with(const char character, char* str) {
	for (int i = strlen(str) - 1; i >= 0; --i) {
		if (!isspace((unsigned char)str[i])) {
			return str[i] == character;
		}
	}
	return false;
}


static inline char* __make_lowercased(const char* str) {
	size_t _len = strlen(str);
	char* _lower = malloc(_len + 1);
	if (!_lower) {
		perror("'malloc' failed");
		exit(1);
	}

	for (size_t i = 0; i < _len; i++) {
		_lower[i] = tolower((unsigned char)str[i]);
	}
	_lower[_len] = '\0';
	return _lower;
}


static inline char* __make_uppercase(const char* str) {
	size_t _len = strlen(str);
	char* _lower = malloc(_len + 1);
	if (!_lower) {
		perror("'malloc' failed");
		exit(1);
	}

	for (size_t i = 0; i < _len; i++) {
		_lower[i] = toupper((unsigned char)str[i]);
	}
	_lower[_len] = '\0';
	return _lower;
}


static inline bool __character_in(const char c, const char* char_array) {
	int _input_len = strlen(char_array);
	for (int i = 0; i < _input_len; i++) {
		if (c == char_array[i]) {
			return true;
		}
	}
	return false;
}


static inline bool __contains_string(const char* sub_str, const char* str) {
	if (sub_str == NULL || str == NULL) return false;
	return strstr(str, sub_str) != NULL;
}


static void __display_targs(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
		fflush(stdout);
	}
}


static char* __format_string(const char* format, ...) {
	if (!format) return NULL;
	va_list args;
	va_start(args, format);

	int size = vsnprintf(NULL, 0, format, args);
	va_end(args);

	if (size < 0) return NULL;

	char* buffer = (char*)malloc(size + 1);
	if (!buffer) return NULL;

	va_start(args, format);
	vsnprintf(buffer, size + 1, format, args);
	va_end(args);
	return buffer;
}


#endif
