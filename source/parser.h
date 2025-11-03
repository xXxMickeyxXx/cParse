#ifndef CPARSE_PARSER_H
#define CPARSE_PARSER_H

#include <stdlib.h>


typedef struct {
	void* input
} cParserInput;


typedef struct {
	void* data
} cParserOutput;


typedef struct {
	const char* parser_id;
	cParserResult _parse_result;
} cParser;


cParser* new_parser(void);


#endif
