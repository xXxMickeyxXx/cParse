#include <stdio.h>

#include "parser.h"
#include "../utils/common.h"
#include "../utils/utils.h"


cParser* __new_cParser__(void* parser_id) {
	cParser* _new_parser = (cParser*)malloc(sizeof(cParser));
	__init_cParser__(_new_parser, parser_id);
	ASSERT(_new_parser != NULL, "Error allocating new 'cParser'...");
	return _new_parser;
}


void __init_cParser__(cParser* self, void* parser_id) {
	self->parser_id = parser_id;
}


void __free_cParser__(cParser* self) {
	free(self);
}
