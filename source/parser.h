#ifndef CPARSE_PARSER_H
#define CPARSE_PARSER_H

#include <stdlib.h>

#include "scanner.h"
#include "tensor.h"


typedef struct {
	void* parser_id;
} cParser;


// @NOTE: parser reification
cParser* __new_cParser__(void* parser_id);
void __init_cParser__(cParser* self, void* parser_id);
void __free_cParser__(cParser* self);


// @NOTE: parser calls/actions/execution units/etc.
void* parse(cParser* self, Token token);
typedef void (*emit)(void* action_id, void* args);


#endif
