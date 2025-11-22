#include <string.h>

#include <cParse.h>
#include "testing_utils.h"


#define TEST_CASE_COUNT (3)


void test_1(void) {
	PRINT("\n");
	DISPLAY_TEST_RESULT(1, 1, TEST_CASE_COUNT);
	PRINT("\n");
}


void test_2(void) {
	cParser* _new_test_parser = NEW_cParser("HELLO MOTO!!!");

	// PRINT("\n");
	// if (strcmp((char*)cParser_ID(_new_test_parser), "HELLO MOTO!!!") == 0) {
	// 	TEST_PASSED2(1);
	// } else {
	// 	TEST_FAILED2(1);
	// }
	// PRINT("\n");

	PRINT("\n");
	bool _result = (strcmp((char*)cParser_ID(_new_test_parser), "HELLO MOTO!!!") == 0);
	DISPLAY_TEST_RESULT(_result, 2, TEST_CASE_COUNT);
	PRINT("\n");
}


void test_3(void) {
	cParser* _new_test_parser = NEW_cParser((&((int){1001})));

	// PRINT("\n");
	// if ((*(int*)cParser_ID(_new_test_parser)) == 1001) {
	// 	TEST_PASSED2(2);
	// } else {
	// 	TEST_FAILED2(2);
	// }
	// PRINT("\n");

	PRINT("\n");
	bool _result = ((*(int*)cParser_ID(_new_test_parser)) == 1001);
	DISPLAY_TEST_RESULT(_result, 3, TEST_CASE_COUNT);
	PRINT("\n");
}


int main(int argc, char* argv[]) {
	// @NOTE: 'TEST_CASE_t' ointer array for executing all added
	TEST_CASE_t TEST_CASES[TEST_CASE_COUNT] = {
		test_1,
		test_2,
		test_3
	};
	
	for (int i = 0; i < TEST_CASE_COUNT; i++) {
		TEST_CASES[i]();
		PRINT("\n");
	}
	return 0;
}
