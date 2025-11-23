#include <stdlib.h>

#include "tensor.h"
// #include "../utils/common.h"
// #include "../utils/utils.h"


Tensor* __tensor_new__(size_t rank, size_t* shape, size_t element_size) {
	NOT_IMPLEMENTED("__tensor_new__", "source/tensor.c");
	return NULL;
}

int __tensor_free__(Tensor* self) {
	if (self != NULL) {
		free(self);
		return 0;
	}
	return -1
}
