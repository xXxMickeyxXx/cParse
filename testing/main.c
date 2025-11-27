#include <stdio.h>
#include <string.h>

#include <cParse.h>
#include "testing_utils.h"

#include "../source/parser.h"
#include "../source/scanner.h"
#include "../source/tensor.h"

#include "../utils/utils.h"


#define TEST_CASE_COUNT (3)


void test_scanner(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 1, TEST_CASE_COUNT);
	PRINT_NEWLINE;
	NOT_IMPLEMENTED("test_scanner", "testing/main.c");
	PRINT_NEWLINE;
	// ASSERT(test_case_condition, "'test_scanner' function has failed it's testing and cannot continue...");
}


void test_cParser(void) {
	bool test_case_condition = FALSE;
	DISPLAY_TEST_RESULT(test_case_condition, 2, TEST_CASE_COUNT);
	PRINT_NEWLINE;
	NOT_IMPLEMENTED("test_cParser", "testing/main.c");
	PRINT_NEWLINE;
	// ASSERT(test_case_condition, "'test_cParser' function has failed it's testing and cannot continue...");
}


// void test_new_Tensor(void) {
// 	size_t example_tensor_shape[5] = {1, 1, 4, 4, 10};
// 	Tensor __TEST_TENSOR__ = NEW_TENSOR(5, example_tensor_shape, sizeof(uint64_t));

// 	printf("TENSOR COUNT ---> %zu\n", __TEST_TENSOR__.count);
// 	printf("TENSOR RANK  ---> %zu\n", __TEST_TENSOR__.rank);
// 	PRINT_NEWLINE;
// 	bool test_case_condition = FALSE;
// 	DISPLAY_TEST_RESULT(test_case_condition, 3, TEST_CASE_COUNT);
// 	PRINT_NEWLINE;
// 	NOT_IMPLEMENTED("test_new_Tensor", "testing/main.c");
// 	PRINT_NEWLINE;
// 	// ASSERT(test_case_condition, "'test_new_Tensor' function has failed it's testing and cannot continue...");
// }


void test_get_tensor_element(void) {
	size_t _3d_example_tensor_shape[] = {2, 2, 2};
	Tensor __3D_TENSOR__ = NEW_TENSOR(3, _3d_example_tensor_shape, sizeof(uint64_t));

	size_t _3d_tensor_size = TENSOR_SIZE(__3D_TENSOR__);
	bool test_case_condition = _3d_tensor_size == 2;
	DISPLAY_TEST_RESULT(test_case_condition, 4, TEST_CASE_COUNT);
	PRINT_NEWLINE;
	NOT_IMPLEMENTED("test_get_tensor_element", "testing/main.c");
	PRINT_NEWLINE;
	// ASSERT(test_case_condition, "'test_new_Tensor' function has failed it's testing and cannot continue...");

	printf("%dD-TENSOR SIZE ---> %zu\n", 3, _3d_tensor_size);
}


int main(int argc, char* argv[]) {
	// @NOTE: 'TEST_CASE_t' ointer array for executing all added
	TEST_CASE_t TEST_CASES[TEST_CASE_COUNT] = {
		test_scanner,
		test_cParser,
		// test_new_Tensor,
		test_get_tensor_element
	};
	
	for (int i = 0; i < TEST_CASE_COUNT; i++) {
		TEST_CASES[i]();
		PRINT("\n");
	}
	return 0;
}
