#ifndef CPARSE_SCANNER_H
#define CPARSE_SCANNER_H

#include <stdlib.h>

#include "../utils/common.h"
#include "../utils/utils.h"


#define TOKEN(type, data) (__create_token__(type, data));


typedef enum {
	EMPTY
} TokenType;


typedef struct {
	TokenType token_type;
} Token;


Token* __create_token__(TokenType type, void* data);


#endif
