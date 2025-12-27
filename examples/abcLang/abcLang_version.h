#ifndef CPARSE_abcLang_VERSION_H
#define CPARSE_abcLang_VERSION_H


typedef struct cParseVersion cParseVersion;


typedef (char*)(*stringify)(cParseVersion* self);


typedef struct {
	const unsigned short value;
	const char* as_string

} cParseVersion;


void __init_cParseVersion__(cParseVersion* self);


char* cParseVersion_as_string


#endif
