#include "../source/common.h"
#include "../source/utils.h"


static int __EXIT_CODE__ = 0;


int main(int argc, char* argv[]) {
	ASSERT(__EXIT_CODE__ == 1, "HELLO MOTO!!!");
	return __EXIT_CODE__;
}
