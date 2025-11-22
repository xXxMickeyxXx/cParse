#ifndef CPARSE_TESTING_UTILS_H
#define CPARSE_TESTING_UTILS_H


// @NOTE: Helper macros for outputting if a specific test, out of total number
//		  of tests, passed or fail; uses color
#define TEST_PASSED(test_number, total_tests) printf("\n\n\t[-"); \
		printf("\033[38;5;10mTEST \033[0m"); \
		printf("\033[38;5;11m%d/%d\033[0m", test_number, total_tests); \
		printf("\033[38;5;10m PASSED\033[0m"); \
		printf("-]\n")
#define TEST_FAILED(test_number, total_tests) printf("\n\n\t[-"); \
		printf("\033[38;5;9mTEST \033[0m"); \
		printf("\033[38;5;11m%d/%d\033[0m", test_number, total_tests); \
		printf("\033[38;5;9m FAILED\033[0m"); \
		printf("-]\n")
#define DISPLAY_TEST_RESULT(condition, test_number, total_tests) (__display_test_result((condition), (test_number), (total_tests)))


// @NOTE: 'TEST_CASE_t' is a function pointer type for test cases
typedef void (*TEST_CASE_t)(void);


static inline void __display_test_result(bool condition, int test_number, int total_tests) {
	PRINT("\n");
	if (condition) {
		TEST_PASSED(test_number, total_tests);
	} else {
		TEST_FAILED(test_number, total_tests);
	}
	PRINT("\n");
}


#endif
