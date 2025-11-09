#include <cParse.h>
#include <stdio.h>
#include <string.h>


#define PRINT(text) printf("%s\n", text); \
	fflush(stdout)


int main(int argc, char* argv[]) {
	// const char* _test_parser_id = "arithmeticLang";
	int _test_parser_id_int = 104;
	int* _test_parser_id;
	_test_parser_id = &_test_parser_id_int;
	*_test_parser_id = 8675309;


	cParser* _new_test_parser = NEW_cParser(_test_parser_id);
	PRINT("\n");
	printf("PARSER ID ---> %d", *cParser_ID(_new_test_parser, int*));
	PRINT("\n");
	return 0;
}
