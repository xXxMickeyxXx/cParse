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
	_new_tensor.size = __tensor_size__;
	_new_tensor.data = calloc(total, element_size);

	size_t stride = element_size;
	for (ssize_t i = (rank - 1); 0 <= i; i--) {
		_new_tensor.strides[i] = stride;
		stride *= shape[i];
	}
	return _new_tensor;
}


void __init_tensor_array__(TensorArray* tensor_array) {
	ASSERT(FALSE, "**WARNING** - 'init_tensor_array' is NOT IMPLEMENTED");
	return;
}


void __write_tensor_array__(TensorArray* tensor_array, Tensor* tensor) {
	ASSERT(FALSE, "**WARNING** - 'write_tensor_array' is NOT IMPLEMENTED");
	return;
}


void __free_tensor_array__(TensorArray* tensor_array) {
	ASSERT(FALSE, "**WARNING** - 'free_tensor_array' is NOT IMPLEMENTED");
	return;
}


size_t __tensor_size__(Tensor tensor) {
	size_t _total_size = 1;
	for (size_t i = 0; i < tensor.rank; ++i) {
		size_t _shape_size_at_dim = tensor.shape[i];
		PRINT(FORMAT_STRING("TENSOR SHAPE INDEX: %zu ---> %zu", i, _shape_size_at_dim));
		_total_size *= _shape_size_at_dim;
	}
	PRINT(FORMAT_STRING("TENSOR SIZE ---> %zu", _total_size));
	return _total_size;
}


static inline size_t __tensor_element_offset(Tensor tensor, size_t* indices) {
	size_t _offset = 0;
	for (int i = 0; i < tensor.rank; ++i) {
		_offset += indices[i] * tensor.strides[i];
	}
	return _offset;
}


size_t __tensor_element__(Tensor tensor, size_t* indices) {
	size_t _element_offset = __tensor_element_offset(tensor, indices);
	return *((size_t*)((unsigned char*)tensor.data + (_element_offset * tensor.element_size)));
}
