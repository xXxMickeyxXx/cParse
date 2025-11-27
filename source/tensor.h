#ifndef CPARSE_TENSOR_H
#define CPARSE_TENSOR_H

#include <stddef.h>
#include <stdint.h>


typedef struct Tensor Tensor;

struct Tensor {
	size_t element_size;
	size_t rank;
	size_t count;
	size_t (*size)(Tensor tensor);
	size_t *shape;
	size_t *strides;
	void* data;
};


typedef struct {
	size_t size;
	size_t count;
	Tensor* tensors;
} TensorArray;


// @NOTE: Private 'Tensor' functions
Tensor __tensor_new__(size_t rank, size_t* shape, size_t element_size);

// @NOTE: Private 'TensorArray' functions
void __init_tensor_array__(TensorArray* tensor_array);
void __write_tensor_array__(TensorArray* tensor_array, Tensor* tensor);
void __free_tensor_array__(TensorArray* tensor_array);


// @NOTE: Private 'Tensor' API's (which are used in the libs primary header file,
//		  'cParse.h', located within the 'include' dir of the package root)
size_t __tensor_size__(Tensor tensor);
size_t __tensor_element__(Tensor tensor, size_t* indices);


#endif
