#ifndef CPARSE_TENSOR_H
#define CPARSE_TENSOR_H

#include <stddef.h>
#include <stdint.h>


#define NEW_Tensor(rank, shape, element_size) (__tensor_new__((rank), (shape), (element_size)))


typedef struct {
	size_t element_size;
	size_t rank;
	size_t count;
	size_t *shape;
	size_t *strides;
	void* data;
} Tensor;


Tensor __tensor_new__(size_t rank, size_t* shape, size_t element_size);


#endif
