#include <stdio.h>
#include <string.h>

#include <cParse.h>
#include "../../utils/common.h"
#include "../../utils/utils.h"


int main(int argc, char* argv[]) {
	PRINT("\n");
	PRINT("CREATING 'cParser'...");
	cParser* _new_test_parser = NEW_cParser((&((int){1001})));
	PRINT("FREE-ING 'cParser'...");
	FREE_cParser(_new_test_parser);
	PRINT("\n");
	return 0;
}
