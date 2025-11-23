#include <stdlib.h>

#include "tensor.h"
#include "../utils/common.h"
#include "../utils/utils.h"


Tensor __tensor_new__(size_t rank, size_t* shape, size_t element_size) {
	Tensor _new_tensor;
	_new_tensor.rank = rank;
	_new_tensor.element_size = element_size;

	_new_tensor.shape = malloc(rank * sizeof(size_t));
	_new_tensor.strides = malloc(rank * sizeof(size_t));

	size_t total = 1;
	for (size_t i = 0; i < rank; i++) {
		total *= shape[i];
	}

	_new_tensor.count = total;
	_new_tensor.data = calloc(total, element_size);

	size_t stride = element_size;
	for (int i = ((int)rank) - 1; i >= 0; i--) {
		_new_tensor.strides[i] = stride;
		stride *= shape[i];
	}
	return _new_tensor;
}
