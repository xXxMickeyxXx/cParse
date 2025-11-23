#ifndef CPARSE_TENSOR_H
#define CPARSE_TENSOR_H

#include <stddef.h>
#include <stdint.h>


#define NEW_Tensor(rank, shape, element_size) (__tensor_new__((rank), (shape), (element_size)))
#define FREE_Tensor(self) (__tensor_free__(self))


typedef struct {
	void* data;
	size_t element_size;

	size_t* shape;
	size_t* strides;

	size_t rank;
	size_t count;

} Tensor;


Tensor* __tensor_new__(size_t rank, size_t* shape, size_t element_size);
int __tensor_free__(Tensor* self);


#endif
