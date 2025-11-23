#include <string.h>

#include <cParse.h>
#include "../source/parser.h"
#include "../source/scanner.h"
#include "testing_utils.h"

#include "testing_SIMD_matmul.h"


#define TEST_CASE_COUNT (4)


void test_scanner(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 1, TEST_CASE_COUNT);
}


void test_creating_new_parser(void) {
	cParser* new_parser = NEW_cParser((&((long){8675309})));

	bool new_parser_allocated_condition = new_parser != NULL;
	DISPLAY_TEST_RESULT(new_parser_allocated_condition, 2, TEST_CASE_COUNT);
}


void test_freeing_parser(void) {
	cParser* new_parser = NEW_cParser((&((long){18001233345})));
	FREE_cParser(new_parser);
	new_parser = NULL;

	bool new_parser_free_condition = new_parser == NULL;
	DISPLAY_TEST_RESULT(new_parser_free_condition, 3, TEST_CASE_COUNT);
}


void test_parser(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 4, TEST_CASE_COUNT);
}


int main(int argc, char* argv[]) {
	// @NOTE: 'TEST_CASE_t' ointer array for executing all added
	TEST_CASE_t TEST_CASES[TEST_CASE_COUNT] = {
		test_scanner,
		test_creating_new_parser,
		test_freeing_parser,
		test_parser
	};
	
	for (int i = 0; i < TEST_CASE_COUNT; i++) {
		TEST_CASES[i]();
		PRINT("\n");
	}
	return 0;
}
