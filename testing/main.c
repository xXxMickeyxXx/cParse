// #include "../include/cParse.h"
#include <cParse.h>


static int __EXIT_CODE__ = 0;


void display_parser_id(const char* parser_id) {
	cParser* _new_parser = NEW_cParser(parser_id);
	PRINT(FORMAT_STRING("TEST PARSER ID ---> '%s'", cParser_ID(_new_parser)));
	__free_cParser__(_new_parser);
}


int main(int argc, char* argv[]) {
	display_parser_id("<<* -TEST_PARSER_ID- •>>");
	return 0;
}
