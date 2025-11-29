#include <stdio.h>
#include <string.h>

#include <cParse.h>
#include "../../utils/common.h"
#include "../../utils/utils.h"


int main(int argc, char* argv[]) {
	PRINT("\n");
	PRINT("\n\t[ • WELCOME TO 'cParse' • ]\n\n");
	const char* _parser_ID = "-HELLO_MOTO-";
	PRINT(FORMAT_STRING("CREATING 'cParser' (ID: %d)...", _parser_ID));
	cParser* _new_test_parser = NEW_PARSER(_parser_ID);
	PRINT(FORMAT_STRING("FREE-ING 'cParser' (ID: %d)...", PARSER_ID(_new_test_parser)));
	FREE_PARSER(_new_test_parser);
	PRINT("\n");
	return 0;
}
