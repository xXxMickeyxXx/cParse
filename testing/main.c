#include <string.h>

#include <cParse.h>
#include "testing_utils.h"


#define TEST_CASE_COUNT (3)


void test_scanner(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 1, TEST_CASE_COUNT);
}


void test_parser(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 1, TEST_CASE_COUNT);
}


int main(int argc, char* argv[]) {
	// @NOTE: 'TEST_CASE_t' ointer array for executing all added
	TEST_CASE_t TEST_CASES[TEST_CASE_COUNT] = {
		test_scanner,
		test_parser
	};
	
	for (int i = 0; i < TEST_CASE_COUNT; i++) {
		TEST_CASES[i]();
		PRINT("\n");
	}
	return 0;
}
