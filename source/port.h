#ifndef CPARSE_PORT_H
#define CPARSE_PORT_H


#include <stdint.h>
#include <stddef.h>


#define PORT_TYPE(ID) ((PortType){ .ID = (ID), .size = sizeof(ID), .alignment = _Alignof(ID)})


typedef struct PortType {
	void* ID;
	size_t size;
	size_t alignment;
} PortType;


int port()


#endif
