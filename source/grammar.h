#ifndef CPARSE_GRAMMAR_H
#define CPARSE_GRAMMAR_H

#include <stdlib.h>


typedef struct {
	void* ID;
	void* data;
} Node;


// typedef struct {
// 	size_t capacity;
// 	size_t count;
// 	Node* nodes;
// } NodeArray;


// typedef struct {
// 	void* ID;
// 	NodeArray nodes;
// } Root;


typedef void (*ArcTransformer)(Node source, Node target);


typedef struct {
	void* source;
	void* target;
	ArcTransformer transformer;
} Arc;


typedef struct {
	size_t node_count;
	size_t arc_count;
	Node* nodes;
	Arc* arcs;
} Graph;


typedef struct {
	void* grammar_id;
	Graph* graph;
} Grammar;


// @NOTE: 'Graph' related logic
Graph* __new_Graph__(size_t node_count, size_t arc_count);
void __free_Graph__(Graph* graph);


// @NOTE: 'Grammar' related logic
Grammar* __new_Grammar__(void* grammar_id, Graph* graph);
void __free_Grammar__(Grammar* grammar);


#endif
