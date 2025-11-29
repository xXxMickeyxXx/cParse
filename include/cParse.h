#include "../source/parser.h"
#include "../source/tensor.h"


// @NOTE: macros for handling the lifetime of the parser, 'cParser' 
#define NEW_PARSER(parser_id) (__new_cParser__((void*)(parser_id)))
#define FREE_PARSER(self) (__free_cParser__((self)))

// @NOTE: conveinance macros for 'cParser' type
#define PARSER_ID(self) ((self)->parser_id)


// @NOTE: conveinance macros for 'Tensor' types
#define NEW_TENSOR(rank, shape, element_size) (__tensor_new__((rank), (shape), (element_size)))
#define TENSOR_SIZE(tensor) ((tensor).size((tensor)))
#define TENSOR_ELEMENT(tensor, indices) (__tensor_element__((tensor)))
#define TENSOR_DIMENSIONS(tensor) (((tensor).rank))
#define TENSOR_STRIDES(tensor) (((tensor).strides))

// @NOTE: conveinance macros for 'TensorArray' types
#define INIT_TENSOR_ARRAY(tensor_array) (__init_tensor_array__((tensor_array)))
#define WRITE_TENSOR_ARRAY(tensor_array, tensor) (__write_tensor_array__((tensor_array), (tensor)))
#define FREE_TENSOR_ARRAY(tensor_array) (__free_tensor_array__((tensor_array)))
