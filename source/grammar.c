#include <stdlib.h>
#include <stdio.h>

#include "grammar.h"


Graph* __new_Graph__(size_t node_count, size_t arc_count) {
	Graph* _new_graph = (Graph*)malloc(sizeof(Graph));
	if (_new_graph == NULL) {
		fprintf(stderr, "Error allocating memory for 'Graph' structure...exiting runtime...");
		exit(1);
	}
	_new_graph->node_count = node_count;
	_new_graph->arc_count = arc_count;
	_new_graph->nodes = (Node*)malloc(sizeof(Node) * node_count);
	_new_graph->arcs = (Arc*)malloc(sizeof(Arc) * arc_count);
	return _new_graph;
}


void __free_Graph__(Graph* graph) {
	free(graph);
}


Grammar* __new_Grammar__(void* grammar_id, Graph* graph) {
	Grammar* _new_grammar = (Grammar*)malloc(sizeof(Grammar));
	if (_new_grammar == NULL) {
		fprintf(stderr, "Error allocating memory for 'Grammar' structure...exiting runtime...");
		exit(1);
	}
	_new_grammar->grammar_id = grammar_id;
	_new_grammar->graph = graph;
	return _new_grammar;
}


void __free_Grammar__(Grammar* grammar) {
	free(grammar);
}

