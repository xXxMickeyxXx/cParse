#include <stdio.h>
#include <string.h>

#include <cParse.h>
#include "testing_utils.h"

#include "../source/parser.h"
#include "../source/scanner.h"
#include "../source/tensor.h"


#define TEST_CASE_COUNT (3)


void test_scanner(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 1, TEST_CASE_COUNT);
}


void test_cParser(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 2, TEST_CASE_COUNT);
}


void test_new_Tensor(void) {
	size_t example_tensor_shape[5] = {1, 1, 4, 4, 10};
	Tensor new_test_tensor = NEW_Tensor(5, example_tensor_shape, sizeof(uint64_t));

	printf("TENSOR COUNT ---> %zu\n", new_test_tensor.count);

	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 3, TEST_CASE_COUNT);
}


int main(int argc, char* argv[]) {
	// @NOTE: 'TEST_CASE_t' ointer array for executing all added
	TEST_CASE_t TEST_CASES[TEST_CASE_COUNT] = {
		test_scanner,
		test_cParser,
		test_new_Tensor
	};
	
	for (int i = 0; i < TEST_CASE_COUNT; i++) {
		TEST_CASES[i]();
		PRINT("\n");
	}
	return 0;
}
