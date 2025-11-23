#include <string.h>

#include <cParse.h>
#include "../source/parser.h"
#include "../source/scanner.h"
#include "testing_utils.h"
#include "../source/tensor.h"

#include "testing_SIMD_matmul.h"


#define TEST_CASE_COUNT (3)


void test_scanner(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 1, TEST_CASE_COUNT);
}


void test_cParser(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 2, TEST_CASE_COUNT);
}


void test_Tensor_new_and_free(void) {
	size_t example_tensor_shape[4] = {1, 1, 4, 4};
	Tensor* new_test_tensor = NEW_Tensor(4, example_tensor_shape, sizeof(uint64_t));

	bool test_case_condition = FREE_Tensor(new_test_tensor) >= 0;
	DISPLAY_TEST_RESULT(test_case_condition, 3, TEST_CASE_COUNT);
}


int main(int argc, char* argv[]) {
	// @NOTE: 'TEST_CASE_t' ointer array for executing all added
	TEST_CASE_t TEST_CASES[TEST_CASE_COUNT] = {
		test_scanner,
		test_cParser,
		test_Tensor_new_and_free
	};
	
	for (int i = 0; i < TEST_CASE_COUNT; i++) {
		TEST_CASES[i]();
		PRINT("\n");
	}
	return 0;
}
