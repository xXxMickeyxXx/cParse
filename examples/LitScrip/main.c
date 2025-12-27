#include <stdio.h>
#include <string.h>

#include <cParse.h>
#include "../../utils/common.h"
#include "../../utils/utils.h"


int main(int argc, char* argv[]) {
	PRINT("\n");
	PRINT(" SHELL-ARGUMENTS\n");
	PRINT(FORMAT_STRING("\n\t FILE: %s\n\n", argv[0]));

	for (int i = 1; i < argc; i++) {
		if (argc >= 1) {
			PRINT(FORMAT_STRING(" \t\t%s\n", argv[i]));
		}
	}
	PRINT("\n");
	int _parser_ID = 1001;
	PRINT(FORMAT_STRING(" CREATING 'cParser' (ID: %d)...", _parser_ID));
	cParser* _new_test_parser = NEW_PARSER(&_parser_ID);
	PRINT(FORMAT_STRING(" FREE-ING 'cParser' (ID: %d)...", PARSER_ID(_new_test_parser)));
	FREE_PARSER(_new_test_parser);
	PRINT("\n");
	return 0;
}
