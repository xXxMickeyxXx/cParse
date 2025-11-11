#include "../source/parser.h"
// #include "../source/utils.h"
// #include "../source/common.h"


// @NOTE: macros for handling the lifetime of 'cParser' instance
#define NEW_cParser(parser_id) (__new_cParser__((void*)(parser_id)))
#define FREE_cParser(self) (__free_cParser__((self)))

// @NOTE: conveinance macros for 'cParser'
#define cParser_ID(self) ((self)->parser_id)
