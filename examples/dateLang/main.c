#include <stdio.h>
#include <string.h>

#include <cParse.h>
#include "../../utils/common.h"
#include "../../utils/utils.h"


static int __EXIT_CODE__ = 0;


int main(int argc, char* argv[]) {
	ASSERT(__EXIT_CODE__ == 0, "ERROR!!!");
	PRINT("HELLO FROM 'dateLang'!!!");
	return __EXIT_CODE__;
}
