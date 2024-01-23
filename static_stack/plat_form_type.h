#ifndef _PLAT_FORM_TYPE_H
#define _PLAT_FORM_TYPE_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

typedef enum return_status{
    R_OK,
    R_NOK
}return_status_t;


#endif /*PLAT_FORM_TYPE_H*/