#ifndef CPARSE_PARSER_H
#define CPARSE_PARSER_H

#include <stdlib.h>


// typedef struct {

// } Cursor;


typedef struct {
	void* node_id;
} Node;


typedef struct {
	size_t capacity;
	size_t count;
	Node* nodes;
} NodeArray;


typedef struct {
	void* graph_id;
	NodeArray nodes;	
} Graph;


// typedef struct {
// 	void* input
// } cParserInput;


// typedef struct {
// 	void* data;
// } cParserOutput;


typedef struct {
	void* parser_id;
} cParser;


cParser* __new_cParser__(void* parser_id);
void __init_cParser__(cParser* self, void* parser_id);
void __free_cParser__(cParser* self);


#endif
