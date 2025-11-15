#include <string.h>

#include <cParse.h>
#include "../utils/common.h"
#include "../utils/utils.h"


#define TOTAL_TEST_COUNT (2)
#define TEST_PASSED(test_number) printf("\n\n\t[-"); \
		printf("\033[38;5;10mTEST \033[0m"); \
		printf("\033[38;5;11m%d/%d\033[0m", test_number, TOTAL_TEST_COUNT); \
		printf("\033[38;5;10m PASSED\033[0m"); \
		printf("-]\n")
#define TEST_FAILED(test_number) printf("\n\n\t[-"); \
		printf("\033[38;5;9mTEST \033[0m"); \
		printf("\033[38;5;11m%d/%d\033[0m", test_number, TOTAL_TEST_COUNT); \
		printf("\033[38;5;9m FAILED\033[0m"); \
		printf("-]\n")


void test_1(void) {
	cParser* _new_test_parser = NEW_cParser("HELLO MOTO!!!");

	PRINT("\n");
	if (strcmp((char*)cParser_ID(_new_test_parser), "HELLO MOTO!!!") == 0) {
		TEST_PASSED(1);
	} else {
		TEST_FAILED(1);
	}
	PRINT("\n");
}


void test_2(void) {
	cParser* _new_test_parser = NEW_cParser((&((int){1001})));

	PRINT("\n");
	if ((*(int*)cParser_ID(_new_test_parser)) == 1001) {
		TEST_PASSED(2);
	} else {
		TEST_FAILED(2);
	}
	PRINT("\n");
}


int main(int argc, char* argv[]) {
	test_1();
	PRINT("\n");
	test_2();
	return 0;
}
