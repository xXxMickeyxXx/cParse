#include <stdio.h>
#include <string.h>

#include <cParse.h>
#include "../../utils/common.h"
#include "../../utils/utils.h"


#define COLOR_STRING(offset, text) (FORMAT_STRING("\033[38;5;%dm%s\033[0m", offset, text))


int main(int argc, char* argv[]) {
	PRINT("\n");

	const char* _example_input_1_path = "/Users/mickey/Desktop/C_Lang/libs/cparse/examples/abcLang/example_input/abcLang_example_input.txt";
	FILE* _example_input_1_read = fopen(_example_input_1_path, "r");

	int _example_input_1_char;
	if (_example_input_1_read == NULL) {
		PRINT("ERROR READING EXAMPLE INPUT # 1");
		exit(-1);
	}

	char _input_buff_1[100];
	size_t i = 0;
	while ((_example_input_1_char = fgetc(_example_input_1_read)) != EOF) {
		_input_buff_1[i++] = _example_input_1_char;
	}
	_input_buff_1[i] = NULL_CHAR;
	fclose(_example_input_1_read);
	PRINT(FORMAT_STRING("%s\n\n", COLOR_STRING(10, _input_buff_1)));


	// const char* _parser_ID = "-HELLO_MOTO-";
	// cParser* _new_test_parser = NEW_PARSER(_parser_ID);
	// PRINT(FORMAT_STRING("FREE-ING 'cParser' (ID: %s)...", (char*)PARSER_ID(_new_test_parser)));
	// FREE_PARSER(_new_test_parser);
	// PRINT("\n");
	// PRINT("\n");
	// Graph* _parse_graph = NEW_GRAPH(2, 2);
	// Grammar* abcLang_grammar = GRAMMAR("TEST_abcLang_GRAMMAR", _parse_graph);
	// PRINT(FORMAT_STRING("GRAMMAR ID: %s", (char*)abcLang_grammar->grammar_id));
	// FREE_GRAMMAR(abcLang_grammar);
	// FREE_GRAPH(_parse_graph);


	return 0;
}
